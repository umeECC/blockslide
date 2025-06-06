#include "Stage.h"
#include "Back.h"
#include "Player.h"
#include "Player_sd.h"
#include "Judge.h"
#include "Audio.h"
#include "Effect.h"
#include "Wall.h"
#include "Goal.h"
#include "SceneGame.h"
#include "StageData_1.h"
#include "StageData_2.h"
#include "StageData_3.h"
#include "StageData_4.h"
#include "StageData_6.h"
#include "StageData_8.h"
#include "Toge.h"
#include "SceneStageSelect.h"
#include "StageData_5.h"

int goalCount;

void Stage::init()
{
    timer = 0;
    switch (stage_number)
    {
    case 1:
        goalCount = 1;
        pScript = stage1Script; break;
    case 2:
        goalCount = 1;
        pScript = stage2Script; break;
    case 3:
        goalCount = 1;
        pScript = stage3Script; break;
    case 4:
        goalCount = 1;
        pScript = stage4Script; break;

    case 5:
        goalCount = 3;
        pScript = stage5Script; break;
    case 6:
        goalCount = 2;
        pScript = stage6Script; break;
    case 8:
        goalCount = 2;
        pScript = stage8Script; break;
    }


    // �w�i�����ݒ�
    BackManager::getInstance().init();

    // �v���C���[�����ݒ�
    PlayerManager::getInstance().init();

    PlayerManager_sd::getInstance().init();

    //�I�u�W�F�N�g�����ݒ�
    WallManager::getInstance().init();
    GoalManager::getInstance().init();

    TogeManager::getInstance().init();
    // �G�t�F�N�g�����ݒ�
    EffectManager::getInstance().init();

    // UI�����ݒ�


    // �I�[�f�B�I�G���W���̏�����
    if (!AudioManager::getInstance().isPlaying(L"btnSound"))
    {
        AudioManager::getInstance().init();
    }
    AudioManager::getInstance().loadSound(L"gameMusic", L"./Data/Musics/y015.wav");
    AudioManager::getInstance().playSound(L"gameMusic", 1.0f, true);

}

void Stage::update()
{
    //�I�u�W�F�N�g�o��


    while (pScript->mover &&    // �I���R�[�h�ł͂Ȃ�
        timer == pScript->time) // ���݂̃^�C�}�[���X�N���v�g�̃^�C���ł����
    {
        switch (pScript->type) {
        case TYPE_WALL:
            WallManager::getInstance().searchSet(pScript->mover, pScript->position);
            break;
        case TYPE_GOAL:
            GoalManager::getInstance().searchSet(pScript->mover, pScript->position);
            break;
        }
        pScript++;
    }

    // �w�i�X�V
    BackManager::getInstance().update();

    // �v���C���[�X�V
    PlayerManager::getInstance().update();

    PlayerManager_sd::getInstance().update();

    // �I�u�W�F�N�g�X�V
    WallManager::getInstance().update();
    GoalManager::getInstance().update();

    TogeManager::getInstance().update();
    // �G�t�F�N�g�X�V
    EffectManager::getInstance().update();

    //�����G�t�F�m�F
    if (GetKeyState('O') < 0)
    {
        EffectManager::getInstance().searchSet(effectExplos, { 960,300 });
    }

    // UI�X�V


    // �����蔻��
    judge();

    timer++;
}

void Stage::draw()
{
    // �w�i�`��
    BackManager::getInstance().draw();

    // �I�u�W�F�N�g�`��
    GoalManager::getInstance().draw();

    // �v���C���[�`��
    PlayerManager::getInstance().draw();

    PlayerManager_sd::getInstance().draw();
    // �G�t�F�N�g�̕`��
    EffectManager::getInstance().draw();

    // �A�C�e���`��


    //�g�̕`��
    WallManager::getInstance().draw();

    TogeManager::getInstance().draw();

    // UI�`��

}