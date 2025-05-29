#pragma once
#include "Player.h"

struct WarpZone {
    Vector2 topLeft;
    Vector2 bottomRight;
    Vector2 destination;
};

bool isInWarpZone(const Player& player, const WarpZone& zone);
void warpPlayer(Player& player, const WarpZone& zone);