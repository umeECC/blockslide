#include "Wall.h"
#include "Spritedata.h"


//�ǂ̐ݒu
void set_wall(OBJ2D* obj)
{
	switch (obj->state)
	{
	case 0:
		//�����蔻��̐ݒ�
		obj->hSize = { 32, 32 };
		obj->judge = JUDGE_ALL;

		//�e��f�[�^
		obj->sprData = &sprWall;

		obj->state++;
		[[fallthrough]];
	case 1:
		break;
	}
}
void set_hako(OBJ2D* obj)
{
	switch (obj->state)
	{
	case 0:
		//�����蔻��̐ݒ�
		obj->hSize = { 32, 32 };
		obj->judge = JUDGE_ALL;

		//�e��f�[�^
		obj->sprData = &sprHako;

		obj->state++;
		[[fallthrough]];
	case 1:
		break;
	}
}