#include "Player_sd.h"

#include "player.h"
#include "SpriteData.h"


static constexpr float PLAYER_SPEED = 10.0f;
static constexpr float PLAYER_LIMIT_L = 32;
static constexpr float PLAYER_LIMIT_R = 1280 - 32;
static constexpr float PLAYER_LIMIT_U = 32;
static constexpr float PLAYER_LIMIT_D = 720 - 32;


void PlayerManager_sd::init()
{
    OBJ2DManager::init();
    searchSet(player_sd_Update, { 64 + 64 * 9, 32 + 64 * 5 });
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
static bool isColliding = false;// �Փˏ�Ԃ��Ǘ�


void player_sd_Move(OBJ2D* obj)
{

    if (!(PlayerManager::getInstance().isMoving() || PlayerManager_sd::getInstance().isMoving())) //WASD��������Ă��Ȃ��Ƃ�
    {
        bool up = GameLib::input::STATE(0) & GameLib::input::PAD_UP;
        bool down = GameLib::input::STATE(0) & GameLib::input::PAD_DOWN;
        bool left = GameLib::input::STATE(0) & GameLib::input::PAD_LEFT;
        bool right = GameLib::input::STATE(0) & GameLib::input::PAD_RIGHT;

        int keyCount = up + down + left + right;


        if (keyCount == 1) //�u1����������Ă���ꍇ�v�Ɍ���
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
        obj->position = { 100,300 };
        obj->hSize = { 64 / 2,64 / 2 };
        obj->judge = JUDGE_ALL;
        obj->state++;
        [[fallthrough]];
    case 1:
        // �v���C���[�ړ�
        player_sd_Move(obj);

        // �ړ��͈̓`�F�b�N
        if (obj->position.x < PLAYER_LIMIT_L) { obj->position.x = PLAYER_LIMIT_L; direction_sd_reset(obj); }
        if (obj->position.x > PLAYER_LIMIT_R) { obj->position.x = PLAYER_LIMIT_R; direction_sd_reset(obj); }
        if (obj->position.y < PLAYER_LIMIT_U) { obj->position.y = PLAYER_LIMIT_U; direction_sd_reset(obj); }
        if (obj->position.y > PLAYER_LIMIT_D) { obj->position.y = PLAYER_LIMIT_D; direction_sd_reset(obj); }
        break;
    }
}


void direction_sd_reset(OBJ2D* obj)
{
    obj->isMoving = false;
    obj->sprData = &sprPlayer_sd;
    obj->direction = { 0,0 };
    //PlayerManager::getInstance().setIsPlayerSecondMove(false);
}
