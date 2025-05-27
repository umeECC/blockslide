#include "SceneEnd.h"
#include "../GameLib/game_lib.h"
#include"../GameLib/DirectXTK-master/Inc/Audio.h"
#include "WinMain.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Audio.h"

VECTOR2 pos2;

OBJ2D end_back;

void SceneEnd::init()
{
    timer = 0;
    pos2 = { 90,250 };

    // テクスチャのロード
    GameLib::texture::load(loadTexture);

    end_back.position = { 0, 0 };
    end_back.sprData = &sprEnd;

    // オーディオエンジンの初期化
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
    
    if (TRG(0) & PAD_START)
    {
        AudioManager::getInstance().playSound(L"btnSound", 0.5f, false);
        setScene(SCENE::GAME);
    }    

    AudioManager::getInstance().update();

    timer++;
}

void SceneEnd::draw()
{
    GameLib::clear(0, 0, 0);
    end_back.draw();
}
