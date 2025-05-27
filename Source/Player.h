#pragma once
#include "Obj2d.h"
#include "Template.h"

class PlayerManager :public OBJ2DManager, public Singleton<PlayerManager>
{

private:
	static constexpr int OBJ_MAX = 1;
	OBJ2D objWork[OBJ_MAX];


	bool isMove = false;

	// true...プレイヤーの１が動いている
	bool isPlayerOneMove = false;

	// true...プレイヤーの２が動いている
	bool isPlayerSecondMove = false;
public:
	void setIsPlayerOneMove(bool flag) { isPlayerOneMove = flag; }
	void setIsPlayerSecondMove(bool flag) { isPlayerSecondMove = flag; }

public:
	OBJ2D* begin() override { return &objWork[0]; }
	OBJ2D* end() override { return &objWork[OBJ_MAX]; }

	void init() override;

	void update() override;


	bool isMoving() { return isMove; }
};


void playerMove(OBJ2D* obj);

void playerUpdate(OBJ2D* obj);

void direction_reset(OBJ2D* obj);
void goal_moving(OBJ2D* obj);
