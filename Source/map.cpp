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
#include "Statge1.h"

using namespace GameLib;
int mapData[MapManager::MAP_HEIGHT][MapManager::MAP_WIDTH] = {0};
int gimickMap[MapManager::MAP_HEIGHT][MapManager::MAP_WIDTH];

int CurrentNumber;

void MapManager::loadStage(int newMapData[MAP_HEIGHT][MAP_WIDTH], int newGimickMap[MAP_HEIGHT][MAP_WIDTH]) {
    // mapData���R�s�[
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            mapData[y][x] = newMapData[y][x];
        }
    }

    // gimickMap���R�s�[
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            gimickMap[y][x] = newGimickMap[y][x];
        }
    }
}
void MapManager::switchToStage(int stageNumber) {
    CurrentNumber = stageNumber;
    switch (stageNumber) {
        //�����p�}�b�v  ������`���[�g���A���Q�̃}�b�v�ɂ���

        //�X�e�[�W�P�|�Z
    case 0: 
        loadStage(mapData11, gimickMap11);
        break;
    }
}
void MapManager::init() {
    // �}�b�v�`�b�v�̓ǂݍ���   
    block = sprite_load(L"./Data/Images/wall.png");
    ugoku = sprite_load(L"./Data/Images/ugoku.png");
    hako = sprite_load(L"./Data/Images/hako.png");
}

void MapManager::deinit() {
    // �}�b�v�`�b�v�X�v���C�g�̉��
    safe_delete(block);
    safe_delete(ugoku);
    // �}�b�v�f�[�^�̏������i�f�t�H���g�̒l��ݒ�j
    memset(mapData, 0, sizeof(mapData));  // 0 �ŏ����� (��̃}�b�v)
    memset(gimickMap, 0, sizeof(gimickMap));  // �M�~�b�N�}�b�v��������
}

void MapManager::draw() {
    // �}�b�v�`�b�v�̕`��
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            int tile = mapData[y][x];


            // �}�b�v�̍��W���s�N�Z�����W�ɕϊ�����i��F64x64�T�C�Y�̃^�C���j
            int pixelX = x * 64;
            int pixelY = y * 64;

            // �}�b�v�`�b�v��`��
            switch (tile)
            {
            case 0:
                break;                                            // ��: �����`�悵�Ȃ� 
            case 1:                                                  // dirt�̃}�b�v�`�b�v��`��     
                sprite_render(block, pixelX, pixelY, 1,1);
                break;
            case 2:
                sprite_render(ugoku, pixelX, pixelY, 1, 1);
                break;
            case 3:
                sprite_render(hako, pixelX, pixelY, 1, 1);
                break;
            }

        }
    }
}




