#include "Goal.h"
#include "Spritedata.h"


//�S�[���̐ݒu
void set_goal(OBJ2D* obj)
{
	switch (obj->state)
	{
	case 0:
		//�����蔻��̐ݒ�
		obj->hSize = { 64 / 2, 64 / 2 };
		obj->judge = JUDGE_GOAL;

		//�e��f�[�^
		obj->sprData = &sprGoal;

		obj->state++;
		[[fallthrough]];
	case 1:
		break;
	}
}