#include "Player_sd.h"
#include "player.h"
#include "SpriteData.h"
#include "SceneStageSelect.h"


static constexpr float PLAYER_SPEED = 10.0f;
static constexpr float PLAYER_LIMIT_L = 32;
static constexpr float PLAYER_LIMIT_R = 1280 - 32;
static constexpr float PLAYER_LIMIT_U = 32;
static constexpr float PLAYER_LIMIT_D = 720 - 32;

bool sd_reset;

void PlayerManager_sd::init()
{
    OBJ2DManager::init();
    sd_reset = true;

    switch (stage_number)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        searchSet(player_sd_Update, { 544, 264 }); break;
    case 3:
        searchSet(player_sd_Update, { 480, 328 }); break;
    case 4:
        searchSet(player_sd_Update, { 416, 216 }); break;
        searchSet(player_sd_Update, { 416, 456 }); break;// 2人目のプレイヤー
    case 5:
        searchSet(player_sd_Update, { 544, 168 }); break;
        searchSet(player_sd_Update, { 352, 360 }); break;// 2人目のプレイヤー
    
    case 6:
        searchSet(player_sd_Update, { 480, 136 });
        searchSet(player_sd_Update, { 800, 136 });
        searchSet(player_sd_Update, { 480, 456 }); break;


    }
}

void PlayerManager_sd::update()
{
    isMove = false;
    for (auto& item : *this)
    {
        if (item.isMoving)
        {
            isMove = true;
            break;
        }
    }

    OBJ2DManager::update();
}

//-----------------------------------------------------------------------------------
//player
static bool isColliding = false;// 衝突状態を管理


void player_sd_Move(OBJ2D* obj)
{

    if (!(PlayerManager::getInstance().isMoving() || PlayerManager_sd::getInstance().isMoving())) //WASDが押されていないとき
    {
        bool up = GameLib::input::STATE(0) & GameLib::input::PAD_UP;
        bool down = GameLib::input::STATE(0) & GameLib::input::PAD_DOWN;
        bool left = GameLib::input::STATE(0) & GameLib::input::PAD_LEFT;
        bool right = GameLib::input::STATE(0) & GameLib::input::PAD_RIGHT;

        int keyCount = up + down + left + right;


        if (keyCount == 1) //「1つだけ押されている場合」に限定
        {
            if (up) { obj->direction.y = -PLAYER_SPEED; }
            if (down) { obj->direction.y = PLAYER_SPEED; }
            if (left) { obj->direction.x = -PLAYER_SPEED; }
            if (right) { obj->direction.x = PLAYER_SPEED; }

            obj->isMoving = true;
        }

    }

    if (obj->isMoving)
    {
        obj->position += obj->direction;
    }

    
}

//-----------------------------------------------------------------------------------

void player_sd_Update(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        obj->sprData = &sprPlayer_sd;
        obj->color = { 1,1,1,1 };
        obj->scale = { 1.0f,1.0f };
        obj->speed = 1;
        obj->direction = { 0,0 };
        obj->isMoving = false;
        
        obj->hSize = { 63 / 2,63 / 2 };
        obj->judge = JUDGE_ALL;
        obj->state++;
        [[fallthrough]];
    case 1:
        // プレイヤー移動
        player_sd_Move(obj);

        // 移動範囲チェック
        if (obj->position.x < PLAYER_LIMIT_L) { obj->position.x = PLAYER_LIMIT_L; direction_sd_reset(obj); }
        if (obj->position.x > PLAYER_LIMIT_R) { obj->position.x = PLAYER_LIMIT_R; direction_sd_reset(obj); }
        if (obj->position.y < PLAYER_LIMIT_U) { obj->position.y = PLAYER_LIMIT_U; direction_sd_reset(obj); }
        if (obj->position.y > PLAYER_LIMIT_D) { obj->position.y = PLAYER_LIMIT_D; direction_sd_reset(obj); }
        
        if (obj->goaled) {
            obj->timer = 0;
            obj->state++;
        }

        obj->timer++;

        break;
    case 2:
        if (sd_reset)
        {
            sd_reset = false;
            obj->goaled = false;
            obj->state = 0;
        }
        
        obj->timer++;
        break;

    }
}


void direction_sd_reset(OBJ2D* obj)
{
    obj->velocity = { 0,0 };
    obj->isMoving = false;
    //obj->sprData = &sprPlayer_sd;
    obj->direction = { 0,0 };
    
    //PlayerManager::getInstance().setIsPlayerSecondMove(false);
}

void player_sd_reset(OBJ2D* obj)
{
    obj->isMoving = false;
    obj->state = 0;
}
