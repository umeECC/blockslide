#include "SceneClear.h"
#include "../GameLib/game_lib.h"
#include "WinMain.h"
#include "Audio.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Player.h" 
#include "Player_sd.h"

OBJ2D clear;

void SceneClear::init()
{
    timer = 0;

    clear.sprData = &sprClear;
    clear.position = { 0,0 };

    PlayerManager::getInstance().init();
    
    AudioManager::getInstance().init();
    AudioManager::getInstance().loadSound(L"clearSound", L"./Data/Sounds/GameClear.wav");
    AudioManager::getInstance().loadSound(L"clearMusic", L"./Data/Musics/418_BPM168.wav");
    AudioManager::getInstance().playSound(L"clearSound", 0.1f, false);
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
        AudioManager::getInstance().playSound(L"clearMusic", 0.5f, true);
    }
    if (timer > 0x40 && GameLib::input::TRG(0))
    {

        setScene(SCENE::TITLE);

    }

    PlayerManager::getInstance().update();

    AudioManager::getInstance().update();

    timer++;
}

void SceneClear::draw()
{
    GameLib::clear(0, 0, 0);

    clear.draw();

    if (timer & 0x20)
    {
        GameLib::font::textOut(4, "Push spase key", { 640, 540 }, { 2, 2 },
            { 1, 1, 0, 1 }, GameLib::TEXT_ALIGN::MIDDLE, 0.0f, false);
    }

    PlayerManager::getInstance().draw();
}

