#include "Player.h"
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
    searchSet(playerUpdate, { 32 + 64 * 10, 32 + 64 * 9 });////////
    searchSet(playerUpdate, { 32 + 64 * 9, 32 + 64 * 5 });
}

//-----------------------------------------------------------------------------------
//player

#if fasel
void playerMove(OBJ2D* obj)
{
    if (!obj->isMoving) //WASD��������Ă��Ȃ��Ƃ�
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
static bool isColliding = false;  // �Փˏ�Ԃ��Ǘ�

const int INPUT_COOLDOWN = 100; // �Փˌ�̃N�[���^�C���i�t���[���j


//-----------------------------------------------------------------------------------
void playerMove(OBJ2D* obj)
{

    static int inputCooldown = 0;

    // �N�[���^�C�����͑�����󂯕t���Ȃ�
    if (inputCooldown > 0)
    {
        inputCooldown--;
        return;
    }

    //if (!obj->isMoving) //WASD��������Ă��Ȃ��Ƃ�
    if (!obj->isMoving) //WASD��������Ă��Ȃ��Ƃ�
    {
        bool up = GameLib::input::STATE(0) & GameLib::input::PAD_UP;
        bool down = GameLib::input::STATE(0) & GameLib::input::PAD_DOWN;
        bool left = GameLib::input::STATE(0) & GameLib::input::PAD_LEFT;
        bool right = GameLib::input::STATE(0) & GameLib::input::PAD_RIGHT;

        int keyCount = up + down + left + right;

        if (keyCount == 1) //�u1����������Ă���ꍇ�v�Ɍ���
        {
            if (up){ obj->sprData = &P_Up; obj->direction.y = -PLAYER_SPEED; }
            if (down){ obj->sprData = &P_Down; obj->direction.y = PLAYER_SPEED; }
            if (left){ obj->sprData = &P_Left; obj->direction.x = -PLAYER_SPEED; }
            if (right){ obj->sprData = &P_Right; obj->direction.x = PLAYER_SPEED; }

            obj->isMoving = true;

        }
    }
    if (obj->isMoving)
    {
        obj->position += obj->direction;
    }

    //---------------------------------------------------------------
    //�J���p
    //---------------------------------------------------------------

    if (GameLib::input::STATE(0) & GameLib::input::PAD_START)
    {
        direction_reset(obj);
    }

    //---------------------------------------------------------------
}

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
        obj->position = { 660,360 };
        obj->hSize = { 32 / 2,32 / 2 };
        //obj->judge = JUDGE_ALL;
        obj->state++;
        [[fallthrough]];
    case 1:
        // �v���C���[�ړ�
        playerMove(obj);

        // �ړ��͈̓`�F�b�N
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
   // obj->position = { 64,64 };
}
