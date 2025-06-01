#pragma once
#include "Obj2d.h"
#include "Template.h"

class GoalManager :public OBJ2DManager, public Singleton<GoalManager>
{
private:
	static constexpr int OBJ_MAX = 10;
	OBJ2D objWork[OBJ_MAX];

public:
	OBJ2D* begin() override { return &objWork[0]; }
	OBJ2D* end() override { return &objWork[OBJ_MAX]; }

	//void init() override;

};

class Goal {
public:
	VECTOR2 position;
	VECTOR2 hSize;
	bool isReached = false;

	Goal(const VECTOR2& pos, const VECTOR2& size)
		: position(pos), hSize(size) {
	}
};

//プロトタイプ宣言
void set_goal(OBJ2D* obj);  //ゴール
