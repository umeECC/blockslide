#include "StageData_1.h"
#include "Wall.h"
#include "Goal.h"
#include "Toge.h"

StageScript stage1Script[] = {
    // 上の囲い（行0）
    SET_OBJ(1, 352,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 416,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 480,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 544,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 608,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 672,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 736,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 800,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 864,  88, set_invwall, TYPE_WALL),

    // 中央エリア（行1~7）
    // 行1
    SET_OBJ(1, 352, 152, set_invwall, TYPE_WALL),
    SET_OBJ(1, 416, 152, set_wall, TYPE_WALL),
    SET_OBJ(1, 480, 152, set_wall, TYPE_WALL),
    SET_OBJ(1, 544, 152, set_wall, TYPE_WALL),
    SET_OBJ(1, 608, 152, set_wall, TYPE_WALL),
    SET_OBJ(1, 672, 152, set_wall, TYPE_WALL),
    SET_OBJ(1, 736, 152, set_wall, TYPE_WALL),
    SET_OBJ(1, 800, 152, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 152, set_invwall, TYPE_WALL),

    // 行2
    SET_OBJ(1, 352, 216, set_invwall, TYPE_WALL),
    SET_OBJ(1, 416, 216, set_wall, TYPE_WALL),
    SET_OBJ(1, 672, 216, set_hako, TYPE_WALL),
    SET_OBJ(1, 800, 216, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 216, set_invwall, TYPE_WALL),

    // 行3
    SET_OBJ(1, 352, 280, set_invwall, TYPE_WALL),
    SET_OBJ(1, 416, 280, set_wall, TYPE_WALL),
    SET_OBJ(1, 800, 280, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 280, set_invwall, TYPE_WALL),

    // 行4
    SET_OBJ(1, 352, 344, set_invwall, TYPE_WALL),
    SET_OBJ(1, 416, 344, set_wall, TYPE_WALL),
    SET_OBJ(1, 800, 344, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 344, set_invwall, TYPE_WALL),

    // 行5
    SET_OBJ(1, 352, 408, set_invwall, TYPE_WALL),
    SET_OBJ(1, 416, 408, set_wall, TYPE_WALL),
    SET_OBJ(1, 800, 408, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 408, set_invwall, TYPE_WALL),

    // 行6
    SET_OBJ(1, 352, 472, set_invwall, TYPE_WALL),
    SET_OBJ(1, 416, 472, set_wall, TYPE_WALL),
    SET_OBJ(1, 608, 472, set_hako, TYPE_WALL),
    SET_OBJ(1, 800, 472, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 472, set_invwall, TYPE_WALL),

    // 行7
    SET_OBJ(1, 352, 536, set_invwall, TYPE_WALL),
    SET_OBJ(1, 416, 536, set_wall, TYPE_WALL),
    SET_OBJ(1, 480, 536, set_wall, TYPE_WALL),
    SET_OBJ(1, 544, 536, set_wall, TYPE_WALL),
    SET_OBJ(1, 608, 536, set_wall, TYPE_WALL),
    SET_OBJ(1, 672, 536, set_wall, TYPE_WALL),
    SET_OBJ(1, 736, 536, set_goal, TYPE_GOAL), 
    SET_OBJ(1, 800, 536, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 536, set_invwall, TYPE_WALL),

    // 下の囲い（行8）
    SET_OBJ(1, 352, 600, set_invwall, TYPE_WALL),
    SET_OBJ(1, 416, 600, set_invwall, TYPE_WALL),
    SET_OBJ(1, 480, 600, set_invwall, TYPE_WALL),
    SET_OBJ(1, 544, 600, set_invwall, TYPE_WALL),
    SET_OBJ(1, 608, 600, set_invwall, TYPE_WALL),
    SET_OBJ(1, 672, 600, set_invwall, TYPE_WALL),
    SET_OBJ(1, 736, 600, set_invwall, TYPE_WALL),
    SET_OBJ(1, 800, 600, set_invwall, TYPE_WALL),
    SET_OBJ(1, 864, 600, set_invwall, TYPE_WALL),

    SET_END
};
