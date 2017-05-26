#include "stdafx.h"
#include "Application.h"
#include "Function.h"
#include "SceneManager.h"
#include "SpriteManager.h"
#include "TextureManager.h"
#include "InputManager.h"


LARGE_INTEGER LInterval;
LARGE_INTEGER RInterval;
LARGE_INTEGER Frequency;

Application::Application() :
	m_pD3D(NULL), m_pd3dDevice(NULL), 
	m_hWnd(NULL),
	m_pAppName(NULL),
	m_nWidth(0), m_nHeight(0)
{
	QueryPerformanceCounter(&LInterval);
	QueryPerformanceFrequency(&Frequency);
}
Application::~Application() {}
//타입 클래스이름::함수이름(){}
void Application::RegisterWindowSize(int nWidth, int nHeight) {
	m_nWidth = nWidth;
	m_nHeight = nHeight;
}
float Application::GetElapsedTime() {
	QueryPerformanceCounter(&RInterval);
	__int64 Interval(RInterval.QuadPart - LInterval.QuadPart);

	float eTime = (double)Interval/(double)Frequency.QuadPart;

	LInterval = RInterval;

	return eTime;
}
void Application::InitializeApp() {
	WNDCLASSEX wc = {
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		m_pAppName, NULL};
	RegisterClassEx(&wc);

	m_hWnd = CreateWindow(m_pAppName, m_pAppName,
		WS_OVERLAPPEDWINDOW, 100, 0, m_nWidth, m_nHeight,
		GetDesktopWindow(), NULL, wc.hInstance, NULL);
}
HRESULT Application::InitDirect3D() {
	D3DPRESENT_PARAMETERS d3dpp;
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferWidth = m_nWidth;
	d3dpp.BackBufferHeight = m_nHeight;
	d3dpp.BackBufferCount = 1;

	m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &m_pd3dDevice);

	SpriteMgr->Initialize();

	return S_OK;
}
void Application::Update(float eTime) {
	SceneMgr->update(eTime);
	InputMgr->update();
}
void Application::Render() {
	m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET,
		D3DCOLOR_ARGB(255, 0, 0, 0), 1.0f, 0);
	Update(GetElapsedTime());
	if(SUCCEEDED(m_pd3dDevice->BeginScene())) {
		SceneMgr->render();
		m_pd3dDevice->EndScene();
	}
	m_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}
void Application::Destroy() {
	m_pD3D->Release();
	m_pd3dDevice->Release();
	SpriteMgr->Release();
	TextureMgr->Release();
}