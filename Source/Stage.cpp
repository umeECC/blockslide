#include "Stage.h"
#include"Obj2d.h"
#include "Back.h"
#include "Player.h"
#include "Judge.h"
#include "Audio.h"
#include "Effect.h"
#include "SceneGame.h"
#include"map.h"
#include"Stage.h"
#include "map.h"

void Stage::init()
{
    timer = 0;
    //pScript = stageScript;

    // �w�i�����ݒ�
    BackManager::getInstance().init();

    // �v���C���[�����ݒ�
    PlayerManager::getInstance().init();

    // �}�b�v�����ݒ�(map_init())
    MapManager::getInstance().init();
    MapManager::getInstance().switchToStage(0);

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
    // �G�o��
    /*while (pScript->mover &&    // �I���R�[�h�ł͂Ȃ�
        timer == pScript->time) // ���݂̃^�C�}�[���X�N���v�g�̃^�C���ł����
    {
        ItemManager::getInstance().searchSet(pScript->mover, pScript->position);
        pScript++;
    }*/

    // �w�i�X�V
    BackManager::getInstance().update();

    // �v���C���[�X�V
    PlayerManager::getInstance().update();

    // �}�b�v�̍X�V
    
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

    // �G�L�����`��
    
    // �G�t�F�N�g�̕`��
    EffectManager::getInstance().draw();

    // �A�C�e���`��
    
    // �}�b�v�̕`��
    MapManager::getInstance().draw();

    // �v���C���[�`��
    PlayerManager::getInstance().draw();
    

    // UI�`��
    
}
