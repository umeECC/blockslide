#include "SceneGame.h"
#include "../GameLib/game_lib.h"
#include "WinMain.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Player.h"
#include "Player_sd.h"
#include "Stage.h"
#include "Audio.h"
#include "Wall.h"

// 定数宣言

// 変数宣言

// プロトタイプ宣言


void SceneGame::init()
{
    Stage::getInstance().init();
}

void SceneGame::deinit()
{
    AudioManager::getInstance().stopSound(L"gameMusic");
}

void SceneGame::update()
{
    Stage::getInstance().update();
    if (GameLib::input::TRG(0) & GameLib::input::PAD_SELECT)
    {
        setScene(SCENE::STAGESEL);
    }
    if ((GetAsyncKeyState('P') & 0x8000))
    {
        setScene(SCENE::CLEAR);
    }
}


void SceneGame::draw()
{
    // 画面をクリア
    GameLib::clear(0, 0, 0);

    Stage::getInstance().draw();

}