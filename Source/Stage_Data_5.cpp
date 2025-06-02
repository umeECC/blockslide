#include "StageData_5.h"
#include "Wall.h"
#include "Goal.h"
#include "Toge.h"


StageScript stage5Script[] = {

    SET_OBJ(1, 352,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 416,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 480,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 544,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 608,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 672,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 736,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 800,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 864,  88, set_invwall, TYPE_WALL),
    SET_OBJ(1, 352,  88, set_wall, TYPE_WALL),
    SET_OBJ(1, 416,  88, set_wall, TYPE_WALL),
    SET_OBJ(1, 480,  88, set_wall, TYPE_WALL),
    SET_OBJ(1, 544,  88, set_wall, TYPE_WALL),
    SET_OBJ(1, 608,  88, set_wall, TYPE_WALL),
    SET_OBJ(1, 672,  88, set_wall, TYPE_WALL),
   // SET_OBJ(1, 736,  88, set_wall, TYPE_WALL),
    SET_OBJ(1, 800,  88, set_wall, TYPE_WALL),
    SET_OBJ(1, 864,  88, set_wall, TYPE_WALL),
    SET_OBJ(1, 288,  88, set_wall, TYPE_WALL),
    SET_OBJ(1, 928,  88, set_wall, TYPE_WALL),
    SET_OBJ(1, 800, 152, set_hako, TYPE_WALL),
    SET_OBJ(1,800,216,set_Toge,TYPE_WALL),
    SET_OBJ(1,864,408,set_hako,TYPE_WALL),
     SET_OBJ(1,928,472,set_hako,TYPE_WALL),
     //SET_OBJ(1,)
    SET_OBJ(1,928,408,set_wall,TYPE_WALL),
    SET_OBJ(1,992,408,set_invwall,TYPE_WALL),
    //SET_OBJ(1,)
    SET_OBJ(1,928,456,set_goal,TYPE_WALL),
    SET_OBJ(1,928,520,set_wall,TYPE_WALL),
    SET_OBJ(1, 864, 152, set_wall, TYPE_WALL),
    SET_OBJ(1,800,216,set_invwall,TYPE_WALL),
    SET_OBJ(1,928,152,set_wall,TYPE_WALL),
   // SET_OBJ(1, 800, 152, set_wall, TYPE_WALL),
    SET_OBJ(1, 288, 152, set_wall, TYPE_WALL),

    SET_OBJ(1, 288, 216, set_wall, TYPE_WALL),
    
    SET_OBJ(1, 928, 216, set_wall, TYPE_WALL),
   // SET_OBJ(1, 288, 280, set_wall, TYPE_WALL),
    
    SET_OBJ(1, 928, 280, set_wall, TYPE_WALL),
    SET_OBJ(1, 288, 344, set_wall, TYPE_WALL),
    
    SET_OBJ(1, 928, 344, set_wall, TYPE_WALL),
    SET_OBJ(1, 288, 408, set_wall, TYPE_WALL),
     SET_OBJ(1, 352, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 416, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 480, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 544, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 608, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 672, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 736, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 800, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 864, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 288, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 928, 584, set_wall, TYPE_WALL),
    SET_OBJ(1,288,520,set_wall,TYPE_WALL),
    SET_OBJ(1,288,456,set_wall,TYPE_WALL),

};