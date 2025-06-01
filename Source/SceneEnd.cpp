#include "SceneEnd.h"
#include "../GameLib/game_lib.h"
#include"../GameLib/DirectXTK-master/Inc/Audio.h"
#include "WinMain.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Audio.h"

VECTOR2 pos2;
OBJ2D over_yaji;
int OverSelect;
bool wasWKeyPressed = false;
bool wasSKeyPressed = false;

OBJ2D end_back;

void SceneEnd::init()
{
    timer = 0;
    pos2 = { 90,250 };

    // �e�N�X�`���̃��[�h
    GameLib::texture::load(loadTexture);

    end_back.position = { 0, 0 };
    end_back.sprData = &sprEnd;

    over_yaji.sprData = &sprYaji;

    // �I�[�f�B�I�G���W���̏�����
    AudioManager::getInstance().init();
    AudioManager::getInstance().loadSound(L"MissMusic", L"./Data/Musics/make.wav");
    
    AudioManager::getInstance().playSound(L"MissMusic", 0.1f, true);

}

void SceneEnd::deinit()
{
    AudioManager::getInstance().stopSound(L"MissMusic");
}

void SceneEnd::update()
{
    using namespace GameLib::input;
    bool isWKeyPressed = (GetAsyncKeyState('W') & 0x8000) != 0;
    bool isSKeyPressed = (GetAsyncKeyState('S') & 0x8000) != 0;

    // A�L�[�������ꂽ�u�Ԃ𔻒�

    if (isWKeyPressed)
    {
        if (!wasWKeyPressed)
        {
            // �����ꂽ�u��
            OverSelect--;
            if (OverSelect < 0) OverSelect = 0;
        }
    }

    // D�L�[�������ꂽ�u�Ԃ𔻒�
    if (isSKeyPressed)
    {
        if (!wasSKeyPressed)
        {
            OverSelect++;
            if (OverSelect > 2) OverSelect = 2;
           
        }
        
    }

    // ���݂̏�Ԃ����̃t���[���̂��߂ɕۑ�
    wasWKeyPressed = isWKeyPressed;
    wasSKeyPressed = isSKeyPressed;


    if (GameLib::input::TRG(0)& GameLib::input::PAD_START) {
        
        switch (OverSelect)
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


    switch (OverSelect)
    {
    case 0:
        over_yaji.position = { 390,420 };
        break;
    case 1:
        over_yaji.position = { 390,580 };
        break;
    case 2:
        over_yaji.position = { 1100,650 };
        break;
    }   

    AudioManager::getInstance().update();

    timer++;
}

void SceneEnd::draw()
{
    GameLib::clear(0, 0, 0);

    end_back.draw();

    over_yaji.draw();
}
