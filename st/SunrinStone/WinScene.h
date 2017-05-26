#ifndef _WINSCENE_H_
#define _WINSCENE_H_
#include "ISceneNode.h"
#include "BackGround.h"
#include "GUIButton.h"
#include "MouseCusor.h"
class WinScene :public ISceneNode{
public:
	WinScene();
	~WinScene();
	BackGround *m_pBackGround;
	GUIButton  *m_pBackToMenu;
	MouseCusor *m_pCusor;
	void update(float eTIme);
	void render();

};


#endif