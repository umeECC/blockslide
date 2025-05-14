#pragma once
#include "Scene.h"

class SceneTuto : public Scene
{
private:
    int tutoState;

private:
    void init() override;
    void deinit() override;
    void update() override;
    void draw() override;
};