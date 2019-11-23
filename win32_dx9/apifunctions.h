#include <Windows.h>
#include <TlHelp32.h>

typedef BOOL(WINAPI *fGetCursorInfo)(
	PCURSORINFO pci
	);


fGetCursorInfo hookCursorInfo;

//this will replace the DeleteFileA function in our target process
BOOL HonkGetCursorInfo(
	PCURSORINFO pci
)
{
	printf("CursorInfo is called\n");

	return hookCursorInfo(pci); //if the parameter does not contain this string, call the original API function
}

typedef BOOL(WINAPI *fGetCursorPos)(
	LPPOINT lpPoint
	);


fGetCursorPos HookCursorPos;

//this will replace the DeleteFileA function in our target process
BOOL HonkGetCursorPos(
	LPPOINT lpPoint
)
{
	printf("CursorPos is called\n");

	return HookCursorPos(lpPoint); //if the parameter does not contain this string, call the original API function
}

typedef HCURSOR(WINAPI *fGetCursor)(
	);


fGetCursor HookCursor;

//this will replace the DeleteFileA function in our target process
HCURSOR HonkGetCursor(
)
{
	printf("Cursor is called\n");

	return HookCursor(); //if the parameter does not contain this string, call the original API function
}