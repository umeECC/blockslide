#pragma once
#include "Obj2d.h"
#include "Template.h"

enum ScriptType
{
	TYPE_NONE = 0,
	TYPE_WALL,
	TYPE_GOAL,
	TYPE_WARP,
};

// 発生データ
struct StageScript
{
	int				time;		// イベント発生時間
	ScriptType		type;		// 種類
	OBJ2D::MOVER	mover;		// 移動処理
	VECTOR2			position;	// 座標
};

// スクリプトマクロ
#define SET_OBJ(time,x,y,mover,type)		{(time),(type),(mover),{(x),(y)}}
#define SET_END						{0,TYPE_NONE,0,{0,0}}

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
