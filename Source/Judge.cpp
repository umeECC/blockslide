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

// �v���g�^�C�v�錾
void judgeSub(OBJ2DManager& manager1, OBJ2DManager& manager2);
//void judgePvP(OBJ2DManager& manager1, OBJ2DManager& manager2);
void judgePvP(OBJ2DManager& manager);
void judgeMapchip(OBJ2DManager& manager1, OBJ2DManager& manager2);


JudgeRect screenRect = {
	64, 64, SCREEN_WIDTH - 64, SCREEN_HEIGHT - 64,
};

void judge()
{
	//�v���C���[VS��
	judgeSub(PlayerManager::getInstance(), MapManager::getInstance());
	judgeMapchip(PlayerManager::getInstance(),MapManager::getInstance());
	//// �v���C���[2VS��
	//judgeSub(PlayerManager_sd::getInstance(), WallManager::getInstance());

	// �v���C���[VS�v���C���[2
	judgePvP(PlayerManager::getInstance());

	//judgeMapchip(PlayerManager::getInstance());

}
std::set<int> BLOCK_TILE_IDS = { 1, 2, 3 }; // �Ⴆ��1, 2, 3�͕�

bool isBlocked(float x, float y) {
	int tileX = static_cast<int>(x) / 64;
	int tileY = static_cast<int>(y) / 64;

	if (tileX < 0 || tileY < 0 || tileX >= MapManager::MAP_WIDTH || tileY >= MapManager::MAP_HEIGHT)
		return true; // �}�b�v�O�̓u���b�N�Ƃ݂Ȃ�

	int tileID = mapData[tileY][tileX];

	// tileID���u���b�N��ID���X�g�Ɋ܂܂�Ă��邩�H
	return BLOCK_TILE_IDS.count(tileID) > 0;
}

void judgeMapchip(OBJ2DManager& manager1, OBJ2DManager& manager2) {
	for (auto& item1 : manager1) {
		bool blockedX = false;
		bool blockedY = false;

		// ���݂̕�����ۑ����Ă����i�␳�p�j
		float dirX = item1.direction.x;
		float dirY = item1.direction.y;

		// ���̈ʒu
		float nextX = item1.position.x + dirX;
		float nextY = item1.position.y + dirY;

		// --- X�����̔��� ---
		if (isBlocked(nextX, item1.position.y)) {
			blockedX = true;
			item1.direction.x = 0;

			if (dirX > 0) {
				item1.position.x = static_cast<int>(item1.position.x / 64) * 64;
			}
			else if (dirX < 0) {
				item1.position.x = static_cast<int>(item1.position.x / 64 + 1) * 64;
			}
		}

		// --- Y�����̔��� ---
		if (isBlocked(item1.position.x, nextY)) {
			blockedY = true;
			item1.direction.y = 0;

			if (dirY > 0) {
				item1.position.y = static_cast<int>(item1.position.y / 64) * 64;
			}
			else if (dirY < 0) {
				item1.position.y = static_cast<int>(item1.position.y / 64 + 1) * 64;
			}
		}

		// �ړ��p���t���O
		item1.isMoving = (item1.direction.x != 0 || item1.direction.y != 0);
	}
}

void judgeSub(OBJ2DManager& manager1, OBJ2DManager& manager2)
{
	for (auto& item1 : manager1)
	{
		if (!item1.mover) continue;

		JudgeRect rect1(item1.position, item1.hSize);
		// rect1�������蔻��G���A�O�̂Ƃ��A����item1��
		if (!screenRect.isHit(rect1)) continue;

		for (auto& item2 : manager2)
		{
			if (!item2.mover) continue;
			if ((item1.judge & item2.judge) == 0) continue;

			JudgeRect rect2(item2.position, item2.hSize);
			// rect2�������蔻��G���A�O�̂Ƃ��A����item2��
			if (!screenRect.isHit(rect2)) continue;

			if (rect1.isHit(rect2))
			{
				// �����߂��������v�Z
				VECTOR2 pushDir = item1.position - item2.position;
				float lenSq = vec2LengthSq(pushDir);

				if (lenSq > 0.01f)
				{
					VECTOR2 normal = vec2Normalize(pushDir);
					float overlapX = (item1.hSize.x + item2.hSize.x) - std::abs(item1.position.x - item2.position.x);
					float overlapY = (item1.hSize.y + item2.hSize.y) - std::abs(item1.position.y - item2.position.y);

					//overlapX = 1.0;
					//overlapY = 1.0;

					// ���d�Ȃ肪�傫�������ɕ␳�i�����Ƃɂ��炷�j
					if (overlapX < overlapY)
						item1.position.x += (item1.position.x < item2.position.x) ? -overlapX - 0.1f : overlapX + 0.1f;//0.1f,�����ŕǂ̌��Ԃ𑝂₷
					else
						item1.position.y += (item1.position.y < item2.position.y) ? -overlapY - 0.1f : overlapY + 0.1f;
				}
				direction_reset(&item1);

				break;
			}
		}
	}
}


void judgePvP(OBJ2DManager& manager)
{
	for (auto& item1 : manager)
	{
		if (!item1.mover) continue;

		JudgeRect rect1(item1.position, item1.hSize);
		// rect1�������蔻��G���A�O�̂Ƃ��A����item1��
		if (!screenRect.isHit(rect1)) continue;

		for (auto& item2 : manager)
		{
			if (!item2.mover) continue;
			if (&item1 == &item2) continue;
			if ((item1.judge & item2.judge) == 0) continue;

			JudgeRect rect2(item2.position, item2.hSize);
			// rect2�������蔻��G���A�O�̂Ƃ��A����item2��
			if (!screenRect.isHit(rect2)) continue;

			if (rect1.isHit(rect2))
			{
				// �����߂��������v�Z
				VECTOR2 pushDir = item1.position - item2.position;
				float lenSq = vec2LengthSq(pushDir);

				if (lenSq > 0.01f)
				{
					VECTOR2 normal = vec2Normalize(pushDir);
					float overlapX = (item1.hSize.x + item2.hSize.x) - std::abs(item1.position.x - item2.position.x);
					float overlapY = (item1.hSize.y + item2.hSize.y) - std::abs(item1.position.y - item2.position.y);

					//overlapX = 1.0;
					//overlapY = 1.0;

					// ���d�Ȃ肪�傫�������ɕ␳�i�����Ƃɂ��炷�j
					if (overlapX < overlapY)
						item1.position.x += (item1.position.x < item2.position.x) ? -overlapX - 0.1f : overlapX + 0.1f;//0.1f,�����ŕǂ̌��Ԃ𑝂₷
					else
						item1.position.y += (item1.position.y < item2.position.y) ? -overlapY - 0.1f : overlapY + 0.1f;
				}

				direction_reset(&item1);
				direction_reset(&item2);

				break; // ��ɑ΂��Ă̂ݔ����i�K�v�Ȃ�continue�ɕύX�j
			}
		}
	}
}