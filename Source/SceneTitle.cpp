#include "SceneTitle.h"
#include "../GameLib/game_lib.h"
#include"../GameLib/DirectXTK-master/Inc/Audio.h"
#include "WinMain.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Audio.h"
#include "Player.h"

//int Selpos;
VECTOR2 pos;

OBJ2D title_back;
OBJ2D push_space;

void SceneTitle::init()
{
    timer = 0;
    //Selpos = 0;
    pos = { 90,250 };

    // �e�N�X�`���̃��[�h
    GameLib::texture::load(loadTexture);

    title_back.position = { 0, 0 };
    title_back.sprData = &sprTitle;

    push_space.position = { SCREEN_WIDTH / 2 + 10, 600 };
    push_space.sprData = &sprPush;

    PlayerManager::getInstance().init();

    // �I�[�f�B�I�G���W���̏�����
    AudioManager::getInstance().init();
    AudioManager::getInstance().loadSound(L"titleMusic", L"./Data/Musics/y014.wav");
    AudioManager::getInstance().loadSound(L"btnSound", L"./Data/Sounds/btn.wav");
    AudioManager::getInstance().loadSound(L"selectSound", L"./Data/Sounds/select.wav");
    AudioManager::getInstance().playSound(L"titleMusic", 0.8f, true);

}

void SceneTitle::deinit()
{
    AudioManager::getInstance().stopSound(L"titleMusic");
}

void SceneTitle::update()
{
    using namespace GameLib::input;
    /*// ���݂̃L�[�̏�Ԃ��擾
    bool isWKeyPressed = (GetAsyncKeyState('W') & 0x8000) != 0;
    bool isSKeyPressed = (GetAsyncKeyState('S') & 0x8000) != 0;

    // W�L�[�������ꂽ�u�Ԃ𔻒�
    if (isWKeyPressed && !wasWKeyPressed)
    {
        AudioManager::getInstance().playSound(L"selectSound", 0.5f, false);
        Selpos--;
        if (Selpos < 0) Selpos = 1;
    }

    // S�L�[�������ꂽ�u�Ԃ𔻒�
    if (isSKeyPressed && !wasSKeyPressed)
    {
        AudioManager::getInstance().playSound(L"selectSound", 0.5f, false);
        Selpos++;
        if (Selpos >= 2) Selpos = 0;
    }

    // ���݂̏�Ԃ����̃t���[���̂��߂ɕۑ�
    wasWKeyPressed = isWKeyPressed;
    wasSKeyPressed = isSKeyPressed;*/

    /*switch (Selpos)
    {
    case 0:
        pos = { 90,440 };
        if (TRG(0) & PAD_START)
        {
            AudioManager::getInstance().playSound(L"btnSound", 0.5f, false);
            setScene(SCENE::GAME);
        }
        break;
    }*/
    if (TRG(0) & PAD_START)
    {
        AudioManager::getInstance().playSound(L"btnSound", 0.5f, false);
        setScene(SCENE::STAGESEL);
    }

    PlayerManager::getInstance().update();

    AudioManager::getInstance().update();

    timer++;
}

void SceneTitle::draw()
{
    GameLib::clear(0, 0, 0);

    //�w�i�`��
    title_back.draw();

    /*GameLib::font::textOut(4, "C++ Shooting", { 640, 360 }, { 5, 5 },
       { 1, 1, 1, 1 }, GameLib::TEXT_ALIGN::MIDDLE);

    GameLib::primitive::rect({ pos }, { 600, 120 }, { 0, 0 }, 0, { 1, 0, 0, 0.7f });
    */
    /*switch (Selpos)
    {
    case 0:
        if (timer & 0x20)
        {
            gamelib::font::textout(4, "game start", { 390,500 }, { 3, 3 },
                { 1, 1, 0, 1 }, gamelib::text_align::middle);
        }

        gamelib::font::textout(4, "tutorial", { 900,610 }, { 3, 3 },
            { 0, 1, 0, 1 }, gamelib::text_align::middle);
        

        break;
    case 1:
        GameLib::font::textOut(4, "Game Start", { 390,500 }, { 3, 3 },
            { 1, 1, 0, 1 }, GameLib::TEXT_ALIGN::MIDDLE);

        if (timer & 0x20)
        {
            GameLib::font::textOut(4, "Tutorial", { 900,610 }, { 3, 3 },
                { 0, 1, 0, 1 }, GameLib::TEXT_ALIGN::MIDDLE);
        }
        title_back2.draw();

        break;
    }*/

    if (timer > 220) //�X�y�[�X�L�[������!!���Ă��
    {
        if (timer / 2 & 0x20)
        {
            push_space.draw();
        }
    }

    PlayerManager::getInstance().draw();
}
