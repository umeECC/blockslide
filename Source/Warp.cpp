#include "Warp.h"
#include "SpriteData.h"



void set_warp(OBJ2D* obj)
{
	switch (obj->state)
	{
	case 0:
		//�����蔻��̐ݒ�
		obj->hSize = { 32, 32 };
		obj->judge = JUDGE_ALL;

		//�e��f�[�^
		obj->sprData = &sprWarp;

		obj->state++;
		[[fallthrough]];
	case 1:
		//// �Փ˔���`�F�b�N
		//if (OBJ2DManager::checkhit(obj, player)) // �Փ˂��Ă�����
		//{
		//	// ���[�v����W
		//	player->pos.x = 100; // �C�ӂ�X���W
		//	player->pos.y = 200; // �C�ӂ�Y���W
		//}

		break;
	}
}