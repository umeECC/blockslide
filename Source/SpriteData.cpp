#include "SpriteData.h"

GameLib::LoadTexture loadTexture[] = {
    { TEXNO::BACK01, L"./Data/Images/BACK01.png", 4U },
    { TEXNO::TITLE0, L"./Data/Images/title.png",  4U},
    { TEXNO::PLAYER, L"./Data/Images/player.png", 4U},
    { TEXNO::SELECT, L"./Data/Images/stage_select.png",4U},

    { -1, nullptr, }, // èIóπÉtÉâÉO
};

SpriteUpperLeft sprBack(TEXNO::BACK01, 0, 0, 1280, 720);
SpriteUpperLeft sprTitle(TEXNO::TITLE0, 0, 0, 1280, 720);
SpriteUpperLeft sprStageSelect(TEXNO::SELECT, 0, 0, 1280, 720);

SpriteCenter sprPlayer(TEXNO::PLAYER, 0, 0, 64, 64);
SpriteCenter P_Down(TEXNO::PLAYER, 64, 0, 64, 64);
SpriteCenter P_Right(TEXNO::PLAYER, 128, 0, 64, 64);
SpriteCenter P_Left(TEXNO::PLAYER, 192, 0, 64, 64);
SpriteCenter P_Up(TEXNO::PLAYER, 256, 0, 64, 64);
//SpriteCenter sprWall(TEXNO::WALL, 0, 0, 64, 64);
