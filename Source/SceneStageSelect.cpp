#include "SceneStageSelect.h"
#include "../GameLib/game_lib.h"
#include "WinMain.h"
#include "Audio.h"
#include "SpriteData.h"
#include "Obj2d.h"
#include "Player.h" 

OBJ2D select_back;
int stage_number;

void SceneSelect::init()
{
	timer = 0;
    stage_number = 1;

    select_back.position = { 0, 0 };
    select_back.sprData = &sprStageSelect;
}

void SceneSelect::deinit()
{

}

void SceneSelect::update()
{ 
    using namespace GameLib::input;
    // ���݂̃L�[�̏�Ԃ��擾
    bool isAKeyPressed = (GetAsyncKeyState('A') & 0x8000) != 0;
    bool isDKeyPressed = (GetAsyncKeyState('D') & 0x8000) != 0;

    // �L�[��������Ă������ǂ���
    bool wasAKeyPressed = false;
    bool wasDKeyPressed = false;

    // W�L�[�������ꂽ�u�Ԃ𔻒�
    if (isAKeyPressed && !wasAKeyPressed)
    {
        AudioManager::getInstance().playSound(L"selectSound", 0.5f, false);
        stage_number--;
        if (stage_number < -1) stage_number = 0;
    }

    // S�L�[�������ꂽ�u�Ԃ𔻒�
    if (isDKeyPressed && !wasDKeyPressed)
    {
        AudioManager::getInstance().playSound(L"selectSound", 0.5f, false);
        stage_number++;
        if (stage_number >= 10) stage_number = 1;
    }

    // ���݂̏�Ԃ����̃t���[���̂��߂ɕۑ�
    wasAKeyPressed = isAKeyPressed;
    wasDKeyPressed = isDKeyPressed;
    if (timer > 0x40 && GameLib::input::TRG(0)& GameLib::input::PAD_START)
    {
        setScene(SCENE::GAME);
    }
    timer++;
}

void SceneSelect::draw()
{
    GameLib::clear(0, 0, 0);

    select_back.draw();
}