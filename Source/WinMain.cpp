// �C���N���[�h
#include "WinMain.h"
#include "../GameLib/game_lib.h"
#include "SceneTitle.h"
#include "SceneTuto.h"
#include "SceneGame.h"
#include "SceneClear.h"
#include "SceneStageSelect.h"
#include "SceneEnd.h"

// ���̐錾
SceneTitle sceneTitle;
SceneSelect sceneSelect;
SceneGame sceneGame;
SceneClear sceneClear;
SceneEnd sceneEnd;

Scene *pScene, *pNextScene;

extern int currentSceneID;

int APIENTRY WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    // �����ݒ�
    GameLib::init(L"Brock Slide", 1280, 720, true);

    // �u�����h���[�h�̐ݒ�
    GameLib::setBlendMode(GameLib::Blender::BS_ALPHA);

    setScene(SCENE::TITLE);

    // ���C�����[�v
    while (GameLib::gameLoop())
    {
        // ���͏���
        GameLib::input::update();

        // �X�V����
        if (pNextScene != nullptr)
        {
            if (pScene != nullptr) {
                pScene->deinit(); 
            }
            pScene = pNextScene;
            pNextScene = nullptr;
            pScene->init();
        }
        pScene->update();

        // �`�揈��
        pScene->draw();

        //GameLib::debug::setString("SAMPLE");
        GameLib::debug::display(1, 1, 1, 2, 2);

        // �o�b�N�o�b�t�@�ƃt�����g�o�b�t�@��؂�ւ���
        GameLib::present(1, 0);
    }

    // �I������
    GameLib::uninit();

    return 0;
}

void setScene(int nextScene)
{
    Scene* scenes[] = {
        &sceneTitle,
        &sceneSelect,
        &sceneGame,
        &sceneEnd,
        &sceneClear,
    };

    pNextScene = scenes[nextScene];
    currentSceneID = nextScene;
}
