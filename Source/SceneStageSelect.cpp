
#include "SceneStageSelect.h"
#include "../GameLib/game_lib.h"
#include "WinMain.h"
#include "Audio.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Player.h" 

static constexpr int STAGE_MAX = 8 ; // �ő�X�e�[�W��

OBJ2D select_back;
int stage_number;

// �L�[��������Ă������ǂ���
bool wasAKeyPressed = false;
bool wasDKeyPressed = false;

// ����������p�̃^�C�}�[�i�~���b or �t���[�����j
int AKeyHoldTimer = 0;
int DKeyHoldTimer = 0;

// �z�[���h���̃C���^�[�o��
int holdInterval = 10;

void SceneSelect::init()
{
	timer = 0;
    stage_number = 1;

    select_back.position = { 0, 0 };
    select_back.sprData = &sprStageSelect;

    PlayerManager::getInstance().init();
}

void SceneSelect::deinit()
{

}

void SceneSelect::update()
{ 
    using namespace GameLib::input;
    // ���݂̃L�[�̏�Ԃ��擾
    bool isAKeyPressed = (GetAsyncKeyState('A') & 0x8000) != 0;
    bool isDKeyPressed = (GetAsyncKeyState('D') & 0x8000) != 0;    

    // A�L�[�������ꂽ�u�Ԃ𔻒�
    
    if (isAKeyPressed)
    {
        if (!wasAKeyPressed)
        {
            // �����ꂽ�u��
            AudioManager::getInstance().playSound(L"selectSound", 0.1f, false);
            stage_number--;
            if (stage_number < 1) stage_number = 1;

            AKeyHoldTimer = 0; // �^�C�}�[���Z�b�g
        }
        else
        {
            // ��������
            AKeyHoldTimer++;
            if (AKeyHoldTimer >= holdInterval)
            {
                AudioManager::getInstance().playSound(L"selectSound", 0.1f, false);
                stage_number--;
                if (stage_number < 1) stage_number = 1;
                AKeyHoldTimer = 0; // �^�C�}�[���Z�b�g���ĘA������������
            }
        }
    }
    else
    {
        AKeyHoldTimer = 0; // ��������^�C�}�[���Z�b�g
    }

    // D�L�[�������ꂽ�u�Ԃ𔻒�
    if (isDKeyPressed)
    {
        if (!wasDKeyPressed)
        {
            AudioManager::getInstance().playSound(L"selectSound", 0.1f, false);
            stage_number++;
            if (stage_number > STAGE_MAX) stage_number = STAGE_MAX;

            DKeyHoldTimer = 0;
        }
        else
        {
            DKeyHoldTimer++;
            if (DKeyHoldTimer >= holdInterval)
            {
                AudioManager::getInstance().playSound(L"selectSound", 0.1f, false);
                stage_number++;
                if (stage_number > STAGE_MAX) stage_number = STAGE_MAX;
                DKeyHoldTimer = 0;
            }
        }
    }
    else
    {
        DKeyHoldTimer = 0;
    }

    // ���݂̏�Ԃ����̃t���[���̂��߂ɕۑ�
    wasAKeyPressed = isAKeyPressed;
    wasDKeyPressed = isDKeyPressed;
    if (GameLib::input::TRG(0)& GameLib::input::PAD_START)
    {
        setScene(SCENE::GAME);
    }

    PlayerManager::getInstance().update();

    timer++;
}

void SceneSelect::draw()
{
    GameLib::clear(0, 0, 0);

    select_back.draw();

    PlayerManager::getInstance().draw();
}

