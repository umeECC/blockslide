#pragma once
#include "Obj2d.h"
#include "Template.h"

class WallManager :public OBJ2DManager, public Singleton<WallManager>
{
private:
	static constexpr int OBJ_MAX = 81;
	OBJ2D objWork[OBJ_MAX];

public:
	OBJ2D* begin() override { return &objWork[0]; }
	OBJ2D* end() override { return &objWork[OBJ_MAX]; }

	//void init() override;

};

//プロトタイプ宣言
void set_wall(OBJ2D* obj);  //壁
