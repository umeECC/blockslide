#include "Wall.h"
#include "Spritedata.h"


//壁の設置
void set_wall(OBJ2D* obj)
{
	switch (obj->state)
	{
	case 0:
		//当たり判定の設定
		obj->hSize = { 32, 32 };
		obj->judge = JUDGE_ALL;

		//各種データ
		obj->sprData = &sprWall;

		obj->state++;
		[[fallthrough]];
	case 1:
		break;
	}
}
void set_hako(OBJ2D* obj)
{
	switch (obj->state)
	{
	case 0:
		//当たり判定の設定
		obj->hSize = { 32, 32 };
		obj->judge = JUDGE_ALL;

		//各種データ
		obj->sprData = &sprHako;

		obj->state++;
		[[fallthrough]];
	case 1:
		break;
	}
}