#include "StageData_1.h"
#include "Wall.h"
#include "Goal.h"
#include "Toge.h"

StageScript stage6Script[] = {
    // Row 0
    SET_OBJ(1, 352,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 416,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 480,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 544,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 608,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 672,  72, set_goal, TYPE_GOAL),
    SET_OBJ(1, 736,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 800,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 864,  72, set_wall, TYPE_WALL),

    // Row 1
    SET_OBJ(1, 352, 136, set_wall, TYPE_WALL),
    SET_OBJ(1, 608, 136, set_hako, TYPE_WALL),
    SET_OBJ(1, 864, 136, set_wall, TYPE_WALL),

    // Row 2
    SET_OBJ(1, 352, 200, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 200, set_wall, TYPE_WALL),

    // Row 3
    SET_OBJ(1, 352, 264, set_wall, TYPE_WALL),
    SET_OBJ(1, 416, 264, set_hako, TYPE_WALL),
    SET_OBJ(1, 738, 264, set_hako, TYPE_WALL),
    SET_OBJ(1, 864, 264, set_wall, TYPE_WALL),

    // Row 4
    SET_OBJ(1, 352, 328, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 328, set_wall, TYPE_WALL),

    // Row 5
    SET_OBJ(1, 352, 392, set_goal, TYPE_GOAL),
    SET_OBJ(1, 800, 392, set_hako, TYPE_WALL),
    SET_OBJ(1, 864, 392, set_wall, TYPE_WALL),

    // Row 6
    SET_OBJ(1, 352, 456, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 456, set_wall, TYPE_WALL),

    // Row 7
    SET_OBJ(1, 352, 520, set_wall, TYPE_WALL),
    SET_OBJ(1, 416, 520, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 520, set_wall, TYPE_WALL),

    // Row 8
    SET_OBJ(1, 352, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 416, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 480, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 544, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 608, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 672, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 736, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 800, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 584, set_wall, TYPE_WALL),
};