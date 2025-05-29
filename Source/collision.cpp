//#include "all.h"
////#include "Gimmick.h"
//#include <algorithm>  // std::find
//#include"map.h"
////using namespace MapManager;
//
//// 当たり判定があり処理を実行するマップチップ
//const int collisionTiles[] = { 1,2,3 };
//
//// 当たり判定なしで処理を実行するマップチップ
//const int gimmickTiles[] = { 9, 10, 11, 12, 13, 14, 15,16,17,18,19,21 }; // ギミックのIDをここで指定
//
//// プレイヤーの当たり判定用の幅と高さ
//const float playerWidth = 64.0f;  // プレイヤーの幅
//const float playerHeight = 64.0f; // プレイヤーの高さ
//
//const int stepsize = 64;
//
//bool checkCollision(float x, float y) {
//    bool isCollision = false; // 当たり判定のフラグ
//
//
//    // プレイヤーが占める領域の左上と右下の座標を求める
//    int left = (int)(x / stepsize);
//    int top = (int)(y / stepsize);
//    int right = (int)((x + playerWidth) / stepsize);
//    int bottom = (int)((y + playerHeight) / stepsize);
//
//    // マップの範囲外の場合はチェックしない
//    if (left < 0 || right >= MapManager::MAP_WIDTH || top < 0 || bottom >= MapManager::MAP_HEIGHT) {
//        return false; // 範囲外は無視
//    }
//
//    for (int tileY = top; tileY <= bottom; tileY++) {
//        for (int tileX = left; tileX <= right; tileX++) {
//            /*int tile = mapData[tileY][tileX];
//            int gimmickTile = MapManager::gimickMap[tileY][tileX];*/
//
//
//
//            // 衝突タイルの処理
//            //if (std::find(std::begin(collisionTiles), std::end(collisionTiles), tile) != std::end(collisionTiles)) {
//            //    isCollision = true;
//
//            //    if (y + playerHeight > tileY * stepsize && y + playerHeight <= (tileY + 1) * stepsize) {
//            //        //isGrounded = true; // プレイヤーの下端がタイルの範囲内にある場合
//            //    }
//            //}
//            ////if (gimmickTile == 16 || gimmickTile == 17 || gimmickTile == 18) {
//            //    isCollision = true;
//            //    if (y + playerHeight > tileY * stepsize && y + playerHeight <= (tileY + 1) * stepsize) {
//            //        isGrounded = true; // プレイヤーの下端がタイルの範囲内にある場合
//            //    }
//            //}
//            // ギミックタイルの処理
//            //if (std::find(std::begin(gimmickTiles), std::end(gimmickTiles), gimmickTile) != std::end(gimmickTiles)) {
//            //    //handleGimmick(gimmickTile, tileX, tileY, x, y, isCollision, bottom);
//
//            //}
//
//            //debug::setString("player.speed.y : %f", playerSpeedY);
//
//
//        }
//    }
//
//
//    //return isCollision; // 衝突判定の結果を返す
//}