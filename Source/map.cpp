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
#include "Statge1.h"

using namespace GameLib;
int mapData[MapManager::MAP_HEIGHT][MapManager::MAP_WIDTH] = {0};
int gimickMap[MapManager::MAP_HEIGHT][MapManager::MAP_WIDTH];

int CurrentNumber;

void MapManager::loadStage(int newMapData[MAP_HEIGHT][MAP_WIDTH], int newGimickMap[MAP_HEIGHT][MAP_WIDTH]) {
    // mapDataをコピー
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            mapData[y][x] = newMapData[y][x];
        }
    }

    // gimickMapをコピー
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            gimickMap[y][x] = newGimickMap[y][x];
        }
    }
}
void MapManager::switchToStage(int stageNumber) {
    CurrentNumber = stageNumber;
    switch (stageNumber) {
        //実験用マップ  これをチュートリアル２のマップにする

        //ステージ１－〇
    case 0: 
        loadStage(mapData11, gimickMap11);
        break;
    }
}
void MapManager::init() {
    // マップチップの読み込み   
    block = sprite_load(L"./Data/Images/wall.png");
    ugoku = sprite_load(L"./Data/Images/ugoku.png");
    hako = sprite_load(L"./Data/Images/hako.png");
}

void MapManager::deinit() {
    // マップチップスプライトの解放
    safe_delete(block);
    safe_delete(ugoku);
    // マップデータの初期化（デフォルトの値を設定）
    memset(mapData, 0, sizeof(mapData));  // 0 で初期化 (空のマップ)
    memset(gimickMap, 0, sizeof(gimickMap));  // ギミックマップも初期化
}

void MapManager::draw() {
    // マップチップの描画
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            int tile = mapData[y][x];


            // マップの座標をピクセル座標に変換する（例：64x64サイズのタイル）
            int pixelX = x * 64;
            int pixelY = y * 64;

            // マップチップを描画
            switch (tile)
            {
            case 0:
                break;                                            // 空白: 何も描画しない 
            case 1:                                                  // dirtのマップチップを描画     
                sprite_render(block, pixelX, pixelY, 1,1);
                break;
            case 2:
                sprite_render(ugoku, pixelX, pixelY, 1, 1);
                break;
            case 3:
                sprite_render(hako, pixelX, pixelY, 1, 1);
                break;
            }

        }
    }
}




