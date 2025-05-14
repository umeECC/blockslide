#include "SceneTuto.h"
#include "../GameLib/game_lib.h"
#include "WinMain.h"
#include "Obj2d.h"
#include "SpriteData.h"
#include "Audio.h"

OBJ2D tuto_back[7];


void SceneTuto::init()
{
    timer = 0;
    tutoState = 0;
    

    if (!AudioManager::getInstance().isPlaying(L"btnSound"))
    {
        AudioManager::getInstance().init();
    }
    AudioManager::getInstance().loadSound(L"tutoMusic", L"./Data/Musics/maou_bgm_cyber18.wav");
    AudioManager::getInstance().playSound(L"tutoMusic", 0.8f, true);
}

void SceneTuto::deinit()
{
    AudioManager::getInstance().stopSound(L"tutoMusic");
}

void SceneTuto::update()
{
    using namespace GameLib::input;
    
    if (TRG(0) & PAD_START)
    {
        switch (tutoState)
        {
        case 0: tutoState+=2; break;
        case 1: tutoState++; break;
        case 2: tutoState++; break;
        case 3: tutoState++; break;
        case 4: tutoState++; break;
        case 5: tutoState++;  break;
        case 6: setScene(SCENE::TITLE); break;
        }        
    }
    /*if (tutoState >= 6)
    {
        tutoState = 0;
    }*/
    AudioManager::getInstance().update();
    timer++;
}

void SceneTuto::draw()
{
    GameLib::clear(0, 0, 0);

    switch (tutoState)
    {
    case 0: tuto_back[0].draw(); break;
    case 1: tuto_back[1].draw(); break;
    case 2: tuto_back[2].draw(); break;
    case 3: tuto_back[3].draw(); break;
    case 4: tuto_back[4].draw(); break;
    case 5: tuto_back[5].draw(); break;
    case 6: tuto_back[6].draw(); break;
    }

    /*GameLib::font::textOut(4, "Tutorial", { 640, 360 }, { 5, 5 },
        { 1, 1, 1, 1 }, GameLib::TEXT_ALIGN::MIDDLE);

    if (timer & 0x20)
    {
        GameLib::font::textOut(4, "Push enter key", { 640, 540 }, { 2, 2 },
            { 1, 1, 0, 1 }, GameLib::TEXT_ALIGN::MIDDLE);
    }*/
}
