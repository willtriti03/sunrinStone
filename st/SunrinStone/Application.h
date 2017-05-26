#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <d3d9.h>
#include <d3dx9.h>


#define GameApp Application::GetInstance()

class Application {
//�������
//����Լ�
private:
	LPDIRECT3D9				m_pD3D; //LP�� long pointer�� ����, m_pD3D�� directx��ü
	LPDIRECT3DDEVICE9	m_pd3dDevice; //direct3D device
	
	HWND	m_hWnd; //�������ڵ�
	LPCWSTR	m_pAppName;  //������ �̸�

	int m_nWidth; //������ ũ��
	int m_nHeight; //������ ũ��

private:
	Application(); //Ŭ�����̸�()
	float GetElapsedTime();

public:
	~Application(); //~Ŭ�����̸�()

public:
	static Application* GetInstance() {
		static Application Instance;
		return &Instance;
	}
	void RegisterWindowSize(int nWidth, int nHeight);
	void InitializeApp();	//������ ����, ����
	HRESULT InitDirect3D(); //DirectX�� �ʱ�ȭ����

public:
	void SetHWND(HWND hWnd) {m_hWnd = hWnd;}
	void SetAppName(LPCWSTR AppName) { m_pAppName = AppName; }
	
	LPCWSTR GetAppName() { return m_pAppName; }
	int GetWindowWidth() { return m_nWidth; }
	int GetWindowHeight() { return m_nHeight; }
	HWND GetHWND() { return m_hWnd; }
	LPDIRECT3DDEVICE9 GetDevice() { return m_pd3dDevice; }

public:
	void Update(float eTime); //���ӿ��� �ǽð����� �ٲ�� �κ��� ó��
	void Render(); //��������� ������
	void Destroy(); //���α׷������ COM��ü �Ҵ�����

};

#endif