#include "stdafx.h"
#include "Function.h"
#include "Application.h"

LRESULT WINAPI MsgProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) 
{
	switch(Msg) {
		case WM_DESTROY :
			GameApp->Destroy();
			PostQuitMessage(0);
			return 0;
	}
	return(DefWindowProc(hWnd, Msg, wParam, lParam));
}