#include <iostream>
#include "Warp.h"

bool isInWarpZone(const Player& player, const WarpZone& zone) {
    return player.position.x >= zone.topLeft.x &&
        player.position.x <= zone.bottomRight.x &&
        player.position.y >= zone.topLeft.y &&
        player.position.y <= zone.bottomRight.y;
}

void warpPlayer(Player& player, const WarpZone& zone) {
    if (isInWarpZone(player, zone)) {
        player.position = zone.destination;
        std::cout << "���[�v���܂����I �V�������W: ("
            << player.position.x << ", "
            << player.position.y << ")" << std::endl;
    }
}