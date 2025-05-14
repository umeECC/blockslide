#pragma once
#include "Obj2d.h"
#include "Template.h"

class EffectManager : public OBJ2DManager, public Singleton<EffectManager>
{
    static constexpr int OBJ_MAX = 100;
    OBJ2D objWork[OBJ_MAX];

public:
    OBJ2D* begin() { return &objWork[0]; }
    OBJ2D* end() { return &objWork[OBJ_MAX]; }

    void init() override;
};

void effectExplos(OBJ2D* obj);
