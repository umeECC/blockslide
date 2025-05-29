#include "SceneTitle.h"
#include "../GameLib/game_lib.h"
#include"../GameLib/DirectXTK-master/Inc/Audio.h"
#include "WinMain.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Audio.h"
#include "Player.h"

VECTOR2 pos;

OBJ2D title_back;
OBJ2D push_space;

void SceneTitle::init()
{
    timer = 0;
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

    if (timer > 220) //�X�y�[�X�L�[������!!���Ă��
    {
        if (timer / 2 & 0x20)
        {
            push_space.draw();
        }
    }

    PlayerManager::getInstance().draw();
}
