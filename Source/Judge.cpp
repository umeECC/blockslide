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
//<<<<<<< HEAD
//void judgeSub(OBJ2DManager& manager1, OBJ2DManager& manager2);
//void judgePvP(OBJ2DManager& manager1, OBJ2DManager& manager2);
//void judgePvP(OBJ2DManager& manager);
//=======
void judgeSub(OBJ2DManager& manager1, OBJ2DManager& manager2);
void judgeSub_sd(OBJ2DManager& manager1, OBJ2DManager& manager2);
void judgePvP(OBJ2DManager& manager1, OBJ2DManager& manager2);
//>>>>>>> 8113188c39b1fdae03c8a084409f8f883018e1e6
void judgeMapchip(OBJ2DManager& manager1);
void judgeMapchip_sd(OBJ2DManager& manager1);


JudgeRect screenRect = {
	64, 64, SCREEN_WIDTH - 64, SCREEN_HEIGHT - 64,
};

void judge()
{
	// �v���C���[VS��
	judgeMapchip(PlayerManager::getInstance());
	judgeMapchip_sd(PlayerManager_sd::getInstance());
//>>>>>>> 8113188c39b1fdae03c8a084409f8f883018e1e6

	// �v���C���[2VS��
	//judgeSub_sd(PlayerManager_sd::getInstance(), WallManager::getInstance());

	//judgeSub(MapManager::getInstance(), PlayerManager::getInstance());
	
	// �v���C���[VS�v���C���[2
	judgePvP(PlayerManager::getInstance(), PlayerManager_sd::getInstance());

	// ���܂�`�F�b�N�F�㉺ + ���E�̗��������܂��Ă�����
	if (PlayerManager::getInstance().checkpress())
	{
		setScene(SCENE::OVER);// ���Q�[���I�[�o�[��ʂɐ؂�ւ���֐�
		return; // �ȍ~�̏����s�v
	}
}



std::set<int> BLOCK_TILE_IDS = { 1, 2, 3 }; // �Ⴆ��1, 2, 3�͕�

bool isBlocked(float x, float y) {
	int tileX = static_cast<int>(x) / 64;
	int tileY = static_cast<int>(y) / 64;

	if (tileX < 0 || tileY < 0 || tileX >= MapManager::MAP_WIDTH || tileY >= MapManager::MAP_HEIGHT) {
		std::cout << "Out of bounds: (" << tileX << "," << tileY << ") �� blocked" << std::endl;
		return true;
	}

	int tileID = mapData[tileY][tileX];
	bool result = BLOCK_TILE_IDS.count(tileID) > 0;

	std::cout << "Check tile (" << tileX << "," << tileY << ") = " << tileID
		<< " �� " << (result ? "blocked" : "free") << std::endl;

	return result;
}


bool isBlockedArea(float centerX, float centerY, const VECTOR2& hSize) {
	float left = centerX - hSize.x;
	float right = centerX + hSize.x;
	float top = centerY - hSize.y;
	float bottom = centerY + hSize.y;

	// �E�[�E���[���܂߂邽�߂� +1
	int leftTile = static_cast<int>(std::floor(left  / 64.0f));
	int rightTile = static_cast<int>(std::floor(right  / 64.0f));  // �� ceil -1 �� floor �ɕύX
	int topTile = static_cast<int>(std::floor(top / 64.0f));
	int bottomTile = static_cast<int>(std::floor(bottom / 64.0f)); // �� ����
	
	for (int y = topTile; y <= bottomTile; y++) {
		for (int x = leftTile; x <= rightTile; x++) {
			if (x < 0 || y < 0 || x >= MapManager::MAP_WIDTH || y >= MapManager::MAP_HEIGHT) {
				return true;
			}

			int tileID = mapData[y][x];
			if (BLOCK_TILE_IDS.count(tileID) > 0) {
				float tileLeft = x * 64.0f;
				float tileRight = tileLeft + 64.0f;
				float tileTop = y * 64.0f;
				float tileBottom = tileTop + 64.0f;

				bool isOverlap = !(right <= tileLeft || left >= tileRight || bottom <= tileTop || top >= tileBottom);
				if (isOverlap) {
					return true;
				}
			}
		}
	}
	leftTile += 30;
	rightTile += 30;
	topTile  += 30;
		bottomTile;
	return false;
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


void judgePvP(OBJ2DManager& manager,OBJ2DManager&manager2)
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

					// ���d�Ȃ肪�傫�������ɕ␳�i�����Ƃɂ��炷)
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
void judgeMapchip(OBJ2DManager& manager) {
	constexpr float TILE_SIZE = 74.0f;

	for
		(auto& item : manager) {
		float dirX = item.direction.x;
		float dirY = item.direction.y;

		// ���݈ʒu�ێ�
		float newX = item.position.x;
		float newY = item.position.y;
		if (!item.mover) continue;

		JudgeRect rect1(item.position, item.hSize);
		if (!screenRect.isHit(rect1)) continue;

		float left = item.position.x - item.hSize.x;
		float right = item.position.x + item.hSize.x;
		float top = item.position.y - item.hSize.y;
		float bottom = item.position.y + item.hSize.y;

		int leftTile = static_cast<int>(std::floor(left / TILE_SIZE));
		int rightTile = static_cast<int>(std::floor(right / TILE_SIZE));
		int topTile = static_cast<int>(std::floor(top / TILE_SIZE));
		int bottomTile = static_cast<int>(std::floor(bottom / TILE_SIZE));

		

		if (dirX != 0) {
			float tryX = newX + dirX;
			if (isBlockedArea(tryX, newY, item.hSize)) {
				item.direction.x = 0;

				if (dirX > 0)
					newX = (int)((tryX + item.hSize.x) / 64 - 1) * 64 + item.hSize.x - 0.1f;
				else
					newX = (int)((tryX - item.hSize.x) / 64 + 1) * 64 + item.hSize.x + 0.1f;
			}
			else {
				newX = tryX;
			}
		}
		if (dirY != 0) {
			float tryY = newY + dirY;
			if (isBlockedArea(newX, tryY, item.hSize)) {
				item.direction.y = 0;

				if (dirY > 0)
					newY = (int)((tryY + item.hSize.y) / 64 - 1) * 64 + item.hSize.y - 0.1f;
				else
					newY = (int)((tryY - item.hSize.y) / 64 + 1) * 64 + item.hSize.y + 0.1f;
			}
			else {
				newY = tryY;
			}
		}
		// --- X�����̈ړ��`�F�b�N ---
		if (dirX != 0) {
			float tryX = newX + dirX;

			// �Փ˂�������������~�߂�B�ʒu�͕␳���Ȃ��B
			if (isBlockedArea(tryX, newY, item.hSize)) {
				item.direction.x = 0;
			}
			else {
				newX = tryX;
			}
		}

		// --- Y�����̈ړ��`�F�b�N ---
		if (dirY != 0) {
			float tryY = newY + dirY;

			// �Փ˂�������������~�߂�B�ʒu�͕␳���Ȃ��B
			if (isBlockedArea(newX, tryY, item.hSize)) {
				item.direction.y = 0;
			}
			else {
				newY = tryY;
			}
		}

		// �X�V
		item.position = { newX, newY };
		item.isMoving = (item.direction.x != 0 || item.direction.y != 0);
	
	
	
	}
}
//<<<<<<< HEAD


//=======
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




					/////////////////
					// ���d�Ȃ肪�傫�������ɕ␳�i�����Ƃɂ��炷�j
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
					if (rect1.isHit(rect2))
					{
						// ���d�Ȃ肪�傫�������ɕ␳�i�����Ƃɂ��炷�j
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
							//0.1f,�����ŕǂ̌��Ԃ𑝂₷
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

				break; // ��ɑ΂��Ă̂ݔ����i�K�v�Ȃ�continue�ɕύX�j
			}
		}
	}
}
//>>>>>>> 8113188c39b1fdae03c8a084409f8f883018e1e6
