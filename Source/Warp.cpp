#include "Warp.h"
#include "SpriteData.h"



void set_warp(OBJ2D* obj)
{
	switch (obj->state)
	{
	case 0:
		//当たり判定の設定
		obj->hSize = { 32, 32 };
		obj->judge = JUDGE_ALL;

		//各種データ
		obj->sprData = &sprWarp;

		obj->state++;
		[[fallthrough]];
	case 1:
		//// 衝突判定チェック
		//if (OBJ2DManager::checkhit(obj, player)) // 衝突していたら
		//{
		//	// ワープ先座標
		//	player->pos.x = 100; // 任意のX座標
		//	player->pos.y = 200; // 任意のY座標
		//}

		break;
	}
}