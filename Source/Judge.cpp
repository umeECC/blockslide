#include "Judge.h"
#include "Player.h"
#include <iostream>
#include "Effect.h"

static constexpr float PLAYER_RADIUS = 64 * 0.8f;
static constexpr float LAGE_PLAYER_RAD = 64 * 1.2f;
//static constexpr float ITEM_RADIUS = 32 * 0.8f;
//static constexpr float ENEMY_RADIUS = 32;

void judge()
{
	/*//�v���C���[VS��
	for (auto& player : PlayerRManager::getInstance()) {		//���ׂẴv���C���[�ɑ΂���
		if (!player.mover)continue;							//�v���C���[�����݂��Ȃ��Ƃ��͎��̃v���C���[��

		for (auto& item : ItemManager::getInstance()) {	//���ׂẴA�C�e���ɑ΂���
			if (!item.mover) continue;						//�A�C�e�������݂��Ȃ��Ƃ��͎��̃A�C�e����
			//item->player�ւ̓����蔻��
			VECTOR2 pe_vector = item.position - player.position;
			float LengthSq = vec2LengthSq(pe_vector);

			float R = PLAYER_RADIUS + ITEM_RADIUS;
			if (item_range) {
				R = LAGE_PLAYER_RAD + ITEM_RADIUS;
			}
			if (LengthSq <= R * R)
			{
				switch (item.item)
				{
				case PLAYER_POWER_UP:
					item_power = true;
					break;
				case PLAYER_SPEED_UP:
					item_speed = true;
					break;
				case PLAYER_RANGE_UP:
					item_range = true;
					break;
				}

				item.clear();
			}
		}
	}
	//�v���C���[VS��
	for (auto& player : PlayerRManager::getInstance()) {		//���ׂẴv���C���[�ɑ΂���
		if (!player.mover)continue;							//�v���C���[�����݂��Ȃ��Ƃ��͎��̃v���C���[��

		for (auto& enemy : EnemyManager::getInstance()) {	//���ׂẴA�C�e���ɑ΂���
			if (!enemy.mover) continue;						//�A�C�e�������݂��Ȃ��Ƃ��͎��̃A�C�e����
			//enemy->player�ւ̓����蔻��
			VECTOR2 pe_vector = enemy.position - player.position;
			float LengthSq = vec2LengthSq(pe_vector);

			float R = PLAYER_RADIUS + ENEMY_RADIUS;
			if (item_range) {
				R = LAGE_PLAYER_RAD + ENEMY_RADIUS;
			}
			if (LengthSq <= R * R)
			{
				if (enemy.index == 0)
				{
					EffectManager::getInstance().searchSet(effectExplos, enemy.position);
					enemy.clear();
					enemy.mover = enemyUpdate;
					player.score += 100;
				}
				if (enemy.index == 2)
				{
					dualenemyR = true;
				}
				else
				{
					dualenemyR = false;
				}

			}
		}
	}*/
	
}