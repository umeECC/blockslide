#include "SceneClear.h"
#include "../GameLib/game_lib.h"
#include "WinMain.h"
#include "Audio.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Player.h" 

//void setScore(OBJ2D* obj);

OBJ2D score;
int Score;

void SceneClear::init()
{
    timer = 0;

    Score = 0;
    score.position = { 1000,300 };
    score.scale = { 2,2 };
    //score.mover = setScore;
    for (auto& player : PlayerManager::getInstance())
    {
        Score += player.score;
    }

    AudioManager::getInstance().init();
    AudioManager::getInstance().loadSound(L"clearSound", L"./Data/Sounds/GameClear.wav");
    AudioManager::getInstance().loadSound(L"clearMusic", L"./Data/Musics/418_BPM168.wav");
    AudioManager::getInstance().playSound(L"clearSound", 0.8f, false);
}

void SceneClear::deinit()
{
    AudioManager::getInstance().stopSound(L"clearMusic");
}

void SceneClear::update()
{
    score.update();

    if (!AudioManager::getInstance().isPlaying(L"clearSound") && !AudioManager::getInstance().isPlaying(L"clearMusic"))
    {
        AudioManager::getInstance().playSound(L"clearMusic", 0.5f, true);
    }
    if (timer > 0x40 && GameLib::input::TRG(0))
    {

        setScene(SCENE::TITLE);
    }
    AudioManager::getInstance().update();

    timer++;
}

void SceneClear::draw()
{
    GameLib::clear(0, 0, 0);

    std::string scoreText = std::to_string(Score);
    GameLib::font::textOut(3, scoreText, { 300, 300 }, { 10,10 },
        { 1, 1, 0, 1 }, GameLib::TEXT_ALIGN::MIDDLE_LEFT, 0.0f, false);

    score.draw();

    if (timer & 0x20)
    {
        GameLib::font::textOut(4, "Push spase key", { 640, 540 }, { 2, 2 },
            { 1, 1, 0, 1 }, GameLib::TEXT_ALIGN::MIDDLE, 0.0f, false);
    }
}

