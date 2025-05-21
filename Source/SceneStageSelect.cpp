#include "SceneStageSelect.h"
#include "../GameLib/game_lib.h"
#include "WinMain.h"
#include "Audio.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Player.h" 


OBJ2D select_back;

void SceneSelect::init()
{
	timer = 0;

    select_back.position = { 0, 0 };
    select_back.sprData = &sprStageSelect;
}

void SceneSelect::deinit()
{

}

void SceneSelect::update()
{ 
    if (timer > 0x40 && GameLib::input::TRG(0)& GameLib::input::PAD_START)
    {
        setScene(SCENE::GAME);
    }
    timer++;
}

void SceneSelect::draw()
{
    GameLib::clear(0, 0, 0);

    select_back.draw();
}