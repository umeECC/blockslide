#include "SceneEnd.h"
#include "../GameLib/game_lib.h"
#include"../GameLib/DirectXTK-master/Inc/Audio.h"
#include "WinMain.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Audio.h"

VECTOR2 pos2;
bool wasWKeyPressed = false;
bool wasSKeyPressed = false;

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
    
    AudioManager::getInstance().update();

    //------------------------------------------------------------
    //仮置き
    if (GameLib::input::TRG(0) & GameLib::input::PAD_START)
    {
        setScene(SCENE::STAGESEL);
    }
    //------------------------------------------------------------


    timer++;
}

void SceneEnd::draw()
{
    GameLib::clear(0, 0, 0);

    end_back.draw();

}
