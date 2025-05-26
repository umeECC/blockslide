#include <iostream>
#include "WinMain.h"

#include "Effect.h"
#include "Judge.h"

#include "Player.h"
#include "Player_sd.h"

#include "Wall.h"
#include"map.h"
#include"Stage.h"
#include "Statge1.h"
#include"SpriteData.h"
#include <set>
extern int mapData[MapManager::MAP_HEIGHT][MapManager::MAP_WIDTH];
class JudgeRect
{
	float left, top, right, bottom;

public:
	JudgeRect(float l, float t, float r, float b)
	{
		left = l;
		top = t;
		right = r;
		bottom = b;
	}
	JudgeRect(const VECTOR2& position, const VECTOR2& hSize)
		:JudgeRect(position.x - hSize.x, position.y - hSize.y,
			position.x + hSize.x, position.y + hSize.y) {}

	bool isHit(const JudgeRect& other)
	{
		if (right < other.left) return false;
		if (left > other.right) return false;
		if (bottom < other.top) return false;
		if (top > other.bottom) return false;
		return true;
	}

};

// プロトタイプ宣言
void judgeSub(OBJ2DManager& manager1, OBJ2DManager& manager2);
void judgeSub_sd(OBJ2DManager& manager1, OBJ2DManager& manager2);
void judgePvP(OBJ2DManager& manager1, OBJ2DManager& manager2);
void judgeMapchip(OBJ2DManager& manager1);


JudgeRect screenRect = {
	64, 64, SCREEN_WIDTH - 64, SCREEN_HEIGHT - 64,
};

void judge()
{
	

	// プレイヤーVS壁
	judgeMapchip(PlayerManager::getInstance());
	judgeMapchip(PlayerManager_sd::getInstance());

	// プレイヤー2VS壁
	judgeSub_sd(PlayerManager_sd::getInstance(), WallManager::getInstance());

	judgeSub(MapManager::getInstance(), PlayerManager::getInstance());
	
	// プレイヤーVSプレイヤー2
	judgePvP(PlayerManager::getInstance(), PlayerManager_sd::getInstance());

	// 挟まれチェック：上下 + 左右の両方が埋まっていたら
	if (PlayerManager::getInstance().checkpress())
	{
		setScene(SCENE::OVER);// ←ゲームオーバー画面に切り替える関数
		return; // 以降の処理不要
	}
}
std::set<int> BLOCK_TILE_IDS = { 1, 2, 3 }; // 例えば1, 2, 3は壁

bool isBlocked(float x, float y) {
	int tileX = static_cast<int>(x) / 64;
	int tileY = static_cast<int>(y) / 64;

	if (tileX < 0 || tileY < 0 || tileX >= MapManager::MAP_WIDTH || tileY >= MapManager::MAP_HEIGHT) {
		// 範囲外はぶつかっている（壁）
		return true;
	}

	int tileID = mapData[tileY][tileX];
	bool result = BLOCK_TILE_IDS.count(tileID) > 0;

	std::cout << "Check tile (" << tileX << "," << tileY << ") = " << tileID
		<< " → " << (result ? "blocked" : "free") << std::endl;

	return result;
}


bool isBlockedArea(float centerX, float centerY, const VECTOR2& hSize) {
	float left = centerX - hSize.x;
	float right = centerX + hSize.x;
	float top = centerY - hSize.y;
	float bottom = centerY + hSize.y;

	// 微小な誤差を含めて、完全に端まで含めるように
	int leftTile = static_cast<int>(std::floor(left / 64.0f));
	int rightTile = static_cast<int>(std::floor((right - 0.001f) / 64.0f));
	int topTile = static_cast<int>(std::floor(top / 64.0f));
	int bottomTile = static_cast<int>(std::floor((bottom - 0.001f) / 64.0f));

	for (int y = topTile; y <= bottomTile; y++) {
		for (int x = leftTile; x <= rightTile; x++) {
			if (isBlocked(x * 64 + 32, y * 64 + 32)) {
				return true;
			}
		}
	}
	return false;
}


void judgeMapchip(OBJ2DManager& manager) {
	for (auto& item : manager) {
		float dirX = item.direction.x;
		float dirY = item.direction.y;

		float newX = item.position.x;
		float newY = item.position.y;

		// --- X方向 ---
		if (dirX != 0) {
			float tryX = newX + dirX;
			if (isBlockedArea(tryX, newY, item.hSize)) {
				// 衝突判定したのでX方向の移動停止
				item.direction.x = 0;

				if (dirX > 0) {
					// 右側の壁の端に移動
					newX = (int)((tryX + item.hSize.x) / 64) * 64 - item.hSize.x - 0.2f; // 余裕0.2fに増やし
				}
				else {
					// 左側の壁の端に移動
					newX = (int)((tryX - item.hSize.x) / 64 + 1) * 64 + item.hSize.x + 0.2f;
				}
			}
			else {
				newX = tryX;
			}
		}

		// --- Y方向 ---
		if (dirY != 0) {
			float tryY = newY + dirY;
			if (isBlockedArea(newX, tryY, item.hSize)) {
				// 衝突判定したのでY方向の移動停止
				item.direction.y = 0;

				if (dirY > 0) {
					// 下側の壁の端に移動
					newY = (int)((tryY + item.hSize.y) / 64) * 64 - item.hSize.y - 0.2f; // 余裕0.2fに増やし
				}
				else {
					// 上側の壁の端に移動
					newY = (int)((tryY - item.hSize.y) / 64 + 1) * 64 + item.hSize.y + 0.2f;
				}
			}
			else {
				newY = tryY;
			}
		}

		item.position = { newX, newY };
		item.isMoving = (item.direction.x != 0 || item.direction.y != 0);
	
	
	
	}
}
void judgeSub(OBJ2DManager& manager1, OBJ2DManager& manager2)
{
	for (auto& item1 : manager1)
	{
		if (!item1.mover) continue;

		JudgeRect rect1(item1.position, item1.hSize);
		// rect1があたり判定エリア外のとき、次のitem1へ
		if (!screenRect.isHit(rect1)) continue;

		for (auto& item2 : manager2)
		{
			if (!item2.mover) continue;
			if ((item1.judge & item2.judge) == 0) continue;

			JudgeRect rect2(item2.position, item2.hSize);
			// rect2があたり判定エリア外のとき、次のitem2へ
			if (!screenRect.isHit(rect2)) continue;

			if (rect1.isHit(rect2))
			{
				// 押し戻す方向を計算
				VECTOR2 pushDir = item1.position - item2.position;
				float lenSq = vec2LengthSq(pushDir);

				if (lenSq > 0.01f)
				{
					VECTOR2 normal = vec2Normalize(pushDir);
					float overlapX = (item1.hSize.x + item2.hSize.x) - std::abs(item1.position.x - item2.position.x);
					float overlapY = (item1.hSize.y + item2.hSize.y) - std::abs(item1.position.y - item2.position.y);

					//overlapX = 1.0;
					//overlapY = 1.0;

					// より重なりが大きい方向に補正（軸ごとにずらす）
					if (overlapX < overlapY)
					{
						if (item1.position.x < item2.position.x)
						{
							item1.hitRight = true;
							item2.hitLeft = true;
						}
						else
						{
							item1.hitLeft = true;
							item2.hitRight = true;
						}
						item1.position.x += (item1.position.x < item2.position.x) ? -overlapX - 0.1f : overlapX + 0.1f;
					}
					else
					{
						if (item1.position.y < item2.position.y)
						{
							item1.hitBottom = true;
							item2.hitTop = true;
						}

						else
						{
							item1.hitTop = true;
							item2.hitBottom = true;
						}


						item1.position.y += (item1.position.y < item2.position.y) ? -overlapY - 0.1f : overlapY + 0.1f;

						////////
					}
				}
				direction_reset(&item1);

				break;
			}
		}
	}
}

void judgeSub_sd(OBJ2DManager& manager1, OBJ2DManager& manager2)
{
	for (auto& item1 : manager1)
	{
		if (!item1.mover) continue;

		JudgeRect rect1(item1.position, item1.hSize);
		// rect1があたり判定エリア外のとき、次のitem1へ
		if (!screenRect.isHit(rect1)) continue;

		for (auto& item2 : manager2)
		{
			if (!item2.mover) continue;
			if ((item1.judge & item2.judge) == 0) continue;

			JudgeRect rect2(item2.position, item2.hSize);
			// rect2があたり判定エリア外のとき、次のitem2へ
			if (!screenRect.isHit(rect2)) continue;

			if (rect1.isHit(rect2))
			{
				// 押し戻す方向を計算
				VECTOR2 pushDir = item1.position - item2.position;
				float lenSq = vec2LengthSq(pushDir);

				if (lenSq > 0.01f)
				{
					VECTOR2 normal = vec2Normalize(pushDir);
					float overlapX = (item1.hSize.x + item2.hSize.x) - std::abs(item1.position.x - item2.position.x);
					float overlapY = (item1.hSize.y + item2.hSize.y) - std::abs(item1.position.y - item2.position.y);

					//overlapX = 1.0;
					//overlapY = 1.0;




					/////////////////
					// より重なりが大きい方向に補正（軸ごとにずらす）
					if (overlapX < overlapY)
					{
						if (item1.position.x < item2.position.x)
						{
							item1.hitRight = true;
							item2.hitLeft = true;
						}
						else
						{
							item1.hitLeft = true;
							item2.hitRight = true;
						}
						item1.position.x += (item1.position.x < item2.position.x) ? -overlapX - 0.1f : overlapX + 0.1f;
					}
					else
					{
						if (item1.position.y < item2.position.y)
						{
							item1.hitBottom = true;
							item2.hitTop = true;
						}

						else
						{
							item1.hitTop = true;
							item2.hitBottom = true;
						}
						item1.position.y += (item1.position.y < item2.position.y) ? -overlapY - 0.1f : overlapY + 0.1f;
						///////
					}
				}
				direction_sd_reset(&item1);

				break;
			}
		}
	}
}

void judgePvP(OBJ2DManager& manager1, OBJ2DManager& manager2)
{
	for (auto& item1 : manager1)
	{
		if (!item1.mover) continue;

		JudgeRect rect1(item1.position, item1.hSize);
		// rect1があたり判定エリア外のとき、次のitem1へ

		if (!screenRect.isHit(rect1)) continue;

		for (auto& item2 : manager2)
		{
			if (!item2.mover) continue;
			
			//if ((item1.judge & item2.judge) == 0) continue;

			JudgeRect rect2(item2.position, item2.hSize);
			// rect2があたり判定エリア外のとき、次のitem2へ
			if (!screenRect.isHit(rect2)) continue;

			if (rect1.isHit(rect2))
			{
				// 押し戻す方向を計算
				VECTOR2 pushDir = item1.position - item2.position;
				float lenSq = vec2LengthSq(pushDir);

				if (lenSq > 0.01f)
				{
					VECTOR2 normal = vec2Normalize(pushDir);
					float overlapX = (item1.hSize.x + item2.hSize.x) - std::abs(item1.position.x - item2.position.x);
					float overlapY = (item1.hSize.y + item2.hSize.y) - std::abs(item1.position.y - item2.position.y);

					//overlapX = 1.0;
					//overlapY = 1.0;
					if (rect1.isHit(rect2))
					{
						// より重なりが大きい方向に補正（軸ごとにずらす）
						if (overlapX < overlapY)
						{
							if (item1.position.x < item2.position.x)
							{
								item1.hitRight = true;
								item2.hitLeft = true;
							}
							else
							{
								item1.hitLeft = true;
								item2.hitRight = true;
							}
							item1.position.x += (item1.position.x < item2.position.x) ? -overlapX - 0.1f : overlapX + 0.1f;
							//0.1f,ここで壁の隙間を増やす
						}
						else
						{
							if (item1.position.y < item2.position.y)
							{
								item1.hitBottom = true;
								item2.hitTop = true;
							}

							else
							{
								item1.hitTop = true;
								item2.hitBottom = true;
							}
							item1.position.y += (item1.position.y < item2.position.y) ? -overlapY - 0.1f : overlapY + 0.1f;

							/////
						}
					}
				}

				direction_reset(&item1);
				direction_reset(&item2);

				break; // 一つに対してのみ反応（必要ならcontinueに変更）
			}
		}
	}
}