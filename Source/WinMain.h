#pragma once

inline constexpr int SCREEN_WIDTH = 1280;
inline constexpr int SCREEN_HEIGHT = 720;

enum SCENE
{
    TITLE = 0,
    STAGESEL,
    GAME,
    CLEAR,
    OVER,
};

void setScene(int nextScene);
