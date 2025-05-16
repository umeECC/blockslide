#pragma once

#include "../GameLib/game_lib.h"
#include "../GameLib/obj2d_data.h"
inline constexpr int JUDGE_PLAYER = 0x01;
inline constexpr int JUDGE_BLOCK = 0x02;
inline constexpr int JUDGE_GOAL = 0x04;
inline constexpr int PLAYER_POWER_UP = 0x01;
inline constexpr int PLAYER_SPEED_UP = 0x02;
inline constexpr int PLAYER_RANGE_UP = 0x04;
inline constexpr int JUDGE_ALL = (JUDGE_PLAYER);

class OBJ2D
{
public:
    typedef void (*MOVER)(OBJ2D* obj);


    GameLib::SpriteData* sprData;
    VECTOR2 position;
    VECTOR2 scale;      //範囲
    float rotation;
    VECTOR4 color;
    GameLib::Blender::BLEND_STATE blendState;

    int state;
    VECTOR2 velocity;
    int timer;

    MOVER mover;    // 移動処理（関数ポインタ）
    int index;

    VECTOR2 direction;
    bool isMoving;

    VECTOR2 hSize;
    int judge;

    int score;

    int speed;         //速度

    int stage;          //現在のステージ数

    OBJ2D() { init(); }

    void init()
    {
        sprData = nullptr;
        position = {};
        scale = { 1,1 };
        rotation = 0.0f;
        color = { 1,1,1,1 };
        blendState = GameLib::Blender::BLEND_STATE::BS_ALPHA;

        state = 0;
        velocity = {};
        timer = 0;

        mover = 0;
        index = 0;

        direction = { 0, 0 };
        isMoving = false;

        hSize = {};
        judge = 0;
        
        score = 0;

        speed = 0; //速度
        stage = 0;

    }

    void clear() { init(); }

    void update();
    void draw();
};

class OBJ2DManager
{
private:
    
   

public:
    virtual OBJ2D* end() = 0;
    virtual OBJ2D* begin() = 0;
    virtual void init();
    void update();
    void draw();

    OBJ2D* searchSet(OBJ2D::MOVER mover, const VECTOR2& position);
};
