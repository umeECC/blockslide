#include "SpriteData.h"

GameLib::LoadTexture loadTexture[] = {
    { TEXNO::BACK01, L"./Data/Images/BACK01.png", 4U },
    { TEXNO::TITLE0, L"./Data/Images/title.png",  4U},
    { TEXNO::PLAYER, L"./Data/Images/player.png", 4U},
    { TEXNO::PLAYERSD, L"./Data/Images/kabe1.png", 4U},
    { TEXNO::WALL, L"./Data/Images/wall.png", 4U},
    { TEXNO::ENDO, L"./Data/Images/end.png", 4U},
    { TEXNO::SELECT, L"./Data/Images/stage_select.png",4U},
    { TEXNO::PUSH, L"./Data/Images/push_space.png", 4U},
    { TEXNO::HAKO,L"./Data/Images/hako.png",4U},
    { TEXNO::GOAL, L"./Data/Images/goal.png", 4U},
    { TEXNO::WARP, L"./Data/Images/warp.png", 4U},
    { TEXNO::TOGE, L"./Data/Images/spike.png", 4U},


    { -1, nullptr, }, // 終了フラグ
};

SpriteUpperLeft sprBack(TEXNO::BACK01, 0, 0, 1280, 720);
SpriteUpperLeft sprTitle(TEXNO::TITLE0, 0, 0, 1280, 720);
SpriteUpperLeft sprStageSelect(TEXNO::SELECT, 0, 0, 1280, 720);
SpriteUpperLeft sprEnd(TEXNO::ENDO, 0, 0, 1280, 720);

SpriteCenter sprPush(TEXNO::PUSH, 0, 0, 310, 100);

//プレイヤー
SpriteCenter sprPlayer(TEXNO::PLAYER, 0, 0, 64, 64);
SpriteCenter P_Down(TEXNO::PLAYER, 64, 0, 64, 64);
SpriteCenter P_Right(TEXNO::PLAYER, 128, 0, 64, 64);
SpriteCenter P_Left(TEXNO::PLAYER, 192, 0, 64, 64);
SpriteCenter P_Up(TEXNO::PLAYER, 256, 0, 64, 64);
SpriteCenter PlayerGoal[8] = {
    { TEXNO::PLAYER, 0 * 64, 1 * 64, 64, 64 },
    { TEXNO::PLAYER, 1 * 64, 1 * 64, 64, 64 },
    { TEXNO::PLAYER, 2 * 64, 1 * 64, 64, 64 },
    { TEXNO::PLAYER, 3 * 64, 1 * 64, 64, 64 },
    { TEXNO::PLAYER, 4 * 64, 1 * 64, 64, 64 },
    { TEXNO::PLAYER, 5 * 64, 1 * 64, 64, 64 },
    { TEXNO::PLAYER, 6 * 64, 1 * 64, 64, 64 },
    { TEXNO::PLAYER, 7 * 64, 1 * 64, 64, 64 },
};

//動く箱
SpriteCenter sprPlayer_sd(TEXNO::PLAYERSD, 0, 0, 64, 64);
SpriteCenter P_Down_sd(TEXNO::PLAYERSD, 64, 0, 64, 64);
SpriteCenter P_Right_sd(TEXNO::PLAYERSD, 128, 0, 64, 64);
SpriteCenter P_Left_sd(TEXNO::PLAYERSD, 192, 0, 64, 64);
SpriteCenter P_Up_sd(TEXNO::PLAYERSD, 256, 0, 64, 64);

SpriteCenter sprWall(TEXNO::WALL, 0, 0, 64, 64);
SpriteCenter sprGoal(TEXNO::GOAL, 0, 0, 64, 64);
SpriteCenter sprHako(TEXNO::HAKO, 0, 0, 64, 64);
SpriteCenter sprWarp(TEXNO::WARP, 0, 0, 64, 64);
SpriteCenter sprToge(TEXNO::TOGE, 0, 0, 64, 64);
