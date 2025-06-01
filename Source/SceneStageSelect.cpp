
#include "SceneStageSelect.h"
#include "../GameLib/game_lib.h"
#include "WinMain.h"
#include "Audio.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Player.h" 

static constexpr int STAGE_MAX = 8 ; // 最大ステージ数

OBJ2D select_back;
int stage_number;

// キーが押されていたかどうか
bool wasAKeyPressed = false;
bool wasDKeyPressed = false;

// 長押し判定用のタイマー（ミリ秒 or フレーム数）
int AKeyHoldTimer = 0;
int DKeyHoldTimer = 0;

// ホールド時のインターバル
int holdInterval = 10;

void SceneSelect::init()
{
	timer = 0;
    stage_number = 1;

    select_back.position = { 0, 0 };
    select_back.sprData = &sprStageSelect;

    PlayerManager::getInstance().init();
}

void SceneSelect::deinit()
{

}

void SceneSelect::update()
{ 
    using namespace GameLib::input;
    // 現在のキーの状態を取得
    bool isAKeyPressed = (GetAsyncKeyState('A') & 0x8000) != 0;
    bool isDKeyPressed = (GetAsyncKeyState('D') & 0x8000) != 0;    

    // Aキーが押された瞬間を判定
    
    if (isAKeyPressed)
    {
        if (!wasAKeyPressed)
        {
            // 押された瞬間
            AudioManager::getInstance().playSound(L"selectSound", 0.1f, false);
            stage_number--;
            if (stage_number < 1) stage_number = 1;

            AKeyHoldTimer = 0; // タイマーリセット
        }
        else
        {
            // 長押し中
            AKeyHoldTimer++;
            if (AKeyHoldTimer >= holdInterval)
            {
                AudioManager::getInstance().playSound(L"selectSound", 0.1f, false);
                stage_number--;
                if (stage_number < 1) stage_number = 1;
                AKeyHoldTimer = 0; // タイマーリセットして連続反応させる
            }
        }
    }
    else
    {
        AKeyHoldTimer = 0; // 離したらタイマーリセット
    }

    // Dキーが押された瞬間を判定
    if (isDKeyPressed)
    {
        if (!wasDKeyPressed)
        {
            AudioManager::getInstance().playSound(L"selectSound", 0.1f, false);
            stage_number++;
            if (stage_number > STAGE_MAX) stage_number = STAGE_MAX;

            DKeyHoldTimer = 0;
        }
        else
        {
            DKeyHoldTimer++;
            if (DKeyHoldTimer >= holdInterval)
            {
                AudioManager::getInstance().playSound(L"selectSound", 0.1f, false);
                stage_number++;
                if (stage_number > STAGE_MAX) stage_number = STAGE_MAX;
                DKeyHoldTimer = 0;
            }
        }
    }
    else
    {
        DKeyHoldTimer = 0;
    }

    // 現在の状態を次のフレームのために保存
    wasAKeyPressed = isAKeyPressed;
    wasDKeyPressed = isDKeyPressed;
    if (GameLib::input::TRG(0)& GameLib::input::PAD_START)
    {
        setScene(SCENE::GAME);
    }

    PlayerManager::getInstance().update();

    timer++;
}

void SceneSelect::draw()
{
    GameLib::clear(0, 0, 0);

    select_back.draw();

    PlayerManager::getInstance().draw();
}

