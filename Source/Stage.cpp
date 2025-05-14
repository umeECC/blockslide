#include "Stage.h"
#include"Obj2d.h"
#include "Back.h"
#include "Player.h"
#include "Judge.h"
#include "Audio.h"
#include "Effect.h"
#include "SceneGame.h"
#include"map.h"
#include"Stage.h"
#include "map.h"

void Stage::init()
{
    timer = 0;
    //pScript = stageScript;

    // 背景初期設定
    BackManager::getInstance().init();

    // プレイヤー初期設定
    PlayerManager::getInstance().init();

    // マップ初期設定(map_init())
    MapManager::getInstance().init();
    MapManager::getInstance().switchToStage(0);

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
    // 敵出現
    /*while (pScript->mover &&    // 終了コードではなく
        timer == pScript->time) // 現在のタイマーがスクリプトのタイムであれば
    {
        ItemManager::getInstance().searchSet(pScript->mover, pScript->position);
        pScript++;
    }*/

    // 背景更新
    BackManager::getInstance().update();

    // プレイヤー更新
    PlayerManager::getInstance().update();

    // マップの更新
    
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

    // 敵キャラ描画
    
    // エフェクトの描画
    EffectManager::getInstance().draw();

    // アイテム描画
    
    // マップの描画
    MapManager::getInstance().draw();

    // プレイヤー描画
    PlayerManager::getInstance().draw();
    

    // UI描画
    
}
