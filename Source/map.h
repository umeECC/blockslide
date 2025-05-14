#pragma once

#include "Obj2d.h"
#include "Template.h"

class MapManager : public Singleton<MapManager>
{
public:
	static const int MAP_HEIGHT = 11;
	static const int MAP_WIDTH = 11;

	

	GameLib::Sprite* block;
	GameLib::Sprite* ugoku;
	GameLib::Sprite* hako;

public:
	// ƒ}ƒbƒv‚ÉŠÖ‚·‚éŠÖ”‚ÌéŒ¾
	void init();
	void deinit();
	//void render();
	void draw();
	void loadStage(int newMapData[MAP_HEIGHT][MAP_WIDTH], int newGimickMap[MAP_HEIGHT][MAP_WIDTH]);
	void switchToStage(int stageNumber);
};