#include "SceneClear.h"
#include "../GameLib/game_lib.h"
#include "WinMain.h"
#include "Audio.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Player.h" 
#include "Player_sd.h"

OBJ2D clear;
OBJ2D clear_yaji;
int ClearSelect;

bool wasWKeyPressed_c = false;
bool wasSKeyPressed_c = false;

// ����������p�̃^�C�}�[�i�~���b or �t���[�����j
int WKeyHoldTimer_c = 0;
int SKeyHoldTimer_c = 0;

// �z�[���h���̃C���^�[�o��
int holdInterval_c = 10;

void SceneClear::init()
{
    timer = 0;

    ClearSelect = 0;
    clear.sprData = &sprClear;
    clear.position = { 0,0 };
    clear_yaji.sprData = &sprYaji;

    PlayerManager::getInstance().init();
    
    AudioManager::getInstance().init();
    AudioManager::getInstance().loadSound(L"clearSound", L"./Data/Sounds/GameClear.wav");
    AudioManager::getInstance().loadSound(L"clearMusic", L"./Data/Musics/418_BPM168.wav");
    AudioManager::getInstance().playSound(L"clearSound", 1.0f, false);
    AudioManager::getInstance().loadSound(L"btnSound", L"./Data/Sounds/btn.wav");
}

void SceneClear::deinit()
{
    AudioManager::getInstance().stopSound(L"clearMusic");
}

void SceneClear::update()
{
    if (!AudioManager::getInstance().isPlaying(L"clearSound") && !AudioManager::getInstance().isPlaying(L"clearMusic"))
    {
        AudioManager::getInstance().playSound(L"clearMusic", 0.1f, true);
    }

    using namespace GameLib::input;
    // ���݂̃L�[�̏�Ԃ��擾
    bool isWKeyPressed = (GetAsyncKeyState('W') & 0x8000) != 0;
    bool isSKeyPressed = (GetAsyncKeyState('S') & 0x8000) != 0;

    // A�L�[�������ꂽ�u�Ԃ𔻒�

    if (isWKeyPressed)
    {
        if (!wasWKeyPressed_c)
        {
            // �����ꂽ�u��
            ClearSelect--;
            if (ClearSelect < 0) ClearSelect = 0;

            WKeyHoldTimer_c = 0; // �^�C�}�[���Z�b�g
        }
        else
        {
            // ��������
            WKeyHoldTimer_c++;
            if (WKeyHoldTimer_c >= holdInterval_c)
            {
                AudioManager::getInstance().playSound(L"selectSound", 0.1f, false);
                ClearSelect--;
                if (ClearSelect < 0) ClearSelect = 0;
                WKeyHoldTimer_c = 0; // �^�C�}�[���Z�b�g���ĘA������������
            }
        }
    }
    else
    {
        WKeyHoldTimer_c = 0; // ��������^�C�}�[���Z�b�g
    }

    // D�L�[�������ꂽ�u�Ԃ𔻒�
    if (isSKeyPressed)
    {
        if (!wasSKeyPressed_c)
        {
            ClearSelect++;
            if (ClearSelect > 2) ClearSelect = 2;
            SKeyHoldTimer_c = 0;
        }
        else
        {
            SKeyHoldTimer_c++;
            if (SKeyHoldTimer_c >= holdInterval_c)
            {
                ClearSelect++;
                if (ClearSelect > 2) ClearSelect = 2;
                SKeyHoldTimer_c = 0;
            }
        }
    }
    else
    {
        SKeyHoldTimer_c = 0;
    }
       
    
    // ���݂̏�Ԃ����̃t���[���̂��߂ɕۑ�
    wasWKeyPressed_c = isWKeyPressed;
    wasSKeyPressed_c = isSKeyPressed;

    if (GameLib::input::TRG(0) & GameLib::input::PAD_START) {

        switch (ClearSelect)
        {
        case 0:
            setScene(SCENE::STAGESEL);
            break;
        case 1:
            setScene(SCENE::GAME);
            break;
        case 2:
            setScene(SCENE::TITLE);
            break;
        }
    }

    switch (ClearSelect)
    {
    case 0:
        clear_yaji.position = { 390,350 };
        break;
    case 1:
        clear_yaji.position = { 390,530 };
        break;
    case 2:
        clear_yaji.position = { 1100,650 };
        break;
    }

    PlayerManager::getInstance().update();

    AudioManager::getInstance().update();

    timer++;
}

void SceneClear::draw()
{
    GameLib::clear(0, 0, 0);

    clear.draw();

    clear_yaji.draw();

    PlayerManager::getInstance().draw();
}

