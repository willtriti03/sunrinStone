#include "stdafx.h"
#include "LoseScene.h"
#include "Application.h"
#include "SceneManager.h"
#include "GameScene.h"
LoseScene::LoseScene(){
	m_pBackGround = new BackGround();

	m_pBackToMenu = new GUIButton();

	m_pCusor = new MouseCusor();


	m_pBackGround->BackGroundRsc("resource/ending/lose_s.png");

	m_pBackToMenu->AddUsualButtonImage("resource/ending/back_bt_on.png");
	m_pBackToMenu->AddOnButtonImage("resource/ending/back_bt_in.png");

	pushScene(m_pBackGround, false);
	pushScene(m_pBackToMenu, false);

	m_pBackGround->setPosition(D3DXVECTOR2(0, 0));

	m_pBackToMenu->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 85, GameApp->GetWindowHeight() - 85));

}
LoseScene::~LoseScene(){}
void LoseScene::update(float eTime){
	ISceneNode::update(eTime);
	m_pBackGround->update(eTime);
	m_pBackToMenu->update(eTime);
	m_pCusor->update(eTime);

	if (m_pBackToMenu->OnMouseClicked()){
		SceneMgr->changeScene(new GameScene);
	}
}
void LoseScene::render(){
	m_pBackGround->render();
	m_pBackToMenu->render();
	m_pCusor->render();

}
