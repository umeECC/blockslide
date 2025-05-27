#include "SpriteData.h"

GameLib::LoadTexture loadTexture[] = {
    { TEXNO::BACK01, L"./Data/Images/BACK01.png", 4U },
    { TEXNO::TITLE0, L"./Data/Images/title.png",  4U},
    { TEXNO::PLAYER, L"./Data/Images/player.png", 4U},
    { TEXNO::BLOCK,L"./Data/Images/wall.png", 4U},
    { TEXNO::HAKO,L"./Data/Images/hako.png", 4U },
    { TEXNO::UGOKU,L"./Data/Images/ugoku.png", 4U},
    { TEXNO::SELECT, L"./Data/Images/stage_select.png",4U},
    { TEXNO::ENDO, L"./Data/Images/end.png", 4U},
    { TEXNO::PUSH, L"./Data/Images/push_space.png", 4U},

    // マップの block と ugoku と hako をここに用意
    

    { -1, nullptr, }, // 終了フラグ
};

SpriteUpperLeft sprBack(TEXNO::BACK01, 0, 0, 1280, 720);
SpriteUpperLeft sprTitle(TEXNO::TITLE0, 0, 0, 1280, 720);
SpriteUpperLeft sprStageSelect(TEXNO::SELECT, 0, 0, 1280, 720);
SpriteUpperLeft sprEnd(TEXNO::ENDO, 0, 0, 1280, 720);

SpriteCenter sprPush(TEXNO::PUSH, 0, 0, 310, 100);

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
//SpriteCenter sprWall(TEXNO::WALL, 0, 0, 64, 64);

// マップの block と uboku と hako の SpriteCenter の本体をここに用意
SpriteCenter sprblock(TEXNO::BLOCK, 0, 0, 64, 64);
SpriteCenter sprhako(TEXNO::HAKO, 0, 0, 64, 64);
SpriteCenter sprugoku(TEXNO::UGOKU, 0, 0, 64, 64);
