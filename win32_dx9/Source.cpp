#include <d3d9.h>
#include "pattern.h"
#include "detours.h"
#include "d3dx9.h"
#include "GameMem.h"
#include "base.h"
#include <tchar.h>
#include "Runner.h"
#include "apihook.h"
#include "apifunctions.h"

using namespace hook;
hook_t Hook;

using hook_fn = void(*)();

uintptr_t d3d9_device_new = 0;
uintptr_t return_address = 0;

ID3DXLine* d3dLine = nullptr;
LPD3DXFONT pFont = nullptr;

HWND gameWindow;
int width = 1030, height = 797;

bool PressedKeys[256] = {};
static bool TryingToUnload = false;
static bool ReadyToUnload = false;

base::sync::recursive_spinlock_t originalFxn_spinlock_;
base::sync::recursive_spinlock_t wnd_proc_spinlock_;
base::sync::recursive_spinlock_t EndScene_spinlock_;


static bool bAutoPilotS = false;
static bool bAutoRunner = false;

// lpClassName = MSCTFIME U
//

//HOOKING
void HookFunction(PVOID *oFunction, PVOID pDetour)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(oFunction, pDetour);
	DetourTransactionCommit();
}
void UnhookFunction(PVOID *oFunction, PVOID pDetour)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(oFunction, pDetour);
	DetourTransactionCommit();
}

void DrawString(int x, int y, DWORD color, LPD3DXFONT g_pFont, const char *fmt, ...)
{
	char buf[1024] = { 0 };
	va_list va_alist;
	RECT FontPos = { x, y, x + 120, y + 16 };
	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	g_pFont->DrawTextA(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}

void DrawLine(float x, float y, float xx, float yy, D3DCOLOR color)
{
	D3DXVECTOR2 dLine[2];

	d3dLine->SetWidth(1.f);

	dLine[0].x = x;
	dLine[0].y = y;

	dLine[1].x = xx;
	dLine[1].y = yy;

	d3dLine->Draw(dLine, 2, color);

}

void DrawBox(float x, float y, float width, float height, D3DCOLOR color)
{
	D3DXVECTOR2 points[5];
	points[0] = D3DXVECTOR2(x, y);
	points[1] = D3DXVECTOR2(x + width, y);
	points[2] = D3DXVECTOR2(x + width, y + height);
	points[3] = D3DXVECTOR2(x, y + height);
	points[4] = D3DXVECTOR2(x, y);
	d3dLine->SetWidth(1);
	d3dLine->Draw(points, 5, color);
}

__declspec(naked) void cfg_hook()
{
	__asm {

		push eax
		mov eax, [esp + 4]
		cmp eax, [return_address] //; endscene return addr
		jne not_endscene
		mov[d3d9_device_new], ebx
		sub[d3d9_device_new], 4
		not_endscene:
		pop eax
			ret
	}
}

hook_fn patch(const uintptr_t address, hook_fn function)
{
	DWORD protection = 0;
	const auto original = hook_fn(*reinterpret_cast<uintptr_t*>(address));
	if (VirtualProtect(LPVOID(address), sizeof(uintptr_t), PAGE_READWRITE, &protection) == FALSE)
		return nullptr;
	*reinterpret_cast<uintptr_t*>(address) = uintptr_t(function);
	VirtualProtect(LPVOID(address), sizeof(uintptr_t), protection, &protection);
	return original;
}

inline void redirect_stdout()
{
	freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
}

uintptr_t get_return_address(const HMODULE d3d_module)
{
	constexpr auto return_addr_pattern = "8B CF FF D6 8B 4D 08 8B 41 3C FF 40 08 83 4D FC FF";

	MODULEINFO moduleinfo = { nullptr };
	if (GetModuleInformation(GetCurrentProcess(), d3d_module, &moduleinfo, sizeof(moduleinfo)) == FALSE)
		return 0;

	return uintptr_t(FindPattern(PBYTE(moduleinfo.lpBaseOfDll), moduleinfo.SizeOfImage, return_addr_pattern));
}

/* EndScene defs */
typedef long(__stdcall *EndScene_t)(IDirect3DDevice9*);
EndScene_t o_EndScene = nullptr;

/* BeginScene defs */
typedef long(__stdcall *BeginScene_t)(IDirect3DDevice9*);
BeginScene_t o_BeginScene = nullptr;

/* Present defs */
typedef long(__stdcall *Present_t)(IDirect3DDevice9*, RECT*, RECT*, HWND, RGNDATA*);
Present_t o_Present = nullptr;

/* Reset defs */
typedef long(__stdcall *Reset_t)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
Reset_t o_Reset = nullptr;

/* WndProc defs*/
LONG_PTR o_WndProc = NULL;

/* LowLevel Mouse Defs*/
HHOOK o_LowMouse = NULL;

static bool bOnce = false;
static int sleeper = 0;

static int ScreenXX = 319;
static int ScreenYY = 293;

static int TargetView = 0;

HRESULT __stdcall EndScene_h(IDirect3DDevice9 *pDevice)
{
	//printf("Reverse after1");
	std::unique_lock<base::sync::recursive_spinlock_t> l{ EndScene_spinlock_ };
	//printf("Reverse before1");
	int x = 0;
	int y = width / 2 - 10 * 20;

	//printf("1\n");

	DWORD hatcur = Equipment::GetHeadCur();
	//printf("2\n");
	DWORD neckcur = Equipment::GetNeckCur();
	//printf("3\n");
	DWORD glasscur = Equipment::GetGlassCur();
	//printf("4\n");
	DWORD wingcur = Equipment::GetWingCur();
	//printf("5\n");
	DWORD uppercur = Equipment::GetUpperCur();
	//printf("6\n");
	DWORD pantcur = Equipment::GetLowerCur();
	//printf("7\n");
	DWORD armcur = Equipment::GetArmCur();
	//printf("8\n");
	DWORD shoecur = Equipment::GetShoeCur();
	//printf("9\n");
	DWORD weaponcur = Equipment::GetWeaponCur();
	//printf("10\n");
	DWORD ringcur = Equipment::GetRingCur();

	//printf("11\n");
	DWORD worldIndex = Overworld::GetCurrentMapIndex();

	DWORD XPosition = Overworld::GetCurrentPosX();
	DWORD YPosition = Overworld::GetCurrentPosY();

	DWORD Speed = Overworld::GetCurrentSpeedHor();
	DWORD conversationstate = Overworld::GetCurrentState();
	BYTE intype = Social::GetCurrentTypingState();

	HDC hdc = 0;
	//hdc = GetDC(gameWindow);
	COLORREF A0 = GetPixel(hdc, ScreenXX, ScreenYY);
	DWORD A0R = GetRValue(A0);
	DWORD A0G = GetGValue(A0);
	DWORD A0B = GetBValue(A0);
	COLORREF B0 = GetPixel(hdc, ScreenXX, ScreenYY);
	DWORD B0R = GetRValue(B0);
	DWORD B0G = GetGValue(B0);
	DWORD B0B = GetBValue(B0);
	COLORREF C0 = GetPixel(hdc, ScreenXX, ScreenYY);
	DWORD C0R = GetRValue(C0);
	DWORD C0G = GetGValue(C0);
	DWORD C0B = GetBValue(C0);
	COLORREF D0 = GetPixel(hdc, ScreenXX, ScreenYY);
	DWORD D0R = GetRValue(D0);
	DWORD D0G = GetGValue(D0);
	DWORD D0B = GetBValue(D0);

	if (bAutoPilotS)
	{
		SendMessage(gameWindow, WM_KEYDOWN, 83, NULL);
	}
	POINTS points;
	points.x = XPosition;
	points.y = YPosition;
	SendMessage(gameWindow, WM_NCMOUSEMOVE, 0, MAKELPARAM(&points, &points));

	if (GetFocus() != gameWindow || TryingToUnload)
	{
		sleeper = 0;
		goto EXIT;
	}

	//delay a little when refocus on the game.
	if (sleeper < 1)
	{
		D3DXCreateFontA(pDevice, 16, 0, FW_HEAVY, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &pFont);
		D3DXCreateLine(pDevice, &d3dLine);
		//printf("font and line\n");
		sleeper++;
		goto EXIT;
	}

	////printf("5\n");

	pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, 0xFFFFFFFF);

	if (PressedKeys[VK_SHIFT])
		if (PressedKeys[VK_F11])
			bAutoPilotS = !bAutoPilotS;

	if (PressedKeys[VK_SHIFT])
		if (PressedKeys[VK_F1])
			bAutoRunner = !bAutoRunner;

	//if (PressedKeys[VK_LEFT])
	//	ScreenXX--;
	//if (PressedKeys[VK_RIGHT])
	//	ScreenXX++;
	//if (PressedKeys[VK_UP])
	//	ScreenYY--;
	//if (PressedKeys[VK_DOWN])
	//	ScreenYY++;
	//if (PressedKeys[79])
	//	TargetView++;
	//if (PressedKeys[76])
	//	TargetView--;

	//printf("drawing\n");

	DrawString(x, y, D3DCOLOR_ARGB(255, 255, 255, 0), pFont, u8"HAT: %i", hatcur);
	y += 20;
	DrawString(x, y, D3DCOLOR_ARGB(255, 255, 255, 0), pFont, u8"NECK: %i", neckcur);
	y += 20;
	DrawString(x, y, D3DCOLOR_ARGB(255, 255, 255, 0), pFont, u8"FACE: %i", glasscur);
	y += 20;
	DrawString(x, y, D3DCOLOR_ARGB(255, 255, 255, 0), pFont, u8"WING: %i", wingcur);
	y += 20;
	DrawString(x, y, D3DCOLOR_ARGB(255, 255, 255, 0), pFont, u8"UPPER: %i", uppercur);
	y += 20;
	DrawString(x, y, D3DCOLOR_ARGB(255, 255, 255, 0), pFont, u8"LOWER: %i", pantcur);
	y += 20;
	DrawString(x, y, D3DCOLOR_ARGB(255, 255, 255, 0), pFont, u8"ARM: %i", armcur);
	y += 20;
	DrawString(x, y, D3DCOLOR_ARGB(255, 255, 255, 0), pFont, u8"SHOE: %i", shoecur);
	y += 20;
	DrawString(x, y, D3DCOLOR_ARGB(255, 255, 255, 0), pFont, u8"WEAPON: %i", weaponcur);
	y += 20;
	DrawString(x, y, D3DCOLOR_ARGB(255, 255, 255, 0), pFont, u8"RING: %i", ringcur);
	y += 20;

	switch (worldIndex)
	{
	case HOLE1:
		DrawString(width / 2, 10, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, u8"HOLE: 1");
		break;
	case HOLE2:
		DrawString(width / 2, 10, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, u8"HOLE: 2");
		break;
	case HOLE3:
		DrawString(width / 2, 10, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, u8"HOLE: 3");
		break;
	case HOLE4:
		DrawString(width / 2, 10, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, u8"HOLE: 4");
		break;
	case HOLE5:
		DrawString(width / 2, 10, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, u8"HOLE: 5");
		break;
	case HOLE6:
		DrawString(width / 2, 10, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, u8"HOLE: 6");
		break;
	default:
		DrawString(width / 2, 10, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, u8"overworld");
		break;
	}

	DrawString(100, 110, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, "BOIHOOK");
	DrawString(100, 170, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, "( %d, %d)", XPosition, YPosition);
	DrawString(100, 130, bAutoPilotS ? D3DCOLOR_ARGB(255, 0, 255, 0) : D3DCOLOR_ARGB(255, 255, 0, 0), pFont, "Shift + F11 - AUTOPILOT S");
	DrawString(100, 150, bAutoRunner ? D3DCOLOR_ARGB(255, 0, 255, 0) : D3DCOLOR_ARGB(255, 255, 0, 0), pFont, "Shift + F1 - AUTO Runner");
	DrawString(100, 190, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, "Conversation State: %d", conversationstate);
	DrawString(100, 210, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, "Current Typing status: %x", intype);
	DrawString(100, 230, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, "A color: %d %d %d", A0R, A0G, A0B);
	DrawString(100, 250, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, "B color: %d %d %d", B0R, B0G, B0B);
	DrawString(100, 270, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, "C color: %d %d %d", C0R, C0G, C0B);
	DrawString(100, 290, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, "D color: %d %d %d", D0R, D0G, D0B);
	DrawString(100, 310, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, "ScreenXY: %d, %d", ScreenXX, ScreenYY);
	DrawString(100, 330, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, "Index: %d", TargetView);
	DrawString(ScreenXX, ScreenYY, D3DCOLOR_ARGB(255, 255, 0, 0), pFont, ".");

EXIT:
	ReadyToUnload = true;

	if (bAutoRunner)
	{
		if (worldIndex == HOLE1 || worldIndex == HOLE2 || worldIndex == HOLE3 || worldIndex == HOLE4 || worldIndex == HOLE5 || worldIndex == HOLE6 || worldIndex == HOLEEND || worldIndex == ENTRYYANNIAODU)
		{
			Runner::clearType(intype);
		}

		if (worldIndex == ENTRYYANNIAODU)
		{
			Runner::RunOutSide(worldIndex, conversationstate, XPosition, YPosition);
		}

		if (worldIndex == HOLE1 || worldIndex == HOLE2 || worldIndex == HOLE3 || worldIndex == HOLE4 || worldIndex == HOLE5 || worldIndex == HOLE6)
			Runner::runnerGeneralPos(XPosition, YPosition, Speed);

		if (worldIndex == HOLE1)
			Runner::runHole1(XPosition, YPosition, Speed);
		else if (worldIndex == HOLE2)
			Runner::runHole2(XPosition, YPosition, Speed);
		else if (worldIndex == HOLE3)
			Runner::runHole3(XPosition, YPosition, Speed);
		else if (worldIndex == HOLE4)
			Runner::runHole4(XPosition, YPosition, Speed);
		else if (worldIndex == HOLE5)
			Runner::runHole5(XPosition, YPosition, Speed);
		else if (worldIndex == HOLE6)
			Runner::runHole6(XPosition, YPosition, Speed);
		else if (worldIndex == HOLEEND)
			Runner::RunHoleExit(worldIndex, conversationstate, XPosition, YPosition, PressedKeys);
	}

	return o_EndScene(pDevice);
}

HRESULT __stdcall Reset_h(IDirect3DDevice9 *pDevice, D3DPRESENT_PARAMETERS *pPresentationParameters)
{
	//printf("Reset_h honk \n");
	return o_Reset(pDevice, pPresentationParameters);
}

HRESULT __stdcall Present_h(IDirect3DDevice9 *pDevice, RECT* pSourceRect, RECT* pDestRect, HWND hDestWindowOverride, RGNDATA* pDirtyRegion)
{

	return o_Present(pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

LRESULT __stdcall WndProc_h(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//printf("Reverse after");
	std::unique_lock<base::sync::recursive_spinlock_t> l{ wnd_proc_spinlock_ };
	//printf("Reverse before");

	switch (uMsg) // record window message
	{
	case WM_LBUTTONDOWN:
		 PressedKeys[VK_LBUTTON] = true;
		break;
	case WM_LBUTTONUP:
		 PressedKeys[VK_LBUTTON] = false;
		break;
	case WM_RBUTTONDOWN:
		 PressedKeys[VK_RBUTTON] = true;
		break;
	case WM_RBUTTONUP:
		 PressedKeys[VK_RBUTTON] = false;
		break;
	case WM_MBUTTONDOWN:
		 PressedKeys[VK_MBUTTON] = true;
		break;
	case WM_MBUTTONUP:
		 PressedKeys[VK_MBUTTON] = false;
		break;
	case WM_XBUTTONDOWN:
	{
		UINT button = GET_XBUTTON_WPARAM(wParam);
		if (button == XBUTTON1)
		{
			 PressedKeys[VK_XBUTTON1] = true;
		}
		else if (button == XBUTTON2)
		{
			 PressedKeys[VK_XBUTTON2] = true;
		}
		break;
	}
	case WM_XBUTTONUP:
	{
		UINT button = GET_XBUTTON_WPARAM(wParam);
		if (button == XBUTTON1)
		{
			 PressedKeys[VK_XBUTTON1] = false;
		}
		else if (button == XBUTTON2)
		{
			 PressedKeys[VK_XBUTTON2] = false;
		}
		break;
	}
	case WM_KEYDOWN:
		 PressedKeys[wParam] = true;
		break;
	case WM_KEYUP:
		 PressedKeys[wParam] = false;
		break;
	default:
		break;
	}

	return CallWindowProcW((WNDPROC)o_WndProc, hWnd, uMsg, wParam, lParam);
}

LRESULT __stdcall LowLevelMouse_h(int nCode, WPARAM wParam, LPARAM lParam)
{
	return CallNextHookEx(o_LowMouse, nCode, wParam, lParam);
}

HRESULT __stdcall BeginScene_h(IDirect3DDevice9* pDevice)
{
	ReadyToUnload = false;

	if (!bOnce)
	{
		D3DDEVICE_CREATION_PARAMETERS pPara;
		pDevice->GetCreationParameters(&pPara);
		gameWindow = pPara.hFocusWindow;
		Runner::gameWindows = gameWindow;

		printf("window\n");

		//hook wndproc and window size
		o_WndProc = SetWindowLongPtr(gameWindow, GWLP_WNDPROC, (LONG_PTR)WndProc_h);

		//hook lowlevel mouse
		o_LowMouse = SetWindowsHookEx(WH_MOUSE, LowLevelMouse_h, NULL, 0);

		//print game name;
		TCHAR className[MAX_PATH];
		GetClassName(gameWindow, className, _countof(className));
		_tprintf(className);
		printf("\n");

		bOnce = true;
	}

	

	return o_BeginScene(pDevice);
}

uintptr_t guard_function;
hook_fn original_fn;

bool find_device(const HMODULE d3d_module)
{
	// get cfg return address
	return_address = get_return_address(d3d_module);

	if (return_address == 0) {
		printf("could not find return address\n");
		return false;
	}

	printf("return address: 0x%08X\n", return_address);

	if (ImageNtHeader(d3d_module) == nullptr)
	{
		printf("d3d9 module is not a valid pe image!\n");
		return false;
	}

	// get load config directory entry
	ULONG directory_size = 0;
	const auto load_config = PIMAGE_LOAD_CONFIG_DIRECTORY(ImageDirectoryEntryToData(d3d_module, TRUE, IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG, &directory_size));

	if (load_config == nullptr)
	{
		printf("could not find IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG\n");
		return false;
	}

	printf("load config: 0x%p\n", load_config);

	guard_function = load_config->GuardCFCheckFunctionPointer;

	printf("guard function: 0x%08X\n", guard_function);

	// replace original function with ours
	original_fn = patch(guard_function, cfg_hook);

	if (original_fn == nullptr)
	{
		printf("could not patch GuardCFCheckFunctionPointer\n");
		return false;
	}

	printf("original function: 0x%p\n", original_fn);

	while (true)
	{
		if (HIBYTE(GetAsyncKeyState(VK_DELETE)))
		{
			break;
		}

		// wait until d3d device is found
		if (d3d9_device_new != 0)
		{
			printf("d3d9 device: 0x%I32X\n", d3d9_device_new);

			DWORD_PTR* pDeviceVT = reinterpret_cast<DWORD_PTR*>(d3d9_device_new);
			pDeviceVT = reinterpret_cast<DWORD_PTR*>(pDeviceVT[0]);

			IDirect3DDevice9* ref = nullptr;

			o_EndScene = reinterpret_cast<EndScene_t>(pDeviceVT[42]);
			printf("EndScene: 0x%I32X\n", pDeviceVT[42]);
			o_BeginScene = reinterpret_cast<BeginScene_t>(pDeviceVT[41]);
			printf("BeginScene: 0x%I32X\n", pDeviceVT[41]);
			o_Reset = reinterpret_cast<Reset_t>(pDeviceVT[16]);
			printf("Reset: 0x%I32X\n", pDeviceVT[16]);
			o_Present = reinterpret_cast<Present_t>(pDeviceVT[17]);
			printf("Present: 0x%I32X\n", pDeviceVT[17]);

			InitializeHook(&Hook, "User32.dll", "GetCursorInfo", HonkGetCursorInfo);
			InitializeHook(&Hook, "User32.dll", "GetCursorPos", HonkGetCursorPos);
			InitializeHook(&Hook, "User32.dll", "GetCursor", HonkGetCursor);
			hookCursorInfo = (fGetCursorInfo)Hook.APIFunction;
			HookCursorPos = (fGetCursorPos)Hook.APIFunction;
			HookCursor = (fGetCursor)Hook.APIFunction;
			InsertHook(&Hook);
			printf("Cursor\n");


			HookFunction(reinterpret_cast<PVOID*>(&o_BeginScene), BeginScene_h);
			HookFunction(reinterpret_cast<PVOID*>(&o_Reset), Reset_h);
			HookFunction(reinterpret_cast<PVOID*>(&o_Present), Present_h);
			HookFunction(reinterpret_cast<PVOID*>(&o_EndScene), EndScene_h);

			printf("Hooking Successful\n");

			Beep(650, 50);
			break;
		}

		using namespace std::chrono_literals;
		std::this_thread::sleep_for(50ms);
	}

	// restor original function
	//patch(guard_function, original_fn);

	return true;
}

DWORD WINAPI initialize(void* mod)
{

	const auto current_module = static_cast<HMODULE>(mod);
	const auto d3d9_module = GetModuleHandle(TEXT("d3d9.dll"));
	// don't allocate a console if there's already one
	const auto allocate_console = GetConsoleWindow() == nullptr;

	if (allocate_console) {
		AllocConsole();
		redirect_stdout();
	}

	if (d3d9_module != nullptr) {
		if (find_device(d3d9_module))
			printf("success\n");
		else
			printf("fail!\n");
	}
	else
	{
		printf("could not find d3d9 module\n");
	}

	while (!PressedKeys[VK_DELETE])
	{
		Sleep(5);
	}
	TryingToUnload = true;	

	//Sleep(50);

	while (!ReadyToUnload)
	{
		Sleep(16);
	}

	printf("unloading...\n");

	patch(guard_function, original_fn);

	printf("Unloading orignal function successful...\n");

	UnhookFunction(reinterpret_cast<PVOID*>(&o_Present), Present_h);
	printf("Present function unloading successful....\n");
	UnhookFunction(reinterpret_cast<PVOID*>(&o_BeginScene), BeginScene_h);
	printf("beginscene function unloading successful....\n");
	UnhookFunction(reinterpret_cast<PVOID*>(&o_EndScene), EndScene_h);
	printf("endscene function unloading successful....\n");
	UnhookFunction(reinterpret_cast<PVOID*>(&o_Reset), Reset_h);
	printf("reset function unloading successful....\n");
	Unhook(&Hook);
	FreeHook(&Hook);
	printf("Mouse Hook unload successful....\n");
	if (o_WndProc)
		SetWindowLongPtr(gameWindow, GWL_WNDPROC, o_WndProc);
	if (o_LowMouse)
		UnhookWindowsHookEx(o_LowMouse);

	if (allocate_console) {
		redirect_stdout();
		FreeConsole();
	}

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(500ms);

	// unload
	FreeLibraryAndExitThread(current_module, 0);
	//return 0;
}

// ReSharper disable once CppInconsistentNaming
BOOL WINAPI DllMain(const HMODULE mod, const ULONG reason, PVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		const auto thread = CreateThread(nullptr, 0, initialize, mod, 0, nullptr);
		LoadLibrary("d3d9.dll");
		CloseHandle(thread);
	}
	return TRUE;
}