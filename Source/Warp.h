#pragma once
#include "Obj2d.h"
#include "Template.h"

class WarpManager :public OBJ2DManager, public Singleton<WarpManager>
{
private:
	static constexpr int OBJ_MAX = 81;
	OBJ2D objWrap[OBJ_MAX];

public:
	OBJ2D* begin() override { return &objWrap[0]; }
	OBJ2D* end() override { return &objWrap[OBJ_MAX]; }

	//void init() override;

};

//プロトタイプ宣言
void set_warp(OBJ2D* obj);  //壁
