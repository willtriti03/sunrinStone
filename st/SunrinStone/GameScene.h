#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "ISceneNode.h"
#include "GUIButton.h"
#include "BackGround.h"
#include <String>
#include "Font.h"
#include "MouseCusor.h"
class GameScene : public ISceneNode {
private:
	GUIButton  *m_pDeckBtn;
	GUIButton  *m_pSoloBtn;
	GUIButton  *m_pMultiBtn;
	GUIButton  *m_pShopBtn;

	MouseCusor *m_pCusor;
	BackGround *m_pBackGround;

	POINT	    currentMousePoint;

	bool        clicked=false;

	int x, y;
public:
	GameScene();
	~GameScene();

	void update(float eTime);
	void render();

};

#endif