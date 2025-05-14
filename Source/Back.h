#pragma once

#include "Obj2d.h"
#include "Template.h"

class BackManager : public OBJ2DManager, public Singleton<BackManager>
{
    static constexpr int OBJ_MAX = 1;
    OBJ2D objWork[OBJ_MAX];

public:
    OBJ2D* begin() override { return &objWork[0]; }
    OBJ2D* end() override { return &objWork[OBJ_MAX]; }

    void init() override;
};

void backUpdate(OBJ2D* obj);