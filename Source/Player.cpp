#include "Player.h"
#include "player_sd.h"
#include "SpriteData.h"
#include "SceneStageSelect.h"
#include "WinMain.h"
#include <cstdlib>
#include <cmath>


static constexpr float PLAYER_SPEED = 10.0f;
static constexpr float PLAYER_LIMIT_L = 32;
static constexpr float PLAYER_LIMIT_R = 1280 - 32;
static constexpr float PLAYER_LIMIT_U = 32;
static constexpr float PLAYER_LIMIT_D = 720 - 32;

int currentSceneID;

void PlayerManager::init()
{
    OBJ2DManager::init();
    switch (stage_number)
    {
    case 0:
        searchSet(playerUpdate, { 544, 431 }); break;
    case 1:
        searchSet(playerUpdate, { 544, 431 }); break;
    case 2:
        searchSet(playerUpdate, { 480, 200 }); break;
    case 3:
        searchSet(playerUpdate, { 800, 136 }); break;
        
    }
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


            //WallManager::getInstance().clearHit();

            obj->isMoving = true;
            //PlayerManager::getInstance().setIsPlayerOneMove(true);
        }

    }
    if (obj->isMoving)
    {
        obj->position += obj->direction;
    }

    if (GameLib::input::STATE(0) & GameLib::input::PAD_START)
    {
        direction_reset(obj);
    }
}

void ssPlayerMove(OBJ2D* obj) //ステージセレクトシーンでの動き
{
    bool left = GameLib::input::STATE(0) & GameLib::input::PAD_LEFT;
    bool right = GameLib::input::STATE(0) & GameLib::input::PAD_RIGHT;

    int keyCount = left + right;

    if (keyCount == 1)
    {
        if (GameLib::input::STATE(0) & GameLib::input::PAD_LEFT) {
            obj->sprData = &P_Left; obj->state = 1;
        }
        if (GameLib::input::STATE(0) & GameLib::input::PAD_RIGHT) {
            obj->sprData = &P_Right; obj->state = 1;
        }
    }
}

//-----------------------------------------------------------------------------------

void playerUpdate(OBJ2D* obj)
{
    switch (currentSceneID)
    {
    case SCENE::TITLE:
        switch (obj->state)
        {
        case 0:
            obj->sprData = &sprPlayer;
            obj->color = { 1,1,1,1 };
            obj->scale = { 1.3f,1.3f };
            obj->speed = 10;
            obj->direction = { 0,0 };
            obj->isMoving = false;
            obj->position = { 950,660 };
            obj->hSize = { 62 / 2,62 / 2 };
            obj->timer = 0;
            obj->state++;
            [[fallthrough]];
        case 1:
            if (obj->timer > 30)
            {
                obj->position.x += -obj->speed;
                obj->sprData = &P_Left;
                if (obj->position.x <= 500)
                {
                    direction_reset(obj);
                    obj->timer = 0;
                    obj->state++;
                }
            }
            obj->timer++;
            break;

        case 2:
            if (obj->timer > 10)
            {
                obj->state++;
            }
            obj->timer++;
            break;

        case 3:
            obj->position.y += -obj->speed;
            obj->sprData = &P_Up;
            if (obj->position.y <= 100)
            {
                direction_reset(obj);
                obj->timer = 0;
                obj->state++;
            }
            obj->timer++;
            break;

        case 4:
            goal_moving(obj);
            obj->timer++;
            break;
        }
        break;
    case SCENE::STAGESEL:
        switch (obj->state)
        {
        case 0:
            obj->sprData = &sprPlayer;
            obj->color = { 1,1,1,1 };
            obj->scale = { 1.5f,1.5f };
            obj->speed = 5;
            obj->direction = { 0,0 };
            obj->isMoving = false;
            obj->position = { 180,170 };
            obj->hSize = { 64 / 2,64 / 2 };
            obj->timer = 0;
            obj->state++;
            [[fallthrough]];
        case 1:

            obj->color = { 1,1,1,1 };
            obj->scale = { 1.5f,1.5f };
            obj->rotation = 0;

            switch (stage_number)
            {
            case 0:
                break;
            case 1:
                obj->position = { 180,170 };
                break;
            case 2:
                obj->position = { 480,170 };
                break;
            case 3:
                obj->position = { 780,170 };
                break;
            case 4:
                obj->position = { 1065,170 };
                break;
            case 5:
                obj->position = { 180,495 };
                break;
            case 6:
                obj->position = { 480,495 };
                break;
            case 7:
                obj->position = { 780,495 };
                break;
            case 8:
                obj->position = { 1065,495 };
                break;
            }
            obj->state++;
            break;

        case 2:

            ssPlayerMove(obj);

            break;
        }

        break;
    case SCENE::GAME:
        switch (obj->state)
        {
        case 0:
            obj->sprData = &sprPlayer;
            obj->color = { 1,1,1,1 };
            obj->scale = { 1.0f,1.0f };
            obj->speed = 1;
            obj->direction = { 0,0 };
            obj->isMoving = false;
            
            obj->hSize = { 62 / 2,62 / 2 };
            obj->judge = JUDGE_ALL;
            obj->timer = 0;
            obj->goaled = false;
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

            if (obj->goaled) {
                obj->timer = 0;
                obj->state++;
            }

            obj->timer++;

            break;
        case 2:
            goal_moving(obj);

            obj->timer++;
            break;

        }
        break;
    case SCENE::CLEAR:
        switch (obj->state)
        {
        case 0:
            obj->sprData = &sprPlayer;
            obj->color = { 1,1,1,1 };
            obj->scale = { 1.5f,1.5f };
            obj->speed = 5;
            obj->direction = { 0,0 };
            obj->isMoving = false;
            obj->position = { 180,170 };
            obj->hSize = { 64 / 2,64 / 2 };
            obj->timer = 0;
            obj->state++;
            [[fallthrough]];
        case 1:
            float radius = 300.0f;
            
            // 回転角（ラジアン）を時間で増やす
            float angle = obj->timer * 10e+8; // 回転速度（小さくするとゆっくり）
            
            obj->position.x = 640 + std::cos(angle) * radius;
            obj->position.y = 370 + std::sin(angle) * radius;
            
            // ランダムカラー（毎フレームチカチカ）
            obj->color = {
                static_cast<float>(rand()) / RAND_MAX,
                static_cast<float>(rand()) / RAND_MAX,
                static_cast<float>(rand()) / RAND_MAX,
                1.0f
            };
            
            obj->scale = { 2.0f, 2.0f };
            obj->sprData = &sprPlayer;
            
            obj->timer++;

            break;
        }

    }
}


void direction_reset(OBJ2D* obj)
{
    obj->isMoving = false;
    obj->sprData = &sprPlayer;
    obj->direction = { 0,0 };
    //PlayerManager::getInstance().setIsPlayerOneMove(false);
}

void goal_moving(OBJ2D* obj)
{
    obj->isMoving = false;

    obj->direction = { 0,0 };

    int frame = (obj->timer / 5);

    if (frame > 7)
    {
        obj->sprData = &PlayerGoal[7];
    }
    else
    {
        obj->sprData = &PlayerGoal[frame];
    }
}

void player_reset(OBJ2D* obj)
{
    obj->isMoving = false;
    obj->state=0;
}
