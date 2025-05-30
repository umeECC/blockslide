#include "Toge.h"
#include "Spritedata.h"


//ゴールの設置
void set_Toge(OBJ2D* obj)
{
	switch (obj->state)
	{
	case 0:
		//当たり判定の設定
		obj->hSize = { 64 / 2, 64 / 2 };
		obj->judge = JUDGE_ALL;

		//各種データ
		obj->sprData = &sprToge;

		obj->state++;
		[[fallthrough]];
	case 1:
		break;
	}
}

