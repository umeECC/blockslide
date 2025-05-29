#include "StageData_1.h"
#include "Wall.h"

StageScript stage1Script[] = {
    // 上辺の横ライン
    SET_WALL(1.0f, 384, 104, set_wall),
    SET_WALL(1.0f, 448, 104, set_wall),
    SET_WALL(1.0f, 512, 104, set_wall),
    SET_WALL(1.0f, 576, 104, set_wall),
    SET_WALL(1.0f, 640, 104, set_wall),
    SET_WALL(1.0f, 704, 104, set_wall),
    SET_WALL(1.0f, 768, 104, set_wall),
    SET_WALL(1.0f, 832, 104, set_wall),
    SET_WALL(1.0f, 896, 104, set_wall),

    // 右辺の縦ライン
    SET_WALL(1.0f, 896, 168, set_wall),
    SET_WALL(1.0f, 896, 232, set_wall),
    SET_WALL(1.0f, 896, 296, set_wall),
    //SET_WALL(1.0f, 896, 360, set_wall),
    SET_WALL(1.0f, 896, 424, set_wall),
    SET_WALL(1.0f, 896, 488, set_wall),
    SET_WALL(1.0f, 896, 552, set_wall),
    SET_WALL(1.0f, 896, 616, set_wall),

    // 下辺の横ライン
    SET_WALL(1.0f, 832, 616, set_wall),
    SET_WALL(1.0f, 768, 616, set_wall),
    SET_WALL(1.0f, 704, 616, set_wall),
    SET_WALL(1.0f, 640, 616, set_wall),
    SET_WALL(1.0f, 576, 616, set_wall),
    SET_WALL(1.0f, 512, 616, set_wall),
    SET_WALL(1.0f, 448, 616, set_wall),
    SET_WALL(1.0f, 384, 616, set_wall),

    // 左辺の縦ライン
    SET_WALL(1.0f, 384, 552, set_wall),
    SET_WALL(1.0f, 384, 488, set_wall),
    SET_WALL(1.0f, 384, 424, set_wall),
    SET_WALL(1.0f, 384, 360, set_wall),
    SET_WALL(1.0f, 384, 296, set_wall),
    SET_WALL(1.0f, 384, 232, set_wall),
    SET_WALL(1.0f, 384, 168, set_wall),
};
