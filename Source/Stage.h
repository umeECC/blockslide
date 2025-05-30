#pragma once
#include "Obj2d.h"
#include "Template.h"

enum ScriptType
{
	TYPE_NONE = 0,
	TYPE_WALL,
	TYPE_GOAL,
	TYPE_WARP,
};

// �����f�[�^
struct StageScript
{
	int				time;		// �C�x���g��������
	ScriptType		type;		// ���
	OBJ2D::MOVER	mover;		// �ړ�����
	VECTOR2			position;	// ���W
};

// �X�N���v�g�}�N��
#define SET_OBJ(time,x,y,mover,type)		{(time),(type),(mover),{(x),(y)}}
#define SET_END						{0,TYPE_NONE,0,{0,0}}

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
