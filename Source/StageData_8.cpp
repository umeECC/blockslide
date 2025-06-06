#include "StageData_8.h"
#include "Wall.h"
#include "Goal.h"
#include "Toge.h"

StageScript stage8Script[] = {
    // Row 0
    SET_OBJ(1, 192,   8, set_invwall, TYPE_WALL),
    SET_OBJ(1,1024,   8, set_invwall, TYPE_WALL),
    //     
    SET_OBJ(1, 192, 648, set_invwall, TYPE_WALL),
    SET_OBJ(1,1024, 648, set_invwall, TYPE_WALL),
    //    E
    SET_OBJ(1, 192,  72, set_invwall, TYPE_WALL),
    SET_OBJ(1, 192, 136, set_invwall, TYPE_WALL),
    SET_OBJ(1, 192, 200, set_invwall, TYPE_WALL),
    SET_OBJ(1, 192, 264, set_invwall, TYPE_WALL),
    SET_OBJ(1, 192, 328, set_invwall, TYPE_WALL),
    SET_OBJ(1, 192, 392, set_invwall, TYPE_WALL),
    SET_OBJ(1, 192, 456, set_invwall, TYPE_WALL),
    SET_OBJ(1, 192, 520, set_invwall, TYPE_WALL),
    SET_OBJ(1, 192, 584, set_invwall, TYPE_WALL),



    SET_OBJ(1, 256, 72,  set_goal, TYPE_GOAL),
    SET_OBJ(1, 256, 200, set_goal, TYPE_GOAL),
    SET_OBJ(1, 256, 264, set_goal, TYPE_GOAL),
    SET_OBJ(1, 256, 328, set_wall, TYPE_WALL),
    SET_OBJ(1, 256, 392, set_wall, TYPE_WALL),
    SET_OBJ(1, 256, 456, set_wall, TYPE_WALL),
    SET_OBJ(1, 256, 520, set_wall, TYPE_WALL),
    SET_OBJ(1, 256, 584, set_wall, TYPE_WALL),

    SET_OBJ(1,1024,  72, set_invwall, TYPE_WALL),
    SET_OBJ(1,1024, 136, set_invwall, TYPE_WALL),
    SET_OBJ(1,1024, 200, set_invwall, TYPE_WALL),
    SET_OBJ(1,1024, 264, set_invwall, TYPE_WALL),
    SET_OBJ(1,1024, 328, set_invwall, TYPE_WALL),
    SET_OBJ(1,1024, 392, set_invwall, TYPE_WALL),
    SET_OBJ(1,1024, 456, set_invwall, TYPE_WALL),
    SET_OBJ(1,1024, 520, set_invwall, TYPE_WALL),
    SET_OBJ(1,1024, 584, set_invwall, TYPE_WALL),

    // ===  } b v {   ===
    // 0 s ?iY=72 j
    SET_OBJ(1, 256,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 320,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 384,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 448,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 512,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 576,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 640,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 704,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 768,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 832,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 896,  72, set_wall, TYPE_WALL),
    SET_OBJ(1, 960,  72, set_wall, TYPE_WALL),

    // 1 s  
    SET_OBJ(1, 256, 136, set_wall, TYPE_WALL),
    SET_OBJ(1, 960, 136, set_wall, TYPE_WALL),

    // 2 s  

    SET_OBJ(1, 512, 200, set_hako, TYPE_WALL),
    SET_OBJ(1, 960, 200, set_wall, TYPE_WALL),

    // 3 s  
    SET_OBJ(1, 256, 264, set_wall, TYPE_WALL),

    SET_OBJ(1, 384, 264, set_hako, TYPE_WALL),
    //SET_OBJ(1, 448, 264, set_wall, TYPE_WALL),
    SET_OBJ(1, 832, 264, set_hako, TYPE_WALL),
    SET_OBJ(1, 960, 264, set_wall, TYPE_WALL),

    // 4 s  
    SET_OBJ(1, 256, 328, set_wall, TYPE_WALL),
    SET_OBJ(1, 960, 328, set_wall, TYPE_WALL),

    // 5 s  
    SET_OBJ(1, 960, 392, set_goal, TYPE_GOAL),

    // 6 s  
    SET_OBJ(1, 832, 456, set_hako, TYPE_WALL),
    SET_OBJ(1, 896, 456, set_wall, TYPE_WALL),
    SET_OBJ(1, 960, 456, set_wall, TYPE_WALL),
    // 7 s  
    //SET_OBJ(1, 320, 520, set_hako, TYPE_WALL),
    SET_OBJ(1, 704, 520, set_hako, TYPE_WALL),
    SET_OBJ(1, 960, 520, set_wall, TYPE_WALL),

    // 8 s  

    SET_OBJ(1, 256, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 320, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 384, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 448, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 512, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 576, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 640, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 704, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 768, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 832, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 896, 584, set_wall, TYPE_WALL),
    SET_OBJ(1, 960, 584, set_wall, TYPE_WALL),

    SET_END
};