#pragma once
#include "Obj2d.h"
#include "Template.h"

// �G�L���������f�[�^�i������X�e�[�W�X�N���v�g�ɂȂ�j
struct StageScript
{
	int				time;		// �C�x���g��������
	OBJ2D::MOVER	mover;		// �ړ�����
	VECTOR2			position;	// ���W
};

// �X�N���v�g�}�N��
#define SET_ENEMY(time,x,y,mover)		{(time),(mover),{(x),(y)}}
#define SET_ITEM(time,x,y,mover)		{(time),(mover),{(x),(y)}}
#define SET_END						{0,0,{0,0}}

// Stage�N���X
class Stage : public Singleton<Stage>
{
	int timer;
	StageScript* pScript;

public:
	void init();
	void update();
	void draw();
};

