#pragma once
#include "Scene.h"

class SceneSelect : public Scene
{
private:
    void init() override;
    void deinit();
    void update() override;
    void draw() override;
};

extern int stage_number;

