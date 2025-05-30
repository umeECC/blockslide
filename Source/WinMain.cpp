// インクルード
#include "WinMain.h"
#include "../GameLib/game_lib.h"
#include "SceneTitle.h"
#include"SceneTuto.h"
#include "SceneGame.h"
#include "SceneClear.h"
#include "SceneEnd.h"
#include "SceneStageSelect.h"
#include "Player.h"
#include "Warp.h"
#include <iostream>

// 実体宣言
SceneTitle sceneTitle;
SceneSelect sceneSelect;
SceneGame sceneGame;
SceneClear sceneClear;
SceneEnd sceneEnd;

Scene* pScene, * pNextScene;

extern int currentSceneID;

int APIENTRY WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    // 初期設定
    GameLib::init(L"Block Slide", 1280, 720, true);

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
        &sceneClear,
        &sceneEnd,
    };

    pNextScene = scenes[nextScene];
    currentSceneID = nextScene;
}




//int main() {
//    Player player = { {5.0f, 5.0f} };
//    WarpZone warp = {
//        {4.0f, 4.0f},       // topLeft
//        {6.0f, 6.0f},       // bottomRight
//        {10.0f, 10.0f}      // destination
//    };
//
//    std::cout << "現在位置: (" << player.position.x << ", " << player.position.y << ")" << std::endl;
//
//    warpPlayer(player, warp);
//
//    std::cout << "現在位置: (" << player.position.x << ", " << player.position.y << ")" << std::endl;
//
//    return 0;
//}
//#include <windows.h>
//
//const int PLAYER_SIZE = 40;
//const int WARP_SIZE = 60;
//
//// プレイヤーとワープの位置
//int playerX = 100, playerY = 100;
//int warpX = 300, warpY = 200;
//
//// ワープ後の位置
//const int warpDestX = 500;
//const int warpDestY = 100;
//
//// ワープ判定関数
//bool checkWarp() {
//    RECT player = { playerX, playerY, playerX + PLAYER_SIZE, playerY + PLAYER_SIZE };
//    RECT warp = { warpX, warpY, warpX + WARP_SIZE, warpY + WARP_SIZE };
//    RECT intersect;
//    return IntersectRect(&intersect, &player, &warp);
//}
//
//// ウィンドウプロシージャ
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//    switch (msg)
//    {
//    case WM_PAINT:
//    {
//        PAINTSTRUCT ps;
//        HDC hdc = BeginPaint(hwnd, &ps);
//
//        // 背景を白で塗る
//        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
//
//        // ワープゾーン（赤）
//        HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
//        RECT warp = { warpX, warpY, warpX + WARP_SIZE, warpY + WARP_SIZE };
//        FillRect(hdc, &warp, redBrush);
//        DeleteObject(redBrush);
//
//        // プレイヤー（青）
//        HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
//        RECT player = { playerX, playerY, playerX + PLAYER_SIZE, playerY + PLAYER_SIZE };
//        FillRect(hdc, &player, blueBrush);
//        DeleteObject(blueBrush);
//
//        EndPaint(hwnd, &ps);
//    }
//    return 0;
//
//    case WM_KEYDOWN:
//        switch (wParam) {
//        case VK_LEFT:  playerX -= 10; break;
//        case VK_RIGHT: playerX += 10; break;
//        case VK_UP:    playerY -= 10; break;
//        case VK_DOWN:  playerY += 10; break;
//        }
//
//        if (checkWarp()) {
//            playerX = warpDestX;
//            playerY = warpDestY;
//        }
//
//        InvalidateRect(hwnd, NULL, TRUE); // 再描画
//        break;
//
//    case WM_DESTROY:
//        PostQuitMessage(0);
//        return 0;
//    }
//
//    return DefWindowProc(hwnd, msg, wParam, lParam);
//}

// エントリーポイント
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
//{
//    const wchar_t CLASS_NAME[] = L"2DGameWindow";
//
//    WNDCLASS wc = {};
//    wc.lpfnWndProc = WndProc;
//    wc.hInstance = hInstance;
//    wc.lpszClassName = CLASS_NAME;
//    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//
//    RegisterClass(&wc);
//
//    HWND hwnd = CreateWindowEx(0, CLASS_NAME, L"ワープゾーン描画 - WinAPI", WS_OVERLAPPEDWINDOW,
//        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
//        NULL, NULL, hInstance, NULL);
//
//    if (!hwnd) return 0;
//
//    ShowWindow(hwnd, nCmdShow);
//
//    // メッセージループ
//    MSG msg = {};
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//    }
//
//    return 0;
//}