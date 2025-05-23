#include "SpriteData.h"

GameLib::LoadTexture loadTexture[] = {
    { TEXNO::BACK01, L"./Data/Images/BACK01.png", 4U },
    { TEXNO::TITLE0, L"./Data/Images/title.png",  4U},
    { TEXNO::PLAYER, L"./Data/Images/player.png", 4U},
    { TEXNO::BLOCK,L"./Data/Images/wall.png", 4U},
    { TEXNO::HAKO,L"./Data/Images/hako.png", 4U },
    { TEXNO::UGOKU,L"./Data/Images/ugoku.png", 4U},
    // マップの block と ugoku と hako をここに用意
    

    { -1, nullptr, }, // 終了フラグ
};

SpriteUpperLeft sprBack(TEXNO::BACK01, 0, 0, 1280, 720);
SpriteUpperLeft sprTitle(TEXNO::TITLE0, 0, 0, 1280, 720);

SpriteCenter sprPlayer(TEXNO::PLAYER, 0, 0, 64, 64);
//SpriteCenter sprWall(TEXNO::WALL, 0, 0, 64, 64);

// マップの block と uboku と hako の SpriteCenter の本体をここに用意
SpriteCenter sprblock(TEXNO::BLOCK, 0, 0, 64, 64);
SpriteCenter sprhako(TEXNO::HAKO, 0, 0, 64, 64);
SpriteCenter sprugoku(TEXNO::UGOKU, 0, 0, 64, 64);
