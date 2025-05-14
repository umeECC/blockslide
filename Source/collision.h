#ifndef COLLISION_H
#define COLLISION_H

// 衝突判定を行うマップチップの配列
extern const int collisionTiles[];

extern const float playerWidth;
extern const float playerHeight;

// 衝突判定関数の宣言
bool checkCollision(float x, float y);

#endif // COLLISION_H
