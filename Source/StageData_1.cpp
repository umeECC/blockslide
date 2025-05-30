#include "StageData_1.h"
#include "Wall.h"
#include "Goal.h"
#include "Toge.h"

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

    //見えない壁
    SET_OBJ(1, 320, 40, set_invwall, TYPE_WALL),
    SET_OBJ(1, 384, 40, set_invwall, TYPE_WALL),
    SET_OBJ(1, 448, 40, set_invwall, TYPE_WALL),
    SET_OBJ(1, 512, 40, set_invwall, TYPE_WALL),
    SET_OBJ(1, 576, 40, set_invwall, TYPE_WALL),
    SET_OBJ(1, 640, 40, set_invwall, TYPE_WALL),
    SET_OBJ(1, 704, 40, set_invwall, TYPE_WALL),
    SET_OBJ(1, 768, 40, set_invwall, TYPE_WALL),
    SET_OBJ(1, 832, 40, set_invwall, TYPE_WALL),
    SET_OBJ(1, 896, 40, set_invwall, TYPE_WALL),
    SET_OBJ(1, 960, 40, set_invwall, TYPE_WALL),
    SET_OBJ(1, 960, 104, set_invwall, TYPE_WALL),
    SET_OBJ(1, 960, 168, set_invwall, TYPE_WALL),
    SET_OBJ(1, 960, 232, set_invwall, TYPE_WALL),
    SET_OBJ(1, 960, 296, set_invwall, TYPE_WALL),
    SET_OBJ(1, 960, 360, set_invwall, TYPE_WALL),
    SET_OBJ(1, 960, 424, set_invwall, TYPE_WALL),
    SET_OBJ(1, 960, 488, set_invwall, TYPE_WALL),
    SET_OBJ(1, 960, 552, set_invwall, TYPE_WALL),
    SET_OBJ(1, 960, 616, set_invwall, TYPE_WALL),
    SET_OBJ(1, 960, 680, set_invwall, TYPE_WALL),
    SET_OBJ(1, 320, 680, set_invwall, TYPE_WALL),
    SET_OBJ(1, 384, 680, set_invwall, TYPE_WALL),
    SET_OBJ(1, 448, 680, set_invwall, TYPE_WALL),
    SET_OBJ(1, 512, 680, set_invwall, TYPE_WALL),
    SET_OBJ(1, 576, 680, set_invwall, TYPE_WALL),
    SET_OBJ(1, 640, 680, set_invwall, TYPE_WALL),
    SET_OBJ(1, 704, 680, set_invwall, TYPE_WALL),
    SET_OBJ(1, 768, 680, set_invwall, TYPE_WALL),
    SET_OBJ(1, 832, 680, set_invwall, TYPE_WALL),
    SET_OBJ(1, 896, 680, set_invwall, TYPE_WALL),
    SET_OBJ(1, 960, 680, set_invwall, TYPE_WALL),
    SET_OBJ(1, 320, 104, set_invwall, TYPE_WALL),
    SET_OBJ(1, 320, 168, set_invwall, TYPE_WALL),
    SET_OBJ(1, 320, 232, set_invwall, TYPE_WALL),
    SET_OBJ(1, 320, 296, set_invwall, TYPE_WALL),
    SET_OBJ(1, 320, 360, set_invwall, TYPE_WALL),
    SET_OBJ(1, 320, 424, set_invwall, TYPE_WALL),
    SET_OBJ(1, 320, 488, set_invwall, TYPE_WALL),
    SET_OBJ(1, 320, 552, set_invwall, TYPE_WALL),
    SET_OBJ(1, 320, 616, set_invwall, TYPE_WALL),
    SET_OBJ(1, 320, 680, set_invwall, TYPE_WALL),



    SET_OBJ(1, 448, 168, set_Toge,TYPE_NONE),

    SET_OBJ(1, 832, 232, set_hako,TYPE_WALL),
    SET_OBJ(1, 616, 488, set_hako,TYPE_WALL),
    
    SET_END
};
