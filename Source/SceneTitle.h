#pragma once
#include "Scene.h"

class SceneTitle : public Scene
{
private:
    void init() override;
    void deinit();
    void update() override;
    void draw() override;
};
