#pragma once
#include "Obj2d.h"
#include "Template.h"

class PlayerManager_sd :public OBJ2DManager, public Singleton<PlayerManager_sd>
{
private:
	static constexpr int OBJ_MAX = 5;
	OBJ2D objWork[OBJ_MAX];

	bool isMove = false;

	bool isWarpmove = false;
public:
	OBJ2D* begin() override { return &objWork[0]; }
	OBJ2D* end() override { return &objWork[OBJ_MAX]; }

	void init() override;

	void update() override;

	bool isMoving() { return isMove; }			//	1‘Ì‚Å‚à“®‚¢‚Ä‚¢‚é‚©‚Ç‚¤‚©

	bool isWarp() { return isWarpmove; }
};


void player_sd_Move(OBJ2D* obj);

void player_sd_Update(OBJ2D* obj);

void direction_sd_reset(OBJ2D* obj);

void player_sd_reset(OBJ2D* obj);
