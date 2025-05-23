#include "SceneGame.h"
#include "../GameLib/game_lib.h"
#include "WinMain.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Player.h"
#include "Stage.h"
#include "Audio.h"
#include "map.h"

// 定数宣言

// 変数宣言

// プロトタイプ宣言
void enemy(OBJ2D* obj);

void SceneGame::init()
{
    MapManager mapmanager;
     mapmanager.init();
    mapmanager.switchToStage(0);
    Stage::getInstance().init();
}

void SceneGame::deinit()
{
    AudioManager::getInstance().stopSound(L"gameMusic");
}

void SceneGame::update()
{
    Stage::getInstance().update();
    if (GameLib::input::STATE(0) & GameLib::input::PAD_SELECT)
    {
        setScene(SCENE::OVER);
    }
}

//敵(仮)
void enemy(OBJ2D* obj)
{
    //obj->position = { rand() % 879 + 209, rand() % 700 };
}

void SceneGame::draw()
{
   
    
    // 画面をクリア
    GameLib::clear(0, 0, 0);

    Stage::getInstance().draw();

    //MapManager mapmanager;
    //mapmanager.draw();

    
}
