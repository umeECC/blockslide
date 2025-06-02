#include "StageData_1.h"
#include "Wall.h"
#include "Goal.h"
#include "Toge.h"

StageScript stage6Script[] = {
    // Row 0
    SET_OBJ(1, 352,  102, set_wall, TYPE_WALL),
    SET_OBJ(1, 416,  102, set_wall, TYPE_WALL),
    SET_OBJ(1, 480,  102, set_wall, TYPE_WALL),
    SET_OBJ(1, 544,  102, set_wall, TYPE_WALL),
    SET_OBJ(1, 608,  102, set_wall, TYPE_WALL),
    SET_OBJ(1, 672,  102, set_goal, TYPE_GOAL),
    SET_OBJ(1, 736,  102, set_wall, TYPE_WALL),
    SET_OBJ(1, 800,  102, set_wall, TYPE_WALL),
    SET_OBJ(1, 864,  102, set_wall, TYPE_WALL),

    // Row 1
    SET_OBJ(1, 352, 166, set_wall, TYPE_WALL),
    SET_OBJ(1, 608, 166, set_hako, TYPE_WALL),
    SET_OBJ(1, 864, 166, set_wall, TYPE_WALL),

    // Row 2
    SET_OBJ(1, 352, 230, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 230, set_wall, TYPE_WALL),

    // Row 3
    SET_OBJ(1, 352, 294, set_wall, TYPE_WALL),
    SET_OBJ(1, 416, 294, set_hako, TYPE_WALL),
    SET_OBJ(1, 864, 294, set_wall, TYPE_WALL),

    // Row 4
    SET_OBJ(1, 352, 358, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 358, set_wall, TYPE_WALL),

    // Row 5
    SET_OBJ(1, 352, 422, set_goal, TYPE_GOAL),
    SET_OBJ(1, 800, 422, set_hako, TYPE_WALL),
    SET_OBJ(1, 864, 422, set_wall, TYPE_WALL),

    // Row 6
    SET_OBJ(1, 352, 486, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 486, set_wall, TYPE_WALL),

    // Row 7
    SET_OBJ(1, 352, 550, set_wall, TYPE_WALL),
    SET_OBJ(1, 416, 550, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 550, set_wall, TYPE_WALL),

    // Row 8
    SET_OBJ(1, 352, 614, set_wall, TYPE_WALL),
    SET_OBJ(1, 416, 614, set_wall, TYPE_WALL),
    SET_OBJ(1, 480, 614, set_wall, TYPE_WALL),
    SET_OBJ(1, 544, 614, set_wall, TYPE_WALL),
    SET_OBJ(1, 608, 614, set_wall, TYPE_WALL),
    SET_OBJ(1, 672, 614, set_wall, TYPE_WALL),
    SET_OBJ(1, 736, 614, set_wall, TYPE_WALL),
    SET_OBJ(1, 800, 614, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 614, set_wall, TYPE_WALL),

    // è„ï”
    SET_OBJ(1, 288,  38,  set_invwall, TYPE_WALL),
    SET_OBJ(1, 352,  38,  set_invwall, TYPE_WALL),
    SET_OBJ(1, 416,  38,  set_invwall, TYPE_WALL),
    SET_OBJ(1, 480,  38,  set_invwall, TYPE_WALL),
    SET_OBJ(1, 544,  38,  set_invwall, TYPE_WALL),
    SET_OBJ(1, 608,  38,  set_invwall, TYPE_WALL),
    SET_OBJ(1, 672,  38,  set_invwall, TYPE_WALL),
    SET_OBJ(1, 736,  38,  set_invwall, TYPE_WALL),
    SET_OBJ(1, 800,  38,  set_invwall, TYPE_WALL),
    SET_OBJ(1, 864,  38,  set_invwall, TYPE_WALL),
    SET_OBJ(1, 928,  38,  set_invwall, TYPE_WALL),

    // â∫ï”
    SET_OBJ(1, 288,  678, set_invwall, TYPE_WALL),
    SET_OBJ(1, 352,  678, set_invwall, TYPE_WALL),
    SET_OBJ(1, 416,  678, set_invwall, TYPE_WALL),
    SET_OBJ(1, 480,  678, set_invwall, TYPE_WALL),
    SET_OBJ(1, 544,  678, set_invwall, TYPE_WALL),
    SET_OBJ(1, 608,  678, set_invwall, TYPE_WALL),
    SET_OBJ(1, 672,  678, set_invwall, TYPE_WALL),
    SET_OBJ(1, 736,  678, set_invwall, TYPE_WALL),
    SET_OBJ(1, 800,  678, set_invwall, TYPE_WALL),
    SET_OBJ(1, 864,  678, set_invwall, TYPE_WALL),
    SET_OBJ(1, 928,  678, set_invwall, TYPE_WALL),

    // ç∂ï”
    SET_OBJ(1, 288,  102, set_invwall, TYPE_WALL),
    SET_OBJ(1, 288,  166, set_invwall, TYPE_WALL),
    SET_OBJ(1, 288,  230, set_invwall, TYPE_WALL),
    SET_OBJ(1, 288,  294, set_invwall, TYPE_WALL),
    SET_OBJ(1, 288,  358, set_invwall, TYPE_WALL),
    SET_OBJ(1, 288,  422, set_invwall, TYPE_WALL),
    SET_OBJ(1, 288,  486, set_invwall, TYPE_WALL),
    SET_OBJ(1, 288,  550, set_invwall, TYPE_WALL),
    SET_OBJ(1, 288,  614, set_invwall, TYPE_WALL),

    // âEï”
    SET_OBJ(1, 928,  102, set_invwall, TYPE_WALL),
    SET_OBJ(1, 928,  166, set_invwall, TYPE_WALL),
    SET_OBJ(1, 928,  230, set_invwall, TYPE_WALL),
    SET_OBJ(1, 928,  294, set_invwall, TYPE_WALL),
    SET_OBJ(1, 928,  358, set_invwall, TYPE_WALL),
    SET_OBJ(1, 928,  422, set_invwall, TYPE_WALL),
    SET_OBJ(1, 928,  486, set_invwall, TYPE_WALL),
    SET_OBJ(1, 928,  550, set_invwall, TYPE_WALL),
    SET_OBJ(1, 928,  614, set_invwall, TYPE_WALL),
};