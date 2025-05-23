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
	judgeSub(MapManager::getInstance(), PlayerManager::getInstance());
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
		return true;

	int tileID = mapData[tileY][tileX];
	return BLOCK_TILE_IDS.count(tileID) > 0;  // �� �������{���g��������������I
}
void judgeMapchip(OBJ2DManager& manager1, OBJ2DManager& manager2) {
	for (auto& item1 : manager1) {
		float dirX = item1.direction.x;
		float dirY = item1.direction.y;

		// �ړ��O�̈ʒu��ۑ�
		float posX = item1.position.x;
		float posY = item1.position.y;

		// X�����̏Փ˔���
		if (dirX != 0) {
			float nextX = posX + dirX;
			// �I�u�W�F�N�g�̍��[�ƉE�[���v�Z
			float leftX = nextX - item1.hSize.x;
			float rightX = nextX + item1.hSize.x;
			float topY = posY - item1.hSize.y;
			float bottomY = posY + item1.hSize.y;

			// ���[�ƉE�[�A���ꂼ��̃^�C�����W���v�Z����
			// Y�����͏�[���牺�[�܂ł͈̔͂��J�o�[����悤�����`�F�b�N����̂����z

			bool blocked = false;

			// Y�����ɕ����_���`�F�b�N�i�㉺�̒[�{�����j
			std::vector<float> checkYs = { topY, posY, bottomY };

			for (float yCheck : checkYs) {
				float checkX = (dirX > 0) ? rightX : leftX;
				if (isBlocked(checkX, yCheck)) {
					blocked = true;
					break;
				}
			}

			if (blocked) {
				item1.direction.x = 0;
				if (dirX > 0) {
					// �E�����Ȃ̂ŉE�[��ǃ^�C���̍��[�ɍ��킹��
					int tileX = static_cast<int>(rightX) / 64;
					item1.position.x = tileX * 64 - item1.hSize.x - 0.01f;
				}
				else {
					// ������
					int tileX = static_cast<int>(leftX) / 64;
					item1.position.x = (tileX + 1) * 64 + item1.hSize.x + 0.01f;
				}
			}
			else {
				item1.position.x = nextX;
			}
		}
		else {
			// X�ړ��Ȃ�
			item1.position.x = posX;
		}

		// Y�����̏Փ˔���
		if (dirY != 0) {
			float nextY = posY + dirY;
			float leftX = item1.position.x - item1.hSize.x;
			float rightX = item1.position.x + item1.hSize.x;
			float topY = nextY - item1.hSize.y;
			float bottomY = nextY + item1.hSize.y;

			bool blocked = false;

			// X�����ɕ����_�`�F�b�N�i���E�̒[�{�����j
			std::vector<float> checkXs = { leftX, item1.position.x, rightX };

			for (float xCheck : checkXs) {
				float checkY = (dirY > 0) ? bottomY : topY;
				if (isBlocked(xCheck, checkY)) {
					blocked = true;
					break;
				}
			}

			if (blocked) {
				item1.direction.y = 0;
				if (dirY > 0) {
					int tileY = static_cast<int>(bottomY) / 64;
					item1.position.y = tileY * 64 - item1.hSize.y - 0.01f;
				}
				else {
					int tileY = static_cast<int>(topY) / 64;
					item1.position.y = (tileY + 1) * 64 + item1.hSize.y + 0.01f;
				}
			}
			else {
				item1.position.y = nextY;
			}
		}
		else {
			// Y�ړ��Ȃ�
			item1.position.y = posY;
		}

		// �ړ��t���O
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