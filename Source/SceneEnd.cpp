#include "SceneEnd.h"
#include "../GameLib/game_lib.h"
#include"../GameLib/DirectXTK-master/Inc/Audio.h"
#include "WinMain.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Audio.h"

int SOelpos;
VECTOR2 pos2;
bool wasWKeyPressed = false;
bool wasSKeyPressed = false;

OBJ2D end_back;
OBJ2D end_back2;

void SceneEnd::init()
{
    timer = 0;
    SOelpos = 0;
    pos2 = { 90,250 };

    // �e�N�X�`���̃��[�h
    GameLib::texture::load(loadTexture);

    end_back.position = { 0, 0 };
    end_back.sprData = &sprEnd;

    // �I�[�f�B�I�G���W���̏�����
    AudioManager::getInstance().init();
    AudioManager::getInstance().loadSound(L"titleMusic", L"./Data/Musics/y014.wav");
    AudioManager::getInstance().loadSound(L"btnSound", L"./Data/Sounds/btn.wav");
    AudioManager::getInstance().loadSound(L"selectSound", L"./Data/Sounds/select.wav");
    AudioManager::getInstance().playSound(L"titleMusic", 0.8f, true);

}

void SceneEnd::deinit()
{
    AudioManager::getInstance().stopSound(L"titleMusic");
}

void SceneEnd::update()
{
    using namespace GameLib::input;
    // ���݂̃L�[�̏�Ԃ��擾
    bool isWKeyPressed = (GetAsyncKeyState('W') & 0x8000) != 0;
    bool isSKeyPressed = (GetAsyncKeyState('S') & 0x8000) != 0;

    // W�L�[�������ꂽ�u�Ԃ𔻒�
    if (isWKeyPressed && !wasWKeyPressed)
    {
        AudioManager::getInstance().playSound(L"selectSound", 0.5f, false);
        SOelpos--;
        if (SOelpos < 0) SOelpos = 1;
    }

    // S�L�[�������ꂽ�u�Ԃ𔻒�
    if (isSKeyPressed && !wasSKeyPressed)
    {
        AudioManager::getInstance().playSound(L"selectSound", 0.5f, false);
        SOelpos++;
        if (SOelpos >= 2) SOelpos = 0;
    }

    // ���݂̏�Ԃ����̃t���[���̂��߂ɕۑ�
    wasWKeyPressed = isWKeyPressed;
    wasSKeyPressed = isSKeyPressed;

    switch (SOelpos)
    {
    case 0:
        pos2 = { 90,440 };
        if (TRG(0) & PAD_START)
        {
            AudioManager::getInstance().playSound(L"btnSound", 0.5f, false);
            setScene(SCENE::GAME);
        }
        break;
    }

    AudioManager::getInstance().update();

    timer++;
}

void SceneEnd::draw()
{
    GameLib::clear(0, 0, 0);


    switch (SOelpos)
    {
    case 0:

        end_back.draw();

        break;
    case 1:

        end_back2.draw();

        break;
    }
}
