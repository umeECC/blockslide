#pragma once
#include "../GameLib/game_lib.h"
#include "../GameLib/obj2d_data.h"

enum TEXNO
{
    BACK01,
    TITLE0,
    PLAYER,
    PLAYERSD,
    WALL,
    ENDO,
    SELECT,
    PUSH,
    GOAL,
    HAKO,
    WARP,
    TOGE,
    CLEAR_B,
    YAJI,
};

struct SpriteUpperLeft : public GameLib::SpriteData
{
    SpriteUpperLeft(int texno, float left, float top, float width, float height)
    {
        this->texNo = texno;
        this->left = left;
        this->top = top;
        this->width = width;
        this->height = height;
        this->centerX = 0;
        this->centerY = 0;
    }
};

struct SpriteCenter : public GameLib::SpriteData
{
    SpriteCenter(int texno, float left, float top, float width, float height)
    {
        this->texNo = texno;
        this->left = left;
        this->top = top;
        this->width = width;
        this->height = height;
        this->centerX = width / 2;
        this->centerY = height / 2;
    }
};

extern GameLib::LoadTexture loadTexture[];

extern SpriteUpperLeft sprBack;
extern SpriteUpperLeft sprTitle;
extern SpriteUpperLeft sprStart;
extern SpriteUpperLeft sprStageSelect;
extern SpriteUpperLeft sprEnd;
extern SpriteUpperLeft sprClear;
extern SpriteCenter sprPush;
extern SpriteCenter sprYaji;

extern SpriteCenter sprPlayer;
extern SpriteCenter PlayerGoal[8];
extern SpriteCenter P_Up;
extern SpriteCenter P_Down;
extern SpriteCenter P_Left;
extern SpriteCenter P_Right;

extern SpriteCenter sprPlayer_sd;

extern SpriteCenter sprWall;
extern SpriteCenter sprGoal;
extern SpriteCenter sprHako;

extern SpriteCenter sprWarp;

extern SpriteCenter sprToge;