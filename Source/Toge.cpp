#include "Toge.h"
#include "Spritedata.h"


//�S�[���̐ݒu
void set_Toge(OBJ2D* obj)
{
	switch (obj->state)
	{
	case 0:
		//�����蔻��̐ݒ�
		obj->hSize = { 64 / 2, 64 / 2 };
		obj->judge = JUDGE_ALL;

		//�e��f�[�^
		obj->sprData = &sprToge;

		obj->state++;
		[[fallthrough]];
	case 1:
		break;
	}
}

