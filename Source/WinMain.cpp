// インクルード
#include "WinMain.h"
#include "../GameLib/game_lib.h"
#include "SceneTitle.h"
#include "SceneTuto.h"
#include "SceneGame.h"
#include "SceneClear.h"
#include "SceneStageSelect.h"
#include "SceneEnd.h"

// 実体宣言
SceneTitle sceneTitle;
SceneSelect sceneSelect;
SceneGame sceneGame;
SceneClear sceneClear;
SceneEnd sceneEnd;

Scene *pScene, *pNextScene;

extern int currentSceneID;

int APIENTRY WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    // 初期設定
    GameLib::init(L"Brock Slide", 1280, 720, true);

    // ブレンドモードの設定
    GameLib::setBlendMode(GameLib::Blender::BS_ALPHA);

    setScene(SCENE::TITLE);

    // メインループ
    while (GameLib::gameLoop())
    {
        // 入力処理
        GameLib::input::update();

        // 更新処理
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

        // 描画処理
        pScene->draw();

        //GameLib::debug::setString("SAMPLE");
        GameLib::debug::display(1, 1, 1, 2, 2);

        // バックバッファとフロントバッファを切り替える
        GameLib::present(1, 0);
    }

    // 終了処理
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
