#pragma once
#include "Obj2d.h"
#include "Template.h"

class TogeManager :public OBJ2DManager, public Singleton<TogeManager>
{
private:
	static constexpr int OBJ_MAX = 10;
	OBJ2D objWork[OBJ_MAX];

public:
	OBJ2D* begin() override { return &objWork[0]; }
	OBJ2D* end() override { return &objWork[OBJ_MAX]; }

	//void init() override;

};

//プロトタイプ宣言
void set_Toge(OBJ2D* obj);  //ゴール
