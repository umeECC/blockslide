#pragma once
class Scene
{
protected:
    int timer;

public:
    virtual void init() {}
    virtual void deinit() {}
    virtual void update() = 0;
    virtual void draw() = 0;
};
