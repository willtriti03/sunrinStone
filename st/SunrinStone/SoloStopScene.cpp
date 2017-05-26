#include "stdafx.h"
#include "SoloStopScene.h"

SoloStopScene::SoloStopScene(SoloScene *Solo){
	m_pSolo = Solo;
	m_pBackGround = new BackGround();
	m_pGiveUp = new GUIButton();
	m_pReturn = new GUIButton();
	m_pRestart = new GUIButton();
	m_pCusor = new MouseCusor();

	m_pBackGround	->BackGroundRsc("resource/setting/set_1.png");
	m_pGiveUp		->AddUsualButtonImage("resource/setting/ff.png");
	m_pReturn		->AddUsualButtonImage("resource/setting/return.png");
	m_pRestart		->AddUsualButtonImage("resource/setting/restart.png");

	m_pGiveUp		->AddOnButtonImage("resource/setting/ff.png");
	m_pReturn		->AddOnButtonImage("resource/setting/return.png");
	m_pRestart		->AddOnButtonImage("resource/setting/restart.png");

	pushScene(m_pBackGround,false);
	pushScene(m_pGiveUp	   ,false);
	pushScene(m_pReturn	   ,false);
	pushScene(m_pRestart   ,false);

	m_pBackGround	->setPosition(D3DXVECTOR2(0,0));
	m_pGiveUp		->setPosition(D3DXVECTOR2(395,220));
	m_pReturn		->setPosition(D3DXVECTOR2(395,320));
	m_pRestart		->setPosition(D3DXVECTOR2(395,420));

};
SoloStopScene::~SoloStopScene(){

}
void SoloStopScene::update(float eTime){
	m_pBackGround	->update(eTime);
	m_pGiveUp		->update(eTime);
	m_pReturn		->update(eTime);
	m_pRestart		->update(eTime);
	m_pCusor->update(eTime);
	if (m_pGiveUp->OnMouseClicked()){
		SceneMgr->changeScene(new GameScene);
	}
	else if (m_pRestart->OnMouseClicked()){
		SceneMgr->changeScene(new SoloScene);
	}
	else if (m_pReturn->OnMouseClicked()){
		SceneMgr->changeScene(m_pSolo);
	}

}
void SoloStopScene::render(){
	m_pBackGround->render();
	m_pGiveUp->render();
	m_pReturn->render();
	m_pRestart->render();
	m_pCusor->render();

}
