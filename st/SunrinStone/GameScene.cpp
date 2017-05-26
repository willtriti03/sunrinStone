#include "stdafx.h"
#include "GameScene.h"
#include "Application.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "ShopScene.h"
#include "DeckScene.h"
#include "MultiScene.h"
#include "SoloScene.h"
GameScene::GameScene() {
	m_pCusor = new MouseCusor();



	m_pBackGround = new BackGround();
	m_pBackGround->BackGroundRsc("resource/main/back1.png");
	pushScene(m_pBackGround, false);
	m_pBackGround->setPosition(D3DXVECTOR2(0, 0));

	m_pSoloBtn = new GUIButton();	
	m_pMultiBtn = new GUIButton();	
	m_pShopBtn = new GUIButton();  
	m_pDeckBtn = new GUIButton();								

	m_pSoloBtn->AddUsualButtonImage("resource/main/solo_out.png");
	m_pMultiBtn->AddUsualButtonImage("resource/main/multi_out.png");
	m_pShopBtn->AddUsualButtonImage("resource/main/shop_out.png");   
	m_pDeckBtn->AddUsualButtonImage("resource/main/card_out.png");	

	m_pMultiBtn->AddOnButtonImage("resource/main/multi_in.png");	
	m_pSoloBtn->AddOnButtonImage("resource/main/solo_in.png");		
	m_pShopBtn->AddOnButtonImage("resource/main/shop_in.png");     
	m_pDeckBtn->AddOnButtonImage("resource/main/card_in.png");	

	pushScene(m_pSoloBtn, false);								
	pushScene(m_pMultiBtn, false);							
	pushScene(m_pShopBtn, false);                      
	pushScene(m_pDeckBtn, false);							

	m_pSoloBtn->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 400, 70));
	m_pMultiBtn->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 400, 230));
	m_pShopBtn->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 400, 400));
	m_pDeckBtn->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 400, 560));

}
GameScene::~GameScene() {

}
void GameScene::update(float eTime) {
	ISceneNode::update(eTime);
	static float currentTime = 0.f;
	m_pBackGround->update(eTime);
	m_pSoloBtn->update(eTime);
	m_pMultiBtn->update(eTime);
	m_pDeckBtn->update(eTime);
	m_pShopBtn->update(eTime);
	m_pCusor->update(eTime);

	if (m_pShopBtn->OnMouseClicked()){
		clicked = true;
		while (clicked){
			currentTime += eTime;
			if (currentTime > 300.f){
				currentTime = 0.f;
				clicked = false;
				SceneMgr->changeScene(new ShopScene);
				break;
			}
		}

	}

	else if (m_pSoloBtn->OnMouseClicked()){
		clicked = true;
		while (clicked){
			currentTime += eTime;
			if (currentTime > 300.0){
				currentTime = 0;
				clicked = false;
				SceneMgr->changeScene(new SoloScene);

				break;
			}
		}
	}

	else if (m_pMultiBtn->OnMouseClicked()){
		clicked = true;
		while (clicked){
			currentTime += eTime;
			if (currentTime > 300.f){
				currentTime = 0.f;
				clicked = false;
				SceneMgr->changeScene(new MultiScene);
				break;
			}
		}
	}

	else if (m_pDeckBtn->OnMouseClicked()){
		clicked = true;
		while (clicked){
		
			currentTime += eTime;
			if (currentTime >= 40.f){
				SceneMgr->changeScene(new DeckScene);
				currentTime = 0;
				clicked = false;
				break;
			}
		}

	}
	//버튼 업데이트
	else if (m_pSoloBtn->OnMouseClicked()){
		clicked = true;
		while (clicked){
			currentTime += eTime;

			if (currentTime > 300.0){
				currentTime = 0;
				clicked = false;
				break;
			}
		}

	}

}

void GameScene::render() {
	ISceneNode::render();
	m_pBackGround->render();
	m_pDeckBtn->render();										//버튼 렌더링
	m_pSoloBtn->render();
	m_pMultiBtn->render();
	m_pShopBtn->render();
	m_pCusor->render();
	
}