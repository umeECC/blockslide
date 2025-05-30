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


void Stage::init()
{
    timer = 0;
    pScript = stage1Script;


    // 背景初期設定
    BackManager::getInstance().init();

    // プレイヤー初期設定
    PlayerManager::getInstance().init();

    PlayerManager_sd::getInstance().init();

    //オブジェクト初期設定
    WallManager::getInstance().init();
    GoalManager::getInstance().init();

    // エフェクト初期設定
    EffectManager::getInstance().init();

    // UI初期設定


    // オーディオエンジンの初期化
    if (!AudioManager::getInstance().isPlaying(L"btnSound"))
    {
        AudioManager::getInstance().init();
    }
    AudioManager::getInstance().loadSound(L"gameMusic", L"./Data/Musics/y015.wav");
    AudioManager::getInstance().playSound(L"gameMusic", 0.8f, true);

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



    // UI描画

}