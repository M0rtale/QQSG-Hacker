#pragma once

#define LOCALPLAYER 0x10F9134 

//LOCALPLAYER + equipment1 + hat/glass/etc + equipmentcur/equipmentmax
#pragma region equipment
#define EQUIPMENT1 0x38

#define HAT 0x348
#define GLASS 0x34C
#define NECK 0x350
#define WING 0x354
#define UPPER 0x358
#define LOWER 0x35C
#define ARM 0x360
#define SHOE 0x364
#define LEFTWEAPON 0x368
#define RIGHTWEAPON 0x36C // ÎäÆ÷
#define RING 0x370
#define FUZHOU 0x374

#define EQUIPMENTCUR 0x28
#define EQUIPMENTMAX 0x2C // +4byte

#pragma endregion

//LOCALPLAYER + MAP + CURRENTMAP + CURRENTMAPID
#pragma region overworld
#define MAP 0x0C

#define CURRENTMAP 0x334
#define CURRENTSTATE 0x338

#define CURRENTMAPID 0x18C
#define XPOS 0x54
#define YPOS 0x58
#define RUN 0x354 

#define HOLE6 456
#define HOLE3 457
#define HOLE2 458
#define HOLE5 459
#define HOLE4 460
#define HOLE1 461
#define HOLEEND 462
#define ENTRYYANNIAODU 28 // entry point
#pragma endregion


#pragma region other
#define CONVERSATIONSTATE1 0x20

#define CONVERSATIONSTATE2 0x0
#pragma endregion

#pragma region social
#define INTYPE 0x10FB3DC  
#pragma endregion