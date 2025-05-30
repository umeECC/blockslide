#include "Judge.h"
#include "WinMain.h"
#include "Player.h"
#include "Player_sd.h"
#include <iostream>
#include "Effect.h"
#include "Wall.h"
#include "Goal.h"

bool player_goaled;

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

void judgeSub_sd(OBJ2DManager& manager1, OBJ2DManager& manager2);

void judgePvP(OBJ2DManager& manager1, OBJ2DManager& manager2);

void judgeGoal(OBJ2DManager& playerManager, OBJ2DManager& goalManager);

void judgeToge(OBJ2DManager& manager1, OBJ2DManager& manager2);

void judgeSub_sd2(OBJ2DManager& manager1, OBJ2DManager& manager2);
JudgeRect screenRect = {
	64, 64, SCREEN_WIDTH - 64, SCREEN_HEIGHT - 64,
};

void judge()
{
	// �����ł������񂷂ׂāi�v���C���[�j�̃`�F�b�N�����Z�b�g
	PlayerManager::getInstance().clearHit();
	PlayerManager_sd::getInstance().clearHit();

	//�v���C���[VS��
	judgeSub(PlayerManager::getInstance(), WallManager::getInstance());
	
	// �v���C���[2�i�����ǁjVS��
	judgeSub_sd(PlayerManager_sd::getInstance(), WallManager::getInstance());

	judgeSub_sd2(PlayerManager_sd::getInstance(), WallManager::getInstance());


	for (int i = 0; i < 35; ++i) {
		judgeSub_sd2(PlayerManager_sd::getInstance(), PlayerManager_sd::getInstance());
	
		// �v���C���[VS�v���C���[2�i�����ǁj
		judgePvP(PlayerManager::getInstance(), PlayerManager_sd::getInstance());
	}
	judgeSub_sd2(PlayerManager_sd::getInstance(), PlayerManager_sd::getInstance());
	
	
	// �v���C���[VS�v���C���[2�i�����ǁj
	judgePvP(PlayerManager::getInstance(), PlayerManager_sd::getInstance());



	// ���܂�`�F�b�N�F�㉺ + ���E�̗��������܂��Ă�����
	if (PlayerManager::getInstance().checkpress())
	{

		setScene(SCENE::OVER);// ���Q�[���I�[�o�[��ʂɐ؂�ւ���֐�
		return; // �ȍ~�̏����s�v
	}
	//�������Ă�����
	if(PlayerManager::getInstance().checkhit())
	{

		setScene(SCENE::OVER);// ���Q�[���I�[�o�[��ʂɐ؂�ւ���֐�
		return; // �ȍ~�̏����s�v
	}

	// �v���C���[VS�S�[���i�ǉ��j
	judgeGoal(PlayerManager::getInstance(), GoalManager::getInstance());
	
	/*PlayerManager::getInstance().clearHit();
	PlayerManager_sd::getInstance().clearHit();
	WallManager::getInstance().clearHit();*/
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


			for (auto& item2 : manager2)
			{
				if (!item2.mover) continue;
				if ((item1.judge & item2.judge) == 0) continue;

				JudgeRect rect2(item2.position, item2.hSize);
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

						overlapX += 1.0;
						overlapY += 1.0;

					// �d�Ȃ�������Ƃɔ���
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

						}
					}
					direction_reset(&item1);

					break;
				}
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

					overlapX += 1.0;
					overlapY += 1.0;

					// ���d�Ȃ肪�傫�������ɕ␳�i�����Ƃɂ��炷�j
					if (overlapX < overlapY)
					{
						/*if (item1.position.x < item2.position.x)
						{
							item1.hitRight = true;
							item2.hitLeft = true;
						}
						else
						{
							item1.hitLeft = true;
							item2.hitRight = true;
						}*/
						item1.position.x += (item1.position.x < item2.position.x) ? -overlapX - 0.1f : overlapX + 0.1f;
					}
					else
					{
						/*if (item1.position.y < item2.position.y)
						{
							item1.hitBottom = true;
							item2.hitTop = true;
						}

						else
						{
							item1.hitTop = true;
							item2.hitBottom = true;
						}*/
						item1.position.y += (item1.position.y < item2.position.y) ? -overlapY - 0.1f : overlapY + 0.1f;
						
					}
				}
				direction_sd_reset(&item1);

				break;
			}
		}
	}
}
bool isPlayerSB(const OBJ2D& item)
{
	// ��: ����t���O�� player_sb ����肷��
	return (item.judge & JUDGE_ALL) != 0;
}

void judgeSub_sd2(OBJ2DManager& manager1, OBJ2DManager& manager2)
{
	for (auto& item1 : manager1)
	{
		if (!item1.mover) continue;

		JudgeRect rect1(item1.position, item1.hSize);
		if (!screenRect.isHit(rect1)) continue;

		for (auto& item2 : manager2)
		{
			if (!item2.mover) continue;
			if (&item1 == &item2) continue;
			if ((item1.judge & item2.judge) == 0) continue;

			JudgeRect rect2(item2.position, item2.hSize);
			if (!screenRect.isHit(rect2)) continue;

			if (rect1.isHit(rect2))
			{
				// player_sb ���m�Ȃ牟���߂��͌y���A�����͎~�߂�
				if (isPlayerSB(item1) && isPlayerSB(item2))
				{
					// �d�Ȃ���y����������i�����ڂ̂߂荞�܂Ȃ��悤�Ɂj
					VECTOR2 pushDir = item1.position - item2.position;
					float lenSq = vec2LengthSq(pushDir);

					if (lenSq > 0.01f)
					{
						float overlapX = (item1.hSize.x + item2.hSize.x) - std::abs(item1.position.x - item2.position.x);
						float overlapY = (item1.hSize.y + item2.hSize.y) - std::abs(item1.position.y - item2.position.y);

						// �ŏ����̕␳�Ō����ڂ�������
						if (overlapX < overlapY)
						{
							item1.position.x += (item1.position.x < item2.position.x) ? -overlapX * 0.5f : overlapX * 0.5f;
						}
						else
						{
							item1.position.y += (item1.position.y < item2.position.y) ? -overlapY * 0.5f : overlapY * 0.5f;
						}
					}

					// �����͎~�߂�
					direction_sd_reset(&item1);
					break;
				}

				// �ʏ�̉����߂�
				VECTOR2 pushDir = item1.position - item2.position;
				float lenSq = vec2LengthSq(pushDir);

				if (lenSq > 0.01f)
				{
					float overlapX = (item1.hSize.x + item2.hSize.x) - std::abs(item1.position.x - item2.position.x);
					float overlapY = (item1.hSize.y + item2.hSize.y) - std::abs(item1.position.y - item2.position.y);

					overlapX += 1.0f;
					overlapY += 1.0f;

					if (overlapX < overlapY)
					{
						item1.position.x += (item1.position.x < item2.position.x) ? -overlapX - 0.1f : overlapX + 0.1f;
					}
					else
					{
						item1.position.y += (item1.position.y < item2.position.y) ? -overlapY - 0.1f : overlapY + 0.1f;
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
						///////
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
				direction_sd_reset(&item2);
				break;
			}
		}
	}
}

void judgeGoal(OBJ2DManager& playerManager, OBJ2DManager& goalManager)
{
	for (auto& player : playerManager)
	{
		if (!player.mover) continue;

		JudgeRect rectP(player.position, player.hSize);
		//if (!screenRect.isHit(rectP)) continue;

		for (auto& goal : goalManager)
		{
			if (!goal.mover) continue;
			if ((player.judge & goal.judge) == 0) continue;

			JudgeRect rectG(goal.position, goal.hSize);
			//if (!screenRect.isHit(rectG)) continue;

			// �������: �ʒu����v
			if (rectP.isHit(rectG))
			{

				if (std::abs(goal.position.x - player.position.x) < 0.1f &&
					std::abs(goal.position.y - player.position.y) < 0.1f)
				{

					player_goaled = true;

					//setScene(SCENE::OVER);
					// �����ɃX�e�[�W�N���A�����Ȃǂ�����

				}
			}
		}
	}
}

void judgeToge(OBJ2DManager& manager1, OBJ2DManager& manager2)
{


}

