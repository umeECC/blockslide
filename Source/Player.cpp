#include "Player.h"
#include "player_sd.h"
#include "SpriteData.h"
#include "WinMain.h"
#include <cstdlib>
#include <cmath>

static constexpr float PLAYER_SPEED = 10.0f;
static constexpr float PLAYER_LIMIT_L = 32;
static constexpr float PLAYER_LIMIT_R = 1280 - 32;
static constexpr float PLAYER_LIMIT_U = 32;
static constexpr float PLAYER_LIMIT_D = 720 - 32;

int currentSceneID;
int stage_number;

void PlayerManager::init()
{
    OBJ2DManager::init();
    searchSet(playerUpdate, { 32 + 64 * 10, 32 + 64 * 9 });////////
}

//-----------------------------------------------------------------------------------
//player

#if fasel
void playerMove(OBJ2D* obj)
{
    if (!obj->isMoving) //WASDが押されていないとき
    {
        if (GameLib::input::STATE(0) & GameLib::input::PAD_UP) { obj->direction.y = -PLAYER_SPEED; obj->isMoving = true; }
        if (GameLib::input::STATE(0) & GameLib::input::PAD_DOWN) { obj->direction.y = PLAYER_SPEED; obj->isMoving = true;}
        if (GameLib::input::STATE(0) & GameLib::input::PAD_LEFT) { obj->direction.x = -PLAYER_SPEED; obj->isMoving = true; }
        if (GameLib::input::STATE(0) & GameLib::input::PAD_RIGHT) { obj->direction.x = PLAYER_SPEED; obj->isMoving = true; }
    }
    if (obj->isMoving)
    {
        obj->position += obj->direction;
    }
}
#endif
static bool isColliding = false;  // 衝突状態を管理

const int INPUT_COOLDOWN = 100; // 衝突後のクールタイム（フレーム）

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
void playerMove(OBJ2D* obj)
{
    static int inputCooldown = 0;

    if (inputCooldown > 0)
    {
        inputCooldown--;
        return;
    }

    if (!(PlayerManager::getInstance().isMoving() || PlayerManager_sd::getInstance().isMoving()))
    {
        bool up = GameLib::input::STATE(0) & GameLib::input::PAD_UP;
        bool down = GameLib::input::STATE(0) & GameLib::input::PAD_DOWN;
        bool left = GameLib::input::STATE(0) & GameLib::input::PAD_LEFT;
        bool right = GameLib::input::STATE(0) & GameLib::input::PAD_RIGHT;

        int keyCount = up + down + left + right;

        if (keyCount == 1)
        {
            if (up) { obj->sprData = &P_Up;    obj->direction.y = -PLAYER_SPEED; }
            if (down) { obj->sprData = &P_Down;  obj->direction.y = PLAYER_SPEED; }
            if (left) { obj->sprData = &P_Left;  obj->direction.x = -PLAYER_SPEED; }
            if (right) { obj->sprData = &P_Right; obj->direction.x = PLAYER_SPEED; }


            PlayerManager::getInstance().clearHit();
            PlayerManager_sd::getInstance().clearHit();


            obj->isMoving = true;
        }
    }

    // 位置更新は削除する！
    // obj->position += obj->direction; ← これが原因でめり込み・ズレが起きてる
}

void ssPlayerMove(OBJ2D* obj) //ステージセレクトシーンでの動き
{ 
    bool left = GameLib::input::STATE(0) & GameLib::input::PAD_LEFT;
    bool right = GameLib::input::STATE(0) & GameLib::input::PAD_RIGHT;

    int keyCount = left + right;

    if (keyCount == 1)
    {
        if (!(stage_number == 0)) {
            if (GameLib::input::STATE(0) & GameLib::input::PAD_LEFT) {
                obj->sprData = &P_Left; obj->state = 1;
            }
        }
        if (GameLib::input::STATE(0) & GameLib::input::PAD_RIGHT) {
            obj->sprData = &P_Right; obj->state = 1;
        }
    }
}


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
            obj->hSize = { 64 / 2,64 / 2 };
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
            if (stage_number == 0)
            {
                // ランダムカラー
                if (obj->timer % 10 == 0)
                {
                    obj->color = {
                        static_cast<float>(rand()) / RAND_MAX,
                        static_cast<float>(rand()) / RAND_MAX,
                        static_cast<float>(rand()) / RAND_MAX,
                        1.0f
                    };
                }

                obj->sprData = &sprPlayer;

                obj->timer++;
            }

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
            obj->position = { 660,360 };
            obj->hSize = { 12 / 2,12 / 2 };
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
        break;
    }
}


void direction_reset(OBJ2D* obj)
{
    obj->isMoving = false;
    obj->sprData = &sprPlayer;
    obj->direction = { 0,0 };
   // obj->position = { 64,64 };
}

void goal_moving(OBJ2D* obj)
{
    obj->isMoving = false;

    obj->direction = { 0,0 };

    int frame = (obj->timer / 5);
    //ここにアニメーションをいれるんだよ

    if (frame > 7)
    {
        obj->sprData = &PlayerGoal[7];
    }
    else
    {
        obj->sprData = &PlayerGoal[frame];
    }
}


