#pragma once
#include "Offsets.h"

namespace Equipment
{
	DWORD& GetHeadCur()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + HAT);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTCUR);
	}
	DWORD& GetHeadMax()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + HAT);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTMAX);
	}

	DWORD& GetGlassCur()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + GLASS);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTCUR);
	}
	DWORD& GetGlassMax()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + GLASS);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTMAX);
	}

	DWORD& GetNeckCur()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + NECK);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTCUR);
	}
	DWORD& GetNeckMax()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + NECK);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTMAX);
	}

	DWORD& GetWingCur()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + WING);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTCUR);
	}
	DWORD& GetWingMax()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + WING);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTMAX);
	}

	DWORD& GetUpperCur()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + UPPER);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTCUR);
	}
	DWORD& GetUpperMax()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + UPPER);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTMAX);
	}

	DWORD& GetLowerCur()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + LOWER);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTCUR);
	}
	DWORD& GetLowerMax()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + LOWER);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTMAX);
	}

	DWORD& GetArmCur()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + ARM);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTCUR);
	}
	DWORD& GetArmMax()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + ARM);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTMAX);
	}

	DWORD& GetShoeCur()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + SHOE);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTCUR);
	}
	DWORD& GetShoeMax()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + SHOE);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTMAX);
	}

	DWORD& GetWeaponCur()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + RIGHTWEAPON);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTCUR);
	}
	DWORD& GetWeaponMax()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + RIGHTWEAPON);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTMAX);
	}

	DWORD& GetRingCur()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + RING);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTCUR);
	}
	DWORD& GetRingMax()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + RING);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTMAX);
	}

	DWORD& GetFuZhouCur()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + FUZHOU);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTCUR);
	}
	DWORD& GetFuZhouMax()
	{
		DWORD nothing = -1;
		DWORD_PTR Equip = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + EQUIPMENT1) + FUZHOU);
		if (!Equip)
			return nothing;
		return *reinterpret_cast<DWORD*>(Equip + EQUIPMENTMAX);
	}


}

namespace Overworld
{
	DWORD& GetCurrentMapIndex()
	{
		DWORD_PTR Map = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + MAP) + CURRENTMAP);
		DWORD nothing = -1;
		if (!Map)
			return nothing;
		return *reinterpret_cast<DWORD*>(Map + CURRENTMAPID);
	}
	DWORD& GetCurrentPosX()
	{
		DWORD_PTR Map = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + MAP) + CURRENTMAP);
		DWORD nothing = -1;
		if (!Map)
			return nothing;
		return *reinterpret_cast<DWORD*>(Map + XPOS);
	}
	DWORD& GetCurrentPosY()
	{
		DWORD_PTR Map = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + MAP) + CURRENTMAP);
		DWORD nothing = -1;
		if (!Map)
			return nothing;
		return *reinterpret_cast<DWORD*>(Map + YPOS);
	}
	DWORD& GetCurrentSpeedHor()
	{
		DWORD_PTR Map = *reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + MAP) + CURRENTSTATE);
		DWORD nothing = -1;
		if (!Map)
			return nothing;
		return *reinterpret_cast<DWORD*>(Map + RUN);
	}
	DWORD& GetCurrentState()
	{
		return *reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD_PTR*>(*reinterpret_cast<DWORD_PTR*>(LOCALPLAYER) + CONVERSATIONSTATE1) + CONVERSATIONSTATE2);
	}
}

namespace Social
{
	BYTE& GetCurrentTypingState()
	{
		return *reinterpret_cast<BYTE*>(INTYPE);
	}
}