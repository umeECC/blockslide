#include "Stage.h"
#include "Back.h"
#include "Player.h"
#include "Player_sd.h"
#include "Judge.h"
#include "Audio.h"
#include "Effect.h"
#include "Wall.h"
#include "Goal.h"
#include "SceneGame.h"
#include "StageData_1.h"
#include "StageData_2.h"
#include "StageData_3.h"
#include "StageData_4.h"
#include "StageData_6.h"
#include "StageData_8.h"
#include "Toge.h"
#include "SceneStageSelect.h"
#include "StageData_5.h"

int goalCount;

void Stage::init()
{
    timer = 0;
    switch (stage_number)
    {
    case 1:
        goalCount = 1;
        pScript = stage1Script; break;
    case 2:
        goalCount = 1;
        pScript = stage2Script; break;
    case 3:
        goalCount = 1;
        pScript = stage3Script; break;
    case 4:
        goalCount = 1;
        pScript = stage4Script; break;

    case 5:
        goalCount = 3;
        pScript = stage5Script; break;
    case 6:
        goalCount = 2;
        pScript = stage6Script; break;
    case 8:
        goalCount = 2;
        pScript = stage8Script; break;
    }


    // 背景初期設定
    BackManager::getInstance().init();

    // プレイヤー初期設定
    PlayerManager::getInstance().init();

    PlayerManager_sd::getInstance().init();

    //オブジェクト初期設定
    WallManager::getInstance().init();
    GoalManager::getInstance().init();

    TogeManager::getInstance().init();
    // エフェクト初期設定
    EffectManager::getInstance().init();

    // UI初期設定


    // オーディオエンジンの初期化
    if (!AudioManager::getInstance().isPlaying(L"btnSound"))
    {
        AudioManager::getInstance().init();
    }
    AudioManager::getInstance().loadSound(L"gameMusic", L"./Data/Musics/y015.wav");
    AudioManager::getInstance().playSound(L"gameMusic", 1.0f, true);

}

void Stage::update()
{
    //オブジェクト出現


    while (pScript->mover &&    // 終了コードではなく
        timer == pScript->time) // 現在のタイマーがスクリプトのタイムであれば
    {
        switch (pScript->type) {
        case TYPE_WALL:
            WallManager::getInstance().searchSet(pScript->mover, pScript->position);
            break;
        case TYPE_GOAL:
            GoalManager::getInstance().searchSet(pScript->mover, pScript->position);
            break;
        }
        pScript++;
    }

    // 背景更新
    BackManager::getInstance().update();

    // プレイヤー更新
    PlayerManager::getInstance().update();

    PlayerManager_sd::getInstance().update();

    // オブジェクト更新
    WallManager::getInstance().update();
    GoalManager::getInstance().update();

    TogeManager::getInstance().update();
    // エフェクト更新
    EffectManager::getInstance().update();

    //爆発エフェ確認
    if (GetKeyState('O') < 0)
    {
        EffectManager::getInstance().searchSet(effectExplos, { 960,300 });
    }

    // UI更新


    // あたり判定
    judge();

    timer++;
}

void Stage::draw()
{
    // 背景描画
    BackManager::getInstance().draw();

    // オブジェクト描画
    GoalManager::getInstance().draw();

    // プレイヤー描画
    PlayerManager::getInstance().draw();

    PlayerManager_sd::getInstance().draw();
    // エフェクトの描画
    EffectManager::getInstance().draw();

    // アイテム描画


    //枠の描画
    WallManager::getInstance().draw();

    TogeManager::getInstance().draw();

    // UI描画

}