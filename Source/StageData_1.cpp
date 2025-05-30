#include "StageData_1.h"
#include "Wall.h"
#include "Goal.h"
#include "Warp.h"

StageScript stage1Script[] = {
    // 上辺の横ライン
    SET_OBJ(1, 384, 104, set_wall,TYPE_WALL),
    SET_OBJ(1, 448, 104, set_wall,TYPE_WALL),
    SET_OBJ(1, 512, 104, set_wall,TYPE_WALL),
    SET_OBJ(1, 576, 104, set_wall,TYPE_WALL),
    SET_OBJ(1, 640, 104, set_wall,TYPE_WALL),
    SET_OBJ(1, 704, 104, set_wall,TYPE_WALL),
    SET_OBJ(1, 768, 104, set_wall,TYPE_WALL),
    SET_OBJ(1, 832, 104, set_wall,TYPE_WALL),
    SET_OBJ(1, 896, 104, set_wall,TYPE_WALL),

    // 右辺の縦ライン
    SET_OBJ(1, 896, 168, set_wall,TYPE_WALL),
    SET_OBJ(1, 896, 232, set_wall,TYPE_WALL),
    SET_OBJ(1, 896, 296, set_wall,TYPE_WALL),
    SET_OBJ(1, 896, 360, set_wall,TYPE_WALL),
    SET_OBJ(1, 896, 424, set_wall,TYPE_WALL),
    SET_OBJ(1, 896, 488, set_goal,TYPE_GOAL),
    SET_OBJ(1, 896, 552, set_wall,TYPE_WALL),
    SET_OBJ(1, 896, 616, set_wall,TYPE_WALL),

    // 下辺の横ライン
    SET_OBJ(1, 832, 616, set_wall,TYPE_WALL),
    SET_OBJ(1, 768, 616, set_wall,TYPE_WALL),
    SET_OBJ(1, 704, 616, set_wall,TYPE_WALL),
    SET_OBJ(1, 640, 616, set_wall,TYPE_WALL),
    SET_OBJ(1, 576, 616, set_wall,TYPE_WALL),
    SET_OBJ(1, 512, 616, set_wall,TYPE_WALL),
    SET_OBJ(1, 448, 616, set_wall,TYPE_WALL),
    SET_OBJ(1, 384, 616, set_wall,TYPE_WALL),

    // 左辺の縦ライン
    SET_OBJ(1, 384, 552, set_wall,TYPE_WALL),
    SET_OBJ(1, 384, 488, set_wall,TYPE_WALL),
    SET_OBJ(1, 384, 424, set_wall,TYPE_WALL),
    SET_OBJ(1, 384, 360, set_wall,TYPE_WALL),
    SET_OBJ(1, 384, 296, set_wall,TYPE_WALL),
    SET_OBJ(1, 384, 232, set_wall,TYPE_WALL),
    SET_OBJ(1, 384, 168, set_wall,TYPE_WALL),



    SET_OBJ(1, 832, 232, set_hako,TYPE_WALL),
    SET_OBJ(1, 616, 488, set_hako,TYPE_WALL),
    
    SET_WARP(1,590, 170, set_warp,TYPE_WARP),
    SET_WARP(1,590, 390, set_warp,TYPE_WARP),
    SET_END
};
