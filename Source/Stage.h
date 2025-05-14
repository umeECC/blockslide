#pragma once
#include "Obj2d.h"
#include "Template.h"

// 敵キャラ発生データ（いずれステージスクリプトになる）
struct StageScript
{
	int				time;		// イベント発生時間
	OBJ2D::MOVER	mover;		// 移動処理
	VECTOR2			position;	// 座標
};

// スクリプトマクロ
#define SET_ENEMY(time,x,y,mover)		{(time),(mover),{(x),(y)}}
#define SET_ITEM(time,x,y,mover)		{(time),(mover),{(x),(y)}}
#define SET_END						{0,0,{0,0}}

// Stageクラス
class Stage : public Singleton<Stage>
{
	int timer;
	StageScript* pScript;

public:
	void init();
	void update();
	void draw();
};

