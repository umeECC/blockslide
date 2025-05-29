//#pragma once
//
//#include "Obj2d.h"
//#include "Template.h"
//
//class MapManager : public OBJ2DManager, public Singleton<MapManager>
//{
//public:
//	static const int MAP_HEIGHT = 11;
//	static const int MAP_WIDTH = 11;
//
//	static constexpr int OBJ_MAX = 11 * 11;
//	OBJ2D objWork[OBJ_MAX];
//	
//
//	GameLib::Sprite* block;
//	GameLib::Sprite* ugoku;
//	GameLib::Sprite* hako;
//
//public:
//	OBJ2D* begin() override { return &objWork[0]; }
//	OBJ2D* end() override { return &objWork[OBJ_MAX]; }
//
//	// É}ÉbÉvÇ…ä÷Ç∑ÇÈä÷êîÇÃêÈåæ
//	void init() override;
//	void deinit();
//	
//
//	//void render();
//
//	void loadStage(int newMapData[MAP_HEIGHT][MAP_WIDTH], int newGimickMap[MAP_HEIGHT][MAP_WIDTH]);
//	void switchToStage(int stageNumber)override;
//};