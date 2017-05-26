#ifndef _LOSESCENE_H_
#define _LOSESCENE_H_
#include "ISceneNode.h"
#include "BackGround.h"
#include "GUIButton.h"
#include "MouseCusor.h"
class LoseScene :public ISceneNode{
public:
	LoseScene();
	~LoseScene();
	BackGround *m_pBackGround;
	GUIButton  *m_pBackToMenu;
	MouseCusor *m_pCusor;
	void update(float eTIme);
	void render();

};


#endif