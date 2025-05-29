#include "SceneGame.h"
#include "../GameLib/game_lib.h"
#include "WinMain.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Player.h"
#include "Player_sd.h"
#include "Stage.h"
#include "Audio.h"
#include "Wall.h"

// �萔�錾

// �ϐ��錾

// �v���g�^�C�v�錾
void enemy(OBJ2D* obj);

void SceneGame::init()
{
    Stage::getInstance().init();
}

void SceneGame::deinit()
{
    AudioManager::getInstance().stopSound(L"gameMusic");
}

void SceneGame::update()
{
    Stage::getInstance().update();
    if (GameLib::input::STATE(0) & GameLib::input::PAD_SELECT)
    {
        setScene(SCENE::STAGESEL);
    }
}

//�G(��)
void enemy(OBJ2D* obj)
{
    //obj->position = { rand() % 879 + 209, rand() % 700 };
}

void SceneGame::draw()
{
    // ��ʂ��N���A
    GameLib::clear(0, 0, 0);

    Stage::getInstance().draw();
}