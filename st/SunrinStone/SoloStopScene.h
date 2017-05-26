#ifndef _SOLOSTOPSCENE_H_
#define _SOLOSTOPSCENE_H_
#include "ISceneNode.h"
#include "BackGround.h"
#include "GUIButton.h"
#include "MouseCusor.h"
#include "SoloScene.h"
#include "SceneManager.h"
class SoloStopScene : public ISceneNode{
public:
	SoloStopScene(SoloScene *Solo);
	~SoloStopScene();

	BackGround *m_pBackGround;
	GUIButton  *m_pGiveUp;
	GUIButton  *m_pRestart;
	GUIButton  *m_pReturn;
	MouseCusor *m_pCusor;

	SoloScene  *m_pSolo;
	void update(float eTIme);
	void render();

};


#endif