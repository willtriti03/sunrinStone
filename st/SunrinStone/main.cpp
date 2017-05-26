#include "stdafx.h"

#pragma comment(lib, "ws2_32.lib")
#include<winsock2.h>
#include<ws2tcpip.h>

#include "Application.h"
#include "Console.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "CSocket.h"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

Console g_Console;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	CSocket::WSAStart();
	SetCursor(NULL);
	ShowCursor(false);
	GameApp->RegisterWindowSize(1024, 720);
	GameApp->SetAppName(L"AMolLang");
	GameApp->InitializeApp();
	GameApp->InitDirect3D();

	ShowWindow(GameApp->GetHWND(), SW_SHOWDEFAULT);
	UpdateWindow(GameApp->GetHWND());

	//°ÔÀÓ¾À
	SceneMgr->changeScene(new GameScene);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while(msg.message != WM_QUIT) {
		if(PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {
			GameApp->Render();
		}
	}
	UnregisterClass(GameApp->GetAppName(), GetModuleHandle(NULL));

	CSocket::WSAClose();
	return 0;
}