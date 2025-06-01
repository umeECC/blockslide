#include "StageData_2.h"
#include "Wall.h"
#include "Goal.h"
#include "Toge.h"

StageScript stage2Script[] = {
    // マップサイズ: 7x7（原点 416, 136）
    SET_OBJ(1, 416, 136, set_wall, TYPE_WALL),
    SET_OBJ(1, 480, 136, set_wall, TYPE_WALL),
    SET_OBJ(1, 544, 136, set_wall, TYPE_WALL),
    SET_OBJ(1, 608, 136, set_wall, TYPE_WALL),
    SET_OBJ(1, 672, 136, set_wall, TYPE_WALL),
    SET_OBJ(1, 736, 136, set_wall, TYPE_WALL),
    SET_OBJ(1, 800, 136, set_wall, TYPE_WALL),

    SET_OBJ(1, 416, 200, set_wall, TYPE_WALL),
    SET_OBJ(1, 544, 200, set_hako, TYPE_WALL),
    SET_OBJ(1, 800, 200, set_wall, TYPE_WALL),

    SET_OBJ(1, 416, 264, set_wall, TYPE_WALL),
    SET_OBJ(1, 480, 264, set_hako, TYPE_WALL),
    SET_OBJ(1, 800, 264, set_wall, TYPE_WALL),

    SET_OBJ(1, 416, 328, set_wall, TYPE_WALL),
    SET_OBJ(1, 800, 328, set_wall, TYPE_WALL),

    SET_OBJ(1, 416, 392, set_wall, TYPE_WALL),
    SET_OBJ(1, 800, 392, set_wall, TYPE_WALL),
    SET_OBJ(1, 736, 392, set_hako, TYPE_WALL),

    SET_OBJ(1, 416, 456, set_wall, TYPE_WALL),
    SET_OBJ(1, 800, 456, set_wall, TYPE_WALL),

    SET_OBJ(1, 416, 520, set_wall, TYPE_WALL),
    SET_OBJ(1, 480, 520, set_wall, TYPE_WALL),
    SET_OBJ(1, 544, 520, set_wall, TYPE_WALL),
    SET_OBJ(1, 608, 520, set_wall, TYPE_WALL),
    SET_OBJ(1, 672, 520, set_wall, TYPE_WALL),
    SET_OBJ(1, 800, 520, set_wall, TYPE_WALL),
    SET_OBJ(1, 736, 520, set_goal, TYPE_GOAL),

    // 外周：set_invwall（上）
    SET_OBJ(1, 352,  72, set_invwall, TYPE_WALL),
    SET_OBJ(1, 416,  72, set_invwall, TYPE_WALL),
    SET_OBJ(1, 480,  72, set_invwall, TYPE_WALL),
    SET_OBJ(1, 544,  72, set_invwall, TYPE_WALL),
    SET_OBJ(1, 608,  72, set_invwall, TYPE_WALL),
    SET_OBJ(1, 672,  72, set_invwall, TYPE_WALL),
    SET_OBJ(1, 736,  72, set_invwall, TYPE_WALL),
    SET_OBJ(1, 800,  72, set_invwall, TYPE_WALL),
    SET_OBJ(1, 864,  72, set_invwall, TYPE_WALL),

    // 外周：set_invwall（下）
    SET_OBJ(1, 352, 584, set_invwall, TYPE_WALL),
    SET_OBJ(1, 416, 584, set_invwall, TYPE_WALL),
    SET_OBJ(1, 480, 584, set_invwall, TYPE_WALL),
    SET_OBJ(1, 544, 584, set_invwall, TYPE_WALL),
    SET_OBJ(1, 608, 584, set_invwall, TYPE_WALL),
    SET_OBJ(1, 672, 584, set_invwall, TYPE_WALL),
    SET_OBJ(1, 736, 584, set_invwall, TYPE_WALL),
    SET_OBJ(1, 800, 584, set_invwall, TYPE_WALL),
    SET_OBJ(1, 864, 584, set_invwall, TYPE_WALL),

    // 外周：set_invwall（左）
    SET_OBJ(1, 352, 136, set_invwall, TYPE_WALL),
    SET_OBJ(1, 352, 200, set_invwall, TYPE_WALL),
    SET_OBJ(1, 352, 264, set_invwall, TYPE_WALL),
    SET_OBJ(1, 352, 328, set_invwall, TYPE_WALL),
    SET_OBJ(1, 352, 392, set_invwall, TYPE_WALL),
    SET_OBJ(1, 352, 456, set_invwall, TYPE_WALL),
    SET_OBJ(1, 352, 520, set_invwall, TYPE_WALL),

    // 外周：set_invwall（右）
    SET_OBJ(1, 864, 136, set_invwall, TYPE_WALL),
    SET_OBJ(1, 864, 200, set_invwall, TYPE_WALL),
    SET_OBJ(1, 864, 264, set_invwall, TYPE_WALL),
    SET_OBJ(1, 864, 328, set_invwall, TYPE_WALL),
    SET_OBJ(1, 864, 392, set_invwall, TYPE_WALL),
    SET_OBJ(1, 864, 456, set_invwall, TYPE_WALL),
    SET_OBJ(1, 864, 520, set_invwall, TYPE_WALL),


    SET_END
};