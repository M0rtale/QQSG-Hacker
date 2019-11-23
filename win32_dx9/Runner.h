#pragma once
//illegible shit, but as long as machine reads, i am fine.

//SendMessage(gameWindows, WM_KEYDOWN, 37, NULL);
//CreateThread(NULL, NULL, jumpUp, NULL, NULL, NULL);
namespace Runner
{
#define AND &&
#define OR ||
#define and &&
#define or ||
#define If if(
#define Then )
#define ElseIf else if(
#define Else else
#define elseIf else if(
	static HWND gameWindows;
	class dm
	{
	public:
		static void keydown(int key)
		{
			SendMessage(gameWindows, WM_KEYDOWN, key, NULL);
		}
		static void keyup(int key)
		{
			SendMessage(gameWindows, WM_KEYUP, key, NULL);
		}
		static void keypress(int key)
		{
			keydown(key);
			keyup(key);
		}
	};
	class DM
	{
	public:
		static void KEYDOWN(int key)
		{
			SendMessage(gameWindows, WM_KEYDOWN, key, NULL);
		}
		static void KEYUP(int key)
		{
			SendMessage(gameWindows, WM_KEYUP, key, NULL);
		}
		static void KEYPRESS(int key)
		{
			KEYDOWN(key);
			using namespace std::chrono_literals;
			std::this_thread::sleep_for(5ms);
			KEYUP(key);
		}
	};

	static int delayb;
	static int delaya;
	static int key;

	DWORD WINAPI ∞¥º¸(void* mod)
	{
		std::chrono::seconds s(delaya);
		std::chrono::seconds s1(delayb);
		std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds> (s);
		std::chrono::milliseconds ms1 = std::chrono::duration_cast<std::chrono::milliseconds> (s1);

		using namespace std::chrono_literals;
		std::this_thread::sleep_for(ms);

		dm::keypress(key);

		using namespace std::chrono_literals;
		std::this_thread::sleep_for(ms1);
		return 0;
	}

	static bool pendingAction = true;
	DWORD WINAPI …œÃ¯(void* mod)
	{
		if (!pendingAction)
			return 0;
		pendingAction = false;
		dm::keypress(39);
		dm::keypress(37);
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(50ms);
		dm::keypress(32);
		pendingAction = true;
		return 0;
	}
	DWORD WINAPI ◊ÛÃ¯(void* mod)
	{
		if (!pendingAction)
			return 0;
		pendingAction = false;
		dm::keypress(39);
		dm::keydown(37);
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(30ms);
		dm::keypress(32);
		pendingAction = true;
		return 0;
	}
	DWORD WINAPI ”“Ã¯(void* mod)
	{
		if (!pendingAction)
			return 0;
		pendingAction = false;
		dm::keypress(37);
		dm::keydown(39);
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(50ms);
		dm::keypress(32);
		pendingAction = true;
		return 0;
	}
	DWORD WINAPI ≈¿ ˜”“…œ(void* mod)
	{
		dm::keydown(39);
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(8ms);
		dm::keydown(38);
		return 0;
	}
	DWORD WINAPI ≈¿ ˜◊Û…œ(void* mod)
	{
		dm::keydown(37);
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(8ms);
		dm::keydown(38);
		return 0;
	}
	DWORD WINAPI ≈¿ ˜”“œ¬(void* mod)
	{
		dm::keydown(39);
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(9ms);
		dm::keydown(40);
		return 0;
	}
	DWORD WINAPI ≈¿ ˜◊Ûœ¬(void* mod)
	{
		dm::keydown(37);
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(7ms);
		dm::keydown(40);
		return 0;
	}

	//CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜”“…œ, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜”“œ¬, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜◊Ûœ¬, NULL, NULL, NULL);

	bool runHole1(int X, int Y, int speedX) // todo : rewrite
	{
		bool ret = false;
		int x = X;
		int y = Y;
		If Y == 1050 and X > 2050 and X <= 2200 Then
			dm::keydown(37);
			ElseIf Y == 1050 and X <= 2050 and X >= 1930 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf Y == 820 AND X >= 2830 AND X <= 2190 Then
			DM::KEYDOWN(37);
			ElseIf Y == 860 AND X >= 2330 AND X <= 2510 Then
			DM::KEYDOWN(37);
			ElseIf Y == 920 AND X >= 2310 AND X <= 2480 Then
			DM::KEYDOWN(37);
			ElseIf Y == 970 AND X >= 2190 AND X <= 2330 Then
			DM::KEYDOWN(37);
			ElseIf y == 900 and x >= 2020 and x <= 2190 Then
			dm::keydown(37);
			ElseIf y == 980 and x >= 1640 and x <= 2050 Then
			dm::keydown(37);
			If x <= 1705 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf y == 910 and x >= 1510 and x <= 1650 Then
			  CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf y == 1340 and x > 230 and x <= 340 Then
			dm::keydown(37);
			ElseIf y == 1340 and x <= 230 and x >= 160 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1280 and x < 130 and x >= 60 Then
			dm::keydown(39);
			ElseIf y == 1280 and x >= 130 and x <= 230 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1220 and x <= 300 and x >= 130 Then
			dm::keydown(39);
			If x >= 235 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 1180 and x >= 300 and x <= 440 Then
			dm::keydown(39);
			If x >= 385 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 1120 and x >= 440 and x <= 540 Then
			dm::keydown(39);
			ElseIf y == 1120 and x >= 440 and x <= 690 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1040 and x >= 540 and x <= 700 Then
			{
			dm::keydown(37);
			If x <= 605 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			}
			ElseIf y == 980 and x <= 540 and x > 450 Then
			dm::keydown(37);
			ElseIf  y == 980 and x >= 370 and x <= 430 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 900 and x >= 260 and x < 410 Then
			dm::keydown(39);
			ElseIf y == 900 and x >= 410 and x <= 430 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 810 and x >= 90 and x <= 270 Then
			dm::keydown(39);
			ElseIf y == 830 and x >= 410 and x <= 580 Then
			{
			dm::keydown(39);
			If speedX <= 200 Then
			If x >= 568 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			Else
			If x >= 510 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			}
			ElseIf Y == 860 AND  X >= 850 AND X <= 1610 Then
			dm::keydown(37);
			ElseIf y == 860 and x >= 640 and x <= 690 Then
			dm::keydown(39);
			ElseIf y == 860 and x >= 690 and x <= 850 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 780 and x >= 690 and x <= 810 Then
			dm::keydown(39);
			ElseIf y == 780 and x >= 810 and x <= 850 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 710 and x >= 900 and x <= 960 Then
			dm::keydown(37);
			ElseIf y == 710 and x >= 810 and x <= 900 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 640 and x >= 790 and x <= 900 Then
			dm::keydown(37);
			ElseIf y == 640 and x >= 750 and x <= 790 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 560 and x >= 620 and x <= 800 Then
			{
			dm::keydown(39);
			If speedX <= 200 Then
			If x >= 763 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf speedX > 200 Then
			If x >= 725 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			}
			ElseIf y == 470 and x >= 180 and x <= 350 Then
			dm::keydown(39);
			ElseIf y == 510 and x >= 330 and x <= 590 Then
			dm::keydown(39);
			ElseIf y == 510 and x >= 590 and x <= 650 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 440 and x >= 590 and x <= 780 Then
			{
			dm::keydown(39);
			If speedX <= 200 Then
			If x >= 740 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf speedX > 200 Then
			If x >= 700 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			}
			ElseIf Y == 360 AND X >= 790 AND X <= 820 Then
			dm::keydown(39);
			ElseIf y == 490 and x >= 840 and x <= 1010 Then
			{
			dm::keydown(39);
			If x >= 955 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			}
			ElseIf y == 430 and x >= 1020 and x <= 1380 Then
			dm::keydown(39);
			ElseIf y == 520 and x >= 1390 and x <= 1600 Then
			  CreateThread(NULL, NULL, ≈¿ ˜”“…œ, NULL, NULL, NULL);
			ElseIf y == 260 and x >= 1340 and x <= 1670 Then
			{
			dm::keydown(37);
			If speedX <= 200 Then
			If x <= 1385 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf speedX <= 250 Then
			If x <= 1400 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf speedX > 250 Then
			If x <= 1470 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			}
			ElseIf y == 250 and x >= 1150 and x <= 1300 Then
			{
			dm::keydown(37);
			If speedX <= 200 Then
			If x <= 1195 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf speedX > 200 Then
			If x <= 1245 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			}
			ElseIf y == 220 and x >= 890 and x <= 1120 Then
			{
			dm::keydown(37);
			If speedX <= 200 Then
			If x <= 935 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf speedX > 200 Then
			If x <= 990 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			}
			ElseIf y == 210 and x >= 330 and x <= 860 Then
			dm::keydown(37);
			ElseIf y == 210 and x >= 140 and x <= 270 Then
			dm::keydown(39);
			ElseIf y == 210 and x >= 270 and x <= 330 Then
			{
			dm::keypress(38);
			ret = true;
			}
			return ret;
	}


	bool runHole2(int X, int Y, int speedX)
	{
		int x = X;
		int y = Y;

		If y == 1060 and x >= 2520 and x < 2600 Then
			CreateThread(NULL, NULL, ≈¿ ˜”“…œ, NULL, NULL, NULL);
			ElseIf y == 1060 and x <= 2690 and x > 2600 Then
			CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
			ElseIf y == 1060 and x == 2600 Then
			dm::keydown(38);
			ElseIf y == 1110 and x >= 2740 and x <= 2880 Then
			{
			dm::keydown(37);
			If speedX <= 200 Then
			If x <= 2750 Then CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf speedX > 200 Then
			If x <= 2760 Then CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			}
			ElseIf y == 1110 and x >= 2700 and x < 2740 Then
			dm::keydown(39);
			ElseIf y == 1190 and x > 2880 and x <= 3030 Then
			dm::keydown(37);
			ElseIf y == 1190 and x > 2660 and x < 2700  Then
			dm::keydown(39);
			ElseIf y == 1190 and x > 2700 and x < 2880 Then
			CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1270 and x < 2660 and x <= 2700 Then
			dm::keydown(39);
			ElseIf y == 1270 and x >= 26660 and x <= 2700 Then
			CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			//–ﬁ∏¥ÕÍ≥… bug1

			//–ﬁ∏ƒƒ⁄»›£∫≤Œøº°∞––Ω≈2::txt°±£¨–ﬁ∏¥¥”y=820µÙœ¬»•µƒbug
			//–ﬁ∏ƒ ±º‰£∫2017::4::29/15£∫16
			//–ﬁ∏¥±Íº«£∫bug2-¥À¥¶2°¢5∫≈∂¥º”»Î£¨∑¿÷π≥ˆ¥Ì
			//–ﬁ∏¥ø™ º
			ElseIf y == 950 and x >= 2830 and x <= 3130 Then
			dm::keydown(37);
			//–ﬁ∏¥ÕÍ≥…  
			ElseIf y == 980 and x < 1995 and x >= 1640 Then
			dm::keydown(39);
			ElseIf y == 980 and x >= 1995 and x <= 2050 Then
			CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 900 and x < 2150 and x >= 2020 Then
			dm::keydown(39);
			ElseIf y == 900 and x >= 2150 and x <= 2190 Then
			CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 1050 and x < 2160 and x >= 1930  Then
			dm::keydown(39);
			ElseIf y == 1050 and x >= 2160 and x <= 2200 Then
			CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 970 and x < 2280 and x >= 2190 Then
			dm::keydown(39);
			ElseIf y == 970 and x >= 2280 and x <= 2330  Then
			CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 920 and x < 2330 and x >= 2310 Then
			dm::keydown(39);
			ElseIf y == 920 and x >= 2330 and x <= 2480  Then
			CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 860 and x >= 2330 and x <= 2510  Then
			CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 820 and x < 2280 and x >= 2190  Then
			CreateThread(NULL, NULL, ≈¿ ˜”“…œ, NULL, NULL, NULL);
			ElseIf y == 820 and x >= 2280 and x <= 2830   Then
			{
			dm::keydown(37);
			If y == 820 and x >= 2280 and x <= 2400 Then
			dm::keydown(38);
			}
			ElseIf y == 570 and x < 2535 and x >= 2190 Then
			dm::keydown(39);
			ElseIf y == 570 and x >= 2535 and x <= 2620 Then
			{
			If speedX <= 200 Then
			{
				If x >= 2540 Then CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			}
			Else
				If x >= 2515 Then CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			}
			ElseIf y == 500 and x < 2790 and x >= 2570 Then
			{
				If speedX <= 200 Then If x >= 2750 Then CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf speedX > 200 Then If x >= 2700 Then CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			dm::keydown(39);
			}
			ElseIf y == 480 and x < 3080 and x >= 2830 Then
			CreateThread(NULL, NULL, ≈¿ ˜”“…œ, NULL, NULL, NULL);
			ElseIf y == 480 and x >= 3080 and x <= 3160 Then
			CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
			ElseIf y == 230 and x >= 3000 and x <= 3150  Then
			{
			dm::keydown(37);
			If speedX <= 200 Then
			If x <= 3040 Then CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf speedX > 200 Then
			If x <= 3070 Then CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			}
			ElseIf y == 210 and x >= 2610 and x <= 2960 Then
			{
			dm::keydown(37);
			If speedX <= 200 Then
			If x <= 2660 Then CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf speedX > 200 Then
			If x <= 2715 Then CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			}
			ElseIf (y == 180 or y == 390 or y == 430) and x >= 1940 and x <= 2620 Then
			dm::keydown(37);
			ElseIf y == 480 and x >= 1930 Then
			CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
			ElseIf y == 480 and x <= 1930 Then
			CreateThread(NULL, NULL, ≈¿ ˜”“…œ, NULL, NULL, NULL);
			ElseIf  y == 210 and x > 1945 and x <= 1990 Then
			dm::keydown(37);
			ElseIf y == 210 and x >= 1850 and x <= 1900 Then
			dm::keydown(39);
			ElseIf y == 210 and x <= 1945 and x >= 1900 Then
			{
			dm::keypress(38);
			}
			return false;
	}

	bool runHole3(int x, int y, int speedX)
	{
		If y == 1060 and x >= 2520 and x < 2600 Then
			 CreateThread(NULL, NULL, ≈¿ ˜”“…œ, NULL, NULL, NULL);
			ElseIf y == 1060 and x <= 2690 and x > 2600 Then
			 CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
			ElseIf y == 1060 and x == 2600 Then
			dm::keydown(38);
			ElseIf y == 1110 and x >= 2740 and x <= 2880 Then
			{
			dm::keydown(37);
			If speedX <= 200 Then
			If x <= 2750 Then  CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf speedX > 200 Then
			If x <= 2760 Then  CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			}
			ElseIf y == 1110 and x >= 2700 and x < 2740 Then
			dm::keydown(39);
			ElseIf y == 1190 and x > 2880 and x <= 3030 Then
			dm::keydown(37);
			ElseIf y == 1190 and x > 2660 and x < 2700  Then
			dm::keydown(39);
			ElseIf y == 1190 and x > 2700 and x < 2880 Then
			 CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1270 and x < 2660 and x >= 2550 Then
			dm::keydown(39);
			ElseIf y == 1270 and x >= 2660 and x <= 2700 Then
			 CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			//–ﬁ∏¥ÕÍ≥… bug1
			ElseIf y == 980 and x < 1995 and x >= 1640 Then
			dm::keydown(39);
			ElseIf y == 980 and x >= 1995 and x <= 2050 Then
			 CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 900 and x < 2150 and x >= 2020 Then
			dm::keydown(39);
			ElseIf y == 900 and x >= 2150 and x <= 2190 Then
			 CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 1050 and x < 2160 and x >= 1930 Then
			dm::keydown(39);
			ElseIf y == 1050 and x >= 2160 and x <= 2200 Then
			 CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 970 and x < 2280 and x >= 2190 Then
			dm::keydown(39);
			ElseIf y == 970 and x >= 2280 and x <= 2330  Then
			 CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 920 and x < 2330 and x >= 2310 Then
			dm::keydown(39);
			ElseIf y == 920 and x >= 2330 and x <= 2480  Then
			 CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 860 and x >= 2330 and x <= 2510  Then
			 CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 820 and x >= 2190 and x <= 2830  Then
			dm::keydown(39);
			ElseIf y == 950 and x <= 3090 and x >= 2830   Then
			 CreateThread(NULL, NULL, ≈¿ ˜”“…œ, NULL, NULL, NULL);
			ElseIf y == 950 and x > 3090 and x <= 3150 Then
			 CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
			ElseIf  y == 700 and x <= 3410 and x >= 3000  Then
			dm::keydown(39);
			ElseIf y == 700 and x > 3410 and x <= 3540 Then
			 CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
			ElseIf y == 450 and x <= 3370 and x >= 3340  Then
			dm::keydown(39);
			ElseIf y == 450 and x > 3370 and x <= 3470 Then
			 CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
			ElseIf x == 3370 and y <= 265 Then
			{
			dm::keyup(38);
			 CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			}
			ElseIf  y == 180 and x <= 3750 and x >= 3290  Then
			{
			dm::keydown(39);
			If y == 180 and x >= 3650 and x <= 3750  Then
			 CreateThread(NULL, NULL, ≈¿ ˜”“œ¬, NULL, NULL, NULL);
			}
			ElseIf y == 180 and x > 3750 and x <= 3850 Then
			 CreateThread(NULL, NULL, ≈¿ ˜◊Ûœ¬, NULL, NULL, NULL);
			ElseIf y == 450 and x <= 3790 and x >= 3720  Then
			 CreateThread(NULL, NULL, ≈¿ ˜”“œ¬, NULL, NULL, NULL);
			ElseIf y == 450 and x > 3790 and x <= 3840 Then
			 CreateThread(NULL, NULL, ≈¿ ˜◊Ûœ¬, NULL, NULL, NULL);
			ElseIf  y == 760 and x < 3800 and x >= 3740 Then
			dm::keydown(39);
			ElseIf y == 760 and x > 3830 and x <= 3880 Then
			dm::keydown(37);
			ElseIf y == 760 and x >= 3800 and x <= 3830 Then
			dm::keypress(38);
			//–ﬁ∏ƒƒ⁄»›£∫≤Œøº°∞––Ω≈2::txt°±£¨–ﬁ∏¥¥”∆ΩÃ®µÙœ¬»•µƒbug
			//–ﬁ∏ƒ ±º‰£∫2017::4::29/14:58
			//–ﬁ∏¥±Íº«£∫bug3-µÙœ¬»•∫Û¥”Õ∑ø™ º£¨∑¿÷π≥ˆ¥Ì◊¯±Í£®35,9£©ø™ º
			//–ﬁ∏¥ø™ º
			ElseIf y == 910 and x >= 3280 and x <= 3580 Then
			dm::keydown(39);
			ElseIf y == 990 and x >= 3550 and x <= 3730 Then
			dm::keydown(37);
			ElseIf y == 1090 and x >= 3680 and x <= 3880 Then
			dm::keydown(37);
			ElseIf y == 1140 and x >= 3170 and x <= 3470 Then
			dm::keydown(39);
			ElseIf y == 1310 and x >= 3810 and x <= 3980 Then
			dm::keydown(37);
			ElseIf y == 1690 and x >= 3650 and x <= 3800 Then
			dm::keydown(37);
			ElseIf y == 1760 and x >= 3050 and x <= 3700 Then
			dm::keydown(37);
			ElseIf y == 1830 and x >= 2950 and x <= 3100 Then
			dm::keydown(37);
			return false;
	}

	//CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜”“…œ, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜”“œ¬, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜◊Ûœ¬, NULL, NULL, NULL);

	bool runHole4(int x, int y, int speedX)
	{
		If  y == 1050 and x < 2060 and x >= 1930  Then
			  CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf y == 1050 and x >= 2060 and x <= 2200 Then
			dm::keydown(37);
			ElseIf y == 980 and x < 1680 and x >= 1640 Then
			  CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf y == 980 and x >= 1680 and x <= 2050 Then
			dm::keydown(37);
			ElseIf y == 910 and x < 1620 and x >= 1510 Then
			  CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf y == 910 and x >= 1620 and x <= 1650 Then
			dm::keydown(37);
			ElseIf y == 860 and x >= 1150 and x <= 1610 Then
			  dm::keydown(37);
			ElseIf y == 860 and x < 1150 and x >= 640 Then
			  CreateThread(NULL, NULL, ≈¿ ˜”“œ¬, NULL, NULL, NULL);
			ElseIf y == 1150 and x >= 920 and x <= 1250 Then
			dm::keydown(37);
			ElseIf y == 1240 and x >= 740 and x <= 940 Then
			dm::keydown(37);
			ElseIf y == 1310 and x >= 630 and x < 675 Then
			dm::keydown(39);
			ElseIf y == 1310 and x > 740 and x <= 800 Then
			dm::keydown(37);
			ElseIf y == 1310 and x <= 740 and x >= 675 Then
			dm::keypress(38);
			//–ﬁ∏ƒƒ⁄»›£∫≤Œøº°∞––Ω≈2::txt°±£¨‘ˆº”“ª–©y=820µƒ≈–∂œ
			//–ﬁ∏ƒ ±º‰£∫2017::4::29/16:44
			//–ﬁ∏¥±Íº«£∫bug4
			//–ﬁ∏¥ø™ º
			ElseIf y == 820 and x >= 2830 and x <= 2190 Then
			dm::keydown(37);
			ElseIf y == 860 and x >= 2330 and x <= 2510 Then
			dm::keydown(37);
			ElseIf y == 920 and x >= 2310 and x <= 2480 Then
			dm::keydown(37);
			ElseIf y == 970 and x >= 2190 and x <= 2330 Then
			dm::keydown(37);
			ElseIf y == 900 and x >= 2020 and x <= 2190 Then
			dm::keydown(37);
			ElseIf y == 1590 and x >= 360 and x <= 640 Then
			dm::keydown(39);
			return false;
	}

	//CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜”“…œ, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜”“œ¬, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜◊Ûœ¬, NULL, NULL, NULL);

	bool runHole5(int x, int y, int speedX)
	{
		If y == 980 and x < 1995 and x >= 1640 Then
			dm::keydown(39);
			ElseIf y == 980 and x >= 1995 and x <= 2050 Then
			  CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 900 and x < 2150 and x >= 2020 Then
			dm::keydown(39);
			ElseIf y == 900 and x >= 2150 and x <= 2190 Then
			  CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 1050 and x < 2160 and x >= 1930  Then
			dm::keydown(39);
			ElseIf y == 1050 and x >= 2160 and x <= 2200 Then
			  CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 970 and x < 2280 and x >= 2190 Then
			dm::keydown(39);
			ElseIf y == 970 and x >= 2280 and x <= 2330  Then
			  CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 920 and x < 2330 and x >= 2310 Then
			dm::keydown(39);
			ElseIf y == 920 and x >= 2330 and x <= 2480  Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 860 and x >= 2330 and x <= 2510  Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 820 and x < 2600 and x >= 2190  Then
			dm::keydown(39);
			ElseIf y == 820 and x >= 2600 and x <= 2830   Then
			  CreateThread(NULL, NULL, ≈¿ ˜◊Ûœ¬, NULL, NULL, NULL);
			ElseIf y == 1060 and x >= 2520 and x <= 2690 Then
			dm::keydown(37);
			ElseIf y == 1120 and x >= 2330 and x <= 2510 Then
			dm::keydown(37);
			ElseIf y == 1310 and x >= 2070 and x <= 2360 Then
			{
				If speedX <= 200 Then If x <= 2105 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf speedX > 200 Then If x <= 2170 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			dm::keydown(37);
			}
			ElseIf y == 1310 and x >= 1980 and x <= 2030 Then
			dm::keydown(37);
			ElseIf y == 1400 and x >= 1690 and x <= 1960 Then
			dm::keydown(37);
			ElseIf y == 1480 and x >= 1470 and x <= 1730 Then
			dm::keydown(37);
			ElseIf y == 1560 and x >= 1390 and x <= 1550 Then
			dm::keydown(37);
			ElseIf y == 1640 and x >= 1270 and x <= 1440 Then
			dm::keydown(39);
			ElseIf y == 1720 and x >= 1390 and x <= 1540 Then
			dm::keydown(39);
			ElseIf y == 1800 and x >= 1470 and x <= 1610 Then
			dm::keydown(39);
			ElseIf (y == 1930 or y == 1950) and x >= 1480 and x <= 1700  Then
			{
			dm::keydown(37);
			dm::keypress(38);
			}
			ElseIf y == 1950 and x < 1480 and x >= 1450 Then
			{
			dm::keydown(39);
			dm::keypress(38);
			}
			//–ﬁ∏ƒƒ⁄»›£∫≤Œøº°∞––Ω≈2::txt°±£¨–ﬁ∏¥¥”y=1310µÙœ¬¿¥
			//–ﬁ∏ƒ ±º‰£∫2017::4::29/17:00
			//–ﬁ∏¥±Íº«£∫bug5
			//–ﬁ∏¥ø™ º
			ElseIf y == 1930 and x >= 1840 and x <= 2120 Then
			{
			dm::keydown(39);
			If speedX <= 200 Then
			If x >= 2080 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf speedX > 200 Then
			If x >= 2060 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			}
			ElseIf y == 1990 and x > 2110 and x <= 2200 Then
			dm::keydown(37);
			ElseIf y == 1990 and x >= 2180 and x <= 2110 Then
			  CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf y == 1880 and x < 2300 and x >= 2090 Then
			dm::keydown(39);
			ElseIf y == 1880 and x > 2330 and x <= 2690 Then
			dm::keydown(37);
			ElseIf y == 1880 and x >= 2300 and x <= 2330 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1800 and x >= 2200 and x < 2300 Then
			dm::keydown(39);
			ElseIf y == 1800 and x > 2330 and x <= 2390 Then
			dm::keydown(37);
			ElseIf y == 1800 and x >= 2300 and x <= 2330 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1730 and x >= 2280 and x < 2320 Then
			dm::keydown(39);
			ElseIf y == 1730 and x > 2380 and x <= 2470 Then
			dm::keydown(37);
			ElseIf y == 1730 and x >= 2320 and x <= 2380 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1670 and x >= 2220 and x <= 2400 Then
			{
			dm::keydown(37);
			If speedX <= 200 Then
			If x <= 2240 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			Else
			If x <= 2280 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			}
			ElseIf y == 1620 and x <= 2200 and x >= 2100 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1560 and x >= 2020 and x <= 2210 Then
			{
			dm::keydown(39);
			If speedX <= 200 Then
			If x >= 2170 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			Else
			If x >= 2150 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			}
			ElseIf y == 1490 and x >= 2200 and x <= 2390 Then
			{
			dm::keydown(39);
			If speedX <= 200 Then
			If x >= 2350 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			Else
			If x >= 2330 Then   CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			}
			ElseIf(y == 1500 or y == 1570 or y == 1610 or y == 1660) and x >= 2390 and x <= 2710 Then
			dm::keydown(39);
			ElseIf y == 1660 and x > 2710 and x <= 2790 Then
			  CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
			ElseIf y == 1420 and x >= 2630 and x < 2700 Then
			dm::keydown(39);
			ElseIf y == 1420 and x >= 2750 and x <= 2820 Then
			dm::keydown(37);
			ElseIf y == 1420 and x >= 2690 and x <= 2750 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1340 and x >= 2630 and x < 2700 Then
			dm::keydown(39);
			ElseIf y == 1340 and x >= 2720 and x <= 2820 Then
			dm::keydown(37);
			ElseIf y == 1340 and x >= 2690 and x <= 2720 Then
			  CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf y == 1270 and x >= 2540 and x <= 2640 Then
			dm::keydown(39);
			ElseIf y == 1270 and x >= 2680 and x <= 2700 Then
			dm::keydown(37);
			ElseIf y == 1270 and x >= 2640 and x <= 2680 Then
			  CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 1190 and x >= 2660 and x <= 2770 Then
			dm::keydown(39);
			ElseIf y == 1190 and x >= 2840 and x <= 3060 Then
			dm::keydown(37);
			ElseIf y == 1190 and x >= 2770 and x <= 2840 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1110 and x >= 2740 and x <= 2880 Then
			{
			dm::keydown(37);
			If speedX <= 200 Then
			If x <= 2750 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			Else
			If x <= 2760 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			}
			ElseIf y == 1110 and x >= 2700 and x < 2740 Then
			dm::keydown(39);
			return false;
	}

	//CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜”“…œ, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜”“œ¬, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜◊Ûœ¬, NULL, NULL, NULL);
	bool runHole6(int x, int y, int speedX)
	{
		If y == 980 and x < 1995 and x >= 1640 Then
			dm::keydown(39);
			elseIf y == 980 and x >= 1995 and x <= 2050 Then
			  CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 900 and x < 2150 and x >= 2020 Then
			dm::keydown(39);
			ElseIf y == 900 and x >= 2150 and x <= 2190 Then
			  CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			elseIf y == 1050 and x < 2160 and x >= 1930  Then
			dm::keydown(39);
			ElseIf y == 1050 and x >= 2160 and x <= 2200 Then
			  CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 970 and x < 2280 and x >= 2190 Then
			dm::keydown(39);
			ElseIf y == 970 and x >= 2280 and x <= 2330 Then
			  CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 920 and x < 2330 and x >= 2310 Then
			dm::keydown(39);
			ElseIf y == 920 and x >= 2330 and x <= 2480  Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 860 and x >= 2330 and x <= 2510  Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 820 and x >= 2190 and x <= 2830 Then
			dm::keydown(39);
			ElseIf y == 950 and x >= 2830 and x <= 3090 Then
			dm::keydown(39);
			ElseIf y == 950 and x > 3090 and x <= 3140 Then
			  CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
			ElseIf y == 700 and x <= 3290 and x >= 3000 Then
			dm::keydown(39);
			ElseIf y == 700 and x <= 3550 and x > 3290 Then
			{
			dm::keydown(40);
			dm::keydown(39);
			}
			ElseIf(y == 990 or y == 1090) and x >= 3490 and x < 3680  Then
			dm::keydown(39);
			ElseIf y == 1090 and x >= 3680 and x <= 3880  Then//∑¿÷πœ¬≤ª»•£¨from°∞––Ω≈2::txt°±
			  dm::keydown(39);
			ElseIf(y == 3970 or y == 3980 or y == 0) and x >= 3940 and x <= 3980  Then//1310 3970ø®◊°
			  CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			ElseIf y == 1310 and x >= 3940 and x <= 3980 Then
			  dm::keydown(37);
			ElseIf y == 1310 and x < 3940 and x >= 3840 Then
			  CreateThread(NULL, NULL, ≈¿ ˜”“œ¬, NULL, NULL, NULL);
			ElseIf y == 1580 and x > 3890 Then
			  CreateThread(NULL, NULL, ≈¿ ˜◊Ûœ¬, NULL, NULL, NULL);
			ElseIf y == 1580 and x >= 3840 and x <= 3890  Then
			  CreateThread(NULL, NULL, ≈¿ ˜”“œ¬, NULL, NULL, NULL);
			ElseIf y == 1860 and x >= 3850 and x <= 3900  Then
			  CreateThread(NULL, NULL, ≈¿ ˜”“œ¬, NULL, NULL, NULL);
			ElseIf y == 1860 and x >= 3900 and x <= 1860 Then
			  CreateThread(NULL, NULL, ≈¿ ˜◊Ûœ¬, NULL, NULL, NULL);
			ElseIf  y == 2180 and x > 3600 Then
			dm::keydown(37);
			ElseIf y == 2180 and x >= 3390 and x <= 3520 Then
			dm::keydown(39);
			ElseIf y == 2180 and x <= 3600 and x > 3520 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 2100 and x < 3590 and x > 3500 Then
			dm::keydown(39);
			ElseIf y == 2100 and x >= 3600 and x <= 3650 Then
			dm::keydown(37);
			ElseIf y == 2100 and x >= 3590 and x <= 3600 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 2030 and x > 3610 and x <= 3730 Then
			dm::keydown(37);
			ElseIf y == 2030 and x >= 3560 and x < 3580 Then
			dm::keydown(39);
			ElseIf y == 2030 and x <= 3610 and x >= 3580 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf  y == 1960 and x > 3620 and x <= 3690 Then
			dm::keydown(37);
			ElseIf y == 1960 and x < 3575 and x >= 3530  Then
			dm::keydown(39);
			ElseIf y == 1960 and x >= 3575 and x <= 3620 Then
			dm::keypress(38);
			//–ﬁ∏¥bug
			ElseIf(y == 1690 or y == 1760) and x > 3130 and x < 3800  Then
			dm::keydown(37);
			ElseIf y == 1760 and x <= 3120 and x > 3060 Then
			dm::keydown(39);
			ElseIf y == 1760 and x >= 3120 and x <= 3130 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1680 and x < 3100 and x >= 2930 Then
			dm::keydown(39);
			ElseIf y == 1680 and x > 3140 and x <= 3180 Then
			dm::keydown(37);
			ElseIf y == 1680 and x >= 3100 and x <= 3140 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1600 and x >= 3050 and x <= 3190 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1530 and x >= 3000 and x <= 3130 Then
			dm::keydown(39);
			ElseIf y == 1530 and x > 3130 and x <= 3180 Then
			  CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 1450 and x >= 3150 and x < 3220 Then
			dm::keydown(39);
			ElseIf y == 1450 and x >= 3220 and x <= 3330 Then
			  CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			ElseIf y == 1380 and x >= 3220 and x < 3330 Then
			dm::keydown(39);
			ElseIf y == 1380 and x >= 3330 and x <= 3420 Then
			  CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
			ElseIf y == 1140 and x < 3380 and x >= 3210 Then
			dm::keydown(39);
			ElseIf y == 1140 and x <= 3470 and x >= 3380 Then
			  CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
			ElseIf y == 910 and x >= 3300 and x <= 3620 Then
			dm::keydown(39);
			return false;
	}

	//CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜”“…œ, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜◊Û…œ, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜”“œ¬, NULL, NULL, NULL);
	//CreateThread(NULL, NULL, ≈¿ ˜◊Ûœ¬, NULL, NULL, NULL);

	bool runnerGeneralPos(int x, int y, int speedX)
	{
		If x > 980 and y == 2180 Then
			dm::keydown(37);
			ElseIf y == 2180 and x < 980 and x > 840 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 2180 and x <= 840 and x >= 630  Then
			dm::keydown(39);
			ElseIf y == 2100 and x > 980 and x <= 1110  Then
			dm::keydown(37);
			ElseIf y == 2100 and x <= 980  Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 2020 and x > 920  Then
			dm::keydown(37);
			ElseIf y == 2020 and x <= 920  Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1940 and x < 830  Then
			dm::keydown(39);
			ElseIf y == 1940 and x >= 830 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1870 and x > 960 Then
			dm::keydown(37);
			ElseIf y == 1870 and x <= 960 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1790 and x <= 960 and x >= 780 Then
			{
			dm::keydown(37);
			If speedX >= 760 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			Else
			If x <= 860 Then   CreateThread(NULL, NULL, ◊ÛÃ¯, NULL, NULL, NULL);
			If x <= 810 Then   CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			}
			ElseIf y == 1550 or y == 1590 or y == 1660 or y == 1730 or y == 1810 or y == 1880 and x <= 360 Then
			dm::keydown(39);
			ElseIf y == 1960 and x < 390 Then
			dm::keydown(39);
			ElseIf y == 1960 and x >= 390 and x <= 530 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 2040 and x < 300 Then
			dm::keydown(39);
			ElseIf y == 2040 and x >= 300 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 2110 and x < 260 Then
			dm::keydown(39);
			ElseIf y == 2110 and x >= 260 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 2180 and x < 160 Then
			dm::keydown(39);
			ElseIf y == 2180 and x > 320 and x <= 520 Then
			dm::keydown(37);
			ElseIf y == 2180 and x <= 320 and x >= 160 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1880 and x < 500 and x < 2110 Then
			dm::keydown(39);
			ElseIf y == 1880 and x >= 500 and x <= 2110 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1800 and x < 630 Then
			dm::keydown(39);
			ElseIf y == 1800 and x >= 630 and x < 1440 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1720 and x < 770 Then
			dm::keydown(39);
			ElseIf y == 1720 and x >= 770 and x < 1380 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1640 and x < 960 Then
			dm::keydown(39);
			ElseIf y == 1640 and x > 920 and x < 1270 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1560 and x < 1000 Then
			dm::keydown(39);
			ElseIf y == 1560 and x >= 1000 and x <= 1070 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1480 and x < 1145 Then
			dm::keydown(39);
			ElseIf y == 1480 and x >= 1145 and x <= 1160 Then
			{
			  CreateThread(NULL, NULL, ”“Ã¯, NULL, NULL, NULL);
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			}
			ElseIf y == 1410 and x < 1290 Then
			dm::keydown(39);
			ElseIf y == 1410 and x >= 1290 and x <= 1320 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1330 and x < 1400 Then
			dm::keydown(39);
			ElseIf y == 1330 and x >= 1400 and x <= 1440 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1260 and x < 1470 Then
			dm::keydown(39);
			ElseIf y == 1260 and x >= 1470 and x <= 1540 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1190 and x < 1830 Then
			dm::keydown(39);
			ElseIf y == 1190 and x >= 1830 and x <= 1870 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			ElseIf y == 1110 and x < 1930 and x < 1980 Then
			dm::keydown(39);
			ElseIf y == 1110 and x >= 1930 and x < 1980 Then
			  CreateThread(NULL, NULL, …œÃ¯, NULL, NULL, NULL);
			return false;
	}
	bool RunHoleExit(DWORD mapid, DWORD currentstate, DWORD x, DWORD y, bool* PressedKeys)
	{
		If x <= 1956 Then
		{
			dm::keydown(39);
		}
			ElseIf x >= 1956 and currentstate == 0 Then
		{
			dm::keyup(39);
		dm::keypress(71);
		}
			ElseIf mapid == 462 and currentstate == 1 Then
			dm::keypress(13);
			ElseIf mapid == 462 and currentstate == 2 Then//≤ª÷ÿ“™
				dm::keypress(13);
			ElseIf mapid == 462 and currentstate == 14 Then
				dm::keypress(13);
			ElseIf mapid == 462 and currentstate == 21 Then
			{
				//¥Ã‚
				HDC hdc = 0;
		hdc = GetDC(gameWindows);
		COLORREF A0 = GetPixel(hdc, 316, 292);
		bool A = false;
		DWORD A0R = GetRValue(A0);
		DWORD A0G = GetGValue(A0);
		DWORD A0B = GetBValue(A0);
		COLORREF B0 = GetPixel(hdc, 314, 316);
		bool B = false;
		DWORD B0R = GetRValue(B0);
		DWORD B0G = GetGValue(B0);
		DWORD B0B = GetBValue(B0);
		COLORREF C0 = GetPixel(hdc, 316, 349);
		bool C = false;
		DWORD C0R = GetRValue(C0);
		DWORD C0G = GetGValue(C0);
		DWORD C0B = GetBValue(C0);
		COLORREF D0 = GetPixel(hdc, 316, 379);
		bool D = false;
		DWORD D0R = GetRValue(D0);
		DWORD D0G = GetGValue(D0);
		DWORD D0B = GetBValue(D0);
		if (A0R != 0 && A0G != 25 && A0B != 35)
		{
			SendMessage(gameWindows, WM_MOUSEMOVE, 0, MAKELPARAM(316, 292));
			dm::keypress(1);
			printf("A");
		}
		else if (B0R != 0 && B0G != 25 && B0B != 35)
		{
			printf("B");
			SendMessage(gameWindows, WM_MOUSEMOVE, 0, MAKELPARAM(314, 316));
			dm::keypress(1);
		}
		else if (C0R != 0 && C0G != 25 && C0B != 35)
		{
			SendMessage(gameWindows, WM_MOUSEMOVE, 0, MAKELPARAM(316, 349));
			dm::keypress(1);
			printf("C");
		}
		else if (D0R != 0 && D0G != 25 && D0B != 35)
		{
			SendMessage(gameWindows, WM_MOUSEMOVE, 0, MAKELPARAM(316, 379));
			dm::keypress(1);
			printf("D");
		}
		else
		{
			SendMessage(gameWindows, WM_MOUSEMOVE, 0, MAKELPARAM(316, 379));
			dm::keypress(1);
			printf("Don't know");
		}
			}
			return false;
	}
	static bool goDownOne = false;
	bool RunOutSide(DWORD mapid, DWORD currentstate, DWORD x, DWORD y)
	{
		if (y >= 682)
		{
			if (currentstate == 0)
				dm::keypress(71);
			else if (currentstate == 2)
				dm::keypress(13);
			else if (currentstate == 1 && !goDownOne)
			{
				dm::keypress(40);
				goDownOne = true;
			}
			else if (currentstate == 1 && goDownOne)
			{
				dm::keypress(13);
				goDownOne = false;
			}
		}
		return false;
	}
	bool clearType(BOOL intype)
	{
		if(intype)
			dm::keypress(13);
		return false;
	}
}