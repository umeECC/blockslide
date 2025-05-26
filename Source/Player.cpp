#include "Player.h"
#include "player_sd.h"
#include "SpriteData.h"

static constexpr float PLAYER_SPEED = 10.0f;
static constexpr float PLAYER_LIMIT_L = 32;
static constexpr float PLAYER_LIMIT_R = 1280 - 32;
static constexpr float PLAYER_LIMIT_U = 32;
static constexpr float PLAYER_LIMIT_D = 720 - 32;

//bool isGrounded;

void PlayerManager::init()
{
    OBJ2DManager::init();
    searchSet(playerUpdate, { 600,500 });////////
   
}
void PlayerManager::update()
{

    this->isMove = false;
    for (auto& item : *this)
    {
        if (item.isMoving)
        {
            this->isMove = true;
            break;
        }
    }



    OBJ2DManager::update();
}

//-----------------------------------------------------------------------------------
//player

static bool isColliding = false;

void playerMove(OBJ2D* obj)
{
    //if (!obj->isMoving) //WASDが押されていないとき
    if (!(PlayerManager::getInstance().isMoving() || PlayerManager_sd::getInstance().isMoving())) //WASDが押されていないとき
    {
        bool up = GameLib::input::STATE(0) & GameLib::input::PAD_UP;
        bool down = GameLib::input::STATE(0) & GameLib::input::PAD_DOWN;
        bool left = GameLib::input::STATE(0) & GameLib::input::PAD_LEFT;
        bool right = GameLib::input::STATE(0) & GameLib::input::PAD_RIGHT;

        int keyCount = up + down + left + right;

        if (keyCount == 1) //「1つだけ押されている場合」に限定
        {
            if (up) { obj->sprData = &P_Up; obj->direction.y = -PLAYER_SPEED; }
            if (down) { obj->sprData = &P_Down; obj->direction.y = PLAYER_SPEED; }
            if (left) { obj->sprData = &P_Left; obj->direction.x = -PLAYER_SPEED; }
            if (right) { obj->sprData = &P_Right; obj->direction.x = PLAYER_SPEED; }

            PlayerManager::getInstance().clearHit();
            PlayerManager_sd::getInstance().clearHit();

            obj->isMoving = true;
            //PlayerManager::getInstance().setIsPlayerOneMove(true);
        }
    }
    if (obj->isMoving)
    {
        obj->position += obj->direction;
    }
    
}

//-----------------------------------------------------------------------------------
void state;
void playerUpdate(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        obj->sprData = &sprPlayer;
        obj->color = { 1,1,1,1 };
        obj->scale = { 1.0f,1.0f };
        obj->speed = 1;
        obj->direction = { 0,0 };
        obj->isMoving = false;
        obj->position = { 660,370 };
        obj->hSize = { 64 / 2,64 / 2 };
        obj->judge = JUDGE_ALL;
        obj->state++;
        [[fallthrough]];
    case 1:
        // プレイヤー移動
        playerMove(obj);

        // 移動範囲チェック
        if (obj->position.x < PLAYER_LIMIT_L) { obj->position.x = PLAYER_LIMIT_L; direction_reset(obj); }
        if (obj->position.x > PLAYER_LIMIT_R) { obj->position.x = PLAYER_LIMIT_R; direction_reset(obj); }
        if (obj->position.y < PLAYER_LIMIT_U) { obj->position.y = PLAYER_LIMIT_U; direction_reset(obj); }
        if (obj->position.y > PLAYER_LIMIT_D) { obj->position.y = PLAYER_LIMIT_D; direction_reset(obj); }
        break;
        }
    }


void direction_reset(OBJ2D* obj)
{
    obj->isMoving = false;
    obj->sprData = &sprPlayer;
    obj->direction = { 0,0 };
    //PlayerManager::getInstance().setIsPlayerOneMove(false);
}
