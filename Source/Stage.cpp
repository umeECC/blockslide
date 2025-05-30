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


void Stage::init()
{
    timer = 0;
    pScript = stage1Script;


    // �w�i�����ݒ�
    BackManager::getInstance().init();

    // �v���C���[�����ݒ�
    PlayerManager::getInstance().init();

    PlayerManager_sd::getInstance().init();

    //�I�u�W�F�N�g�����ݒ�
    WallManager::getInstance().init();
    GoalManager::getInstance().init();

    // �G�t�F�N�g�����ݒ�
    EffectManager::getInstance().init();

    // UI�����ݒ�


    // �I�[�f�B�I�G���W���̏�����
    if (!AudioManager::getInstance().isPlaying(L"btnSound"))
    {
        AudioManager::getInstance().init();
    }
    AudioManager::getInstance().loadSound(L"gameMusic", L"./Data/Musics/y015.wav");
    AudioManager::getInstance().playSound(L"gameMusic", 0.8f, true);

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



    // UI�`��

}