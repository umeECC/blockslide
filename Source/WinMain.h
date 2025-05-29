#pragma once

inline constexpr int SCREEN_WIDTH = 1280;
inline constexpr int SCREEN_HEIGHT = 720;

enum SCENE
{
    TITLE = 0,
    GAME,
    CLEAR,
    OVER,
    SELECT,
};

void setScene(int nextScene);
