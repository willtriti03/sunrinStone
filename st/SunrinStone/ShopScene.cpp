#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "ShopScene.h"
#include "Application.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "GUIButton.h"
#include "DeckScene.h"
#include "Font.h"


ShopScene::ShopScene(){
	page = 1;
	m_pRes = new ResourceFinder();
	srand((unsigned)time(NULL));
	for (int i = 0; i < 30; ++i){
		cardIndex[i] = 0;
	}
	m_pBackGround = new BackGround();
	m_pBackGround->BackGroundRsc("resource/shop/shop_main.png");
	pushScene(m_pBackGround, false);
	m_pBackGround->setPosition(D3DXVECTOR2(0, 0));

	m_pcard_5 = new GUIButton();
	m_pcard_5->AddUsualButtonImage("resource/shop/card_5.png");
	m_pcard_5->AddOnButtonImage("resource/shop/card_5.png");
	pushScene(m_pcard_5, false);
	m_pcard_5->setPosition(D3DXVECTOR2(115, 405));

	m_pcard_15 = new GUIButton();
	m_pcard_15->AddUsualButtonImage("resource/shop/card_15or20.png");
	m_pcard_15->AddOnButtonImage("resource/shop/card_15or20.png");
	pushScene(m_pcard_15, false);
	m_pcard_15->setPosition(D3DXVECTOR2(314, 395));

	m_pcard_30 = new GUIButton();
	m_pcard_30->AddUsualButtonImage("resource/shop/card_30up.png");
	m_pcard_30->AddOnButtonImage("resource/shop/card_30up.png");
	pushScene(m_pcard_30, false);
	m_pcard_30->setPosition(D3DXVECTOR2(575, 405));

	m_pright_card = new GUIButton();
	m_pright_card->AddUsualButtonImage("resource/deck/r.png");
	m_pright_card->AddOnButtonImage("resource/deck/r_in.png");
	pushScene(m_pright_card, false);
	m_pright_card->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 37, 230));

	m_pleft_card = new GUIButton();
	m_pleft_card->AddUsualButtonImage("resource/deck/bck.png");
	m_pleft_card->AddOnButtonImage("resource/deck/bck_in.png");
	pushScene(m_pleft_card, false);
	m_pleft_card->setPosition(D3DXVECTOR2(15, 230));

	m_pBackBtn = new GUIButton();                        //버튼할당
	m_pBackBtn->AddUsualButtonImage("resource/shop/back_1.png");   //보통이미지 추가
	m_pBackBtn->AddOnButtonImage("resource/shop/back_2.png");      //마우스가 올라왔을때 이미지 추가
	pushScene(m_pBackBtn, false);                        //GameScene의 자식으로 추가
	m_pBackBtn->setPosition(D3DXVECTOR2(25, 10));

	m_pBuyBtn = new GUIButton();
	m_pBuyBtn->AddOnButtonImage("resource/share/blank.png");
	m_pBuyBtn->AddUsualButtonImage("resource/share/blank.png");
	pushScene(m_pBuyBtn, false);
	m_pBuyBtn->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth()-322,GameApp->GetWindowHeight()-115));

	for (int i = 0; i < 5; ++i){
		m_pBuyCard[i] = new GUIButton();
		m_pBuyCard[i]->AddOnButtonImage("resource/shop/card_back.png");
		m_pBuyCard[i]->AddUsualButtonImage("resource/shop/card_back.png");
		pushScene(m_pBuyCard[i], false);
		m_pBuyCard[i]->setPosition(D3DXVECTOR2(100+(124*i)+(53*i),155));
	
	}
	m_pCusor = new MouseCusor();


}
ShopScene::~ShopScene() {}

void ShopScene::CardUpdate(int page){
	int cost, kind, damge, shild,canuse, pageNum;
	std::string *rec = new std::string;

	switch (page){
	case 1:
		pageNum = 0;
		for (int i = 0; i < 5; ++i){
			m_pRes->CardCodeFinder(cost, kind, cardIndex[pageNum], damge, shild,canuse, rec);
			m_pBuyCard[i]->AddOnButtonImage(*rec);
			m_pBuyCard[i]->AddUsualButtonImage(*rec);

			pageNum++;
		}

		break;
	case 2:
		pageNum = 5;
		for (int i = 0; i < 5; ++i){
			m_pRes->CardCodeFinder(cost, kind, cardIndex[pageNum], damge, shild,canuse, rec);
			m_pBuyCard[i]->AddOnButtonImage(*rec);
			m_pBuyCard[i]->AddUsualButtonImage(*rec);


			pageNum++;
		}
		break;
	case 3:
		pageNum = 10;
		for (int i = 0; i < 5; ++i){
			m_pRes->CardCodeFinder(cost, kind, cardIndex[pageNum], damge, shild,canuse, rec);
			m_pBuyCard[i]->AddOnButtonImage(*rec);
			m_pBuyCard[i]->AddUsualButtonImage(*rec);


			pageNum++;
		}
		break;
	case 4:
		pageNum = 15;
		for (int i = 0; i < 5; ++i){
			m_pRes->CardCodeFinder(cost, kind, cardIndex[pageNum], damge, shild,canuse, rec);
			m_pBuyCard[i]->AddOnButtonImage(*rec);
			m_pBuyCard[i]->AddUsualButtonImage(*rec);


			pageNum++;
		}
		break;
	case 5:
		pageNum = 20;
		for (int i = 0; i < 5; ++i){
			m_pRes->CardCodeFinder(cost, kind, cardIndex[pageNum], damge, shild,canuse, rec);
			m_pBuyCard[i]->AddOnButtonImage(*rec);
			m_pBuyCard[i]->AddUsualButtonImage(*rec);


			pageNum++;
		}
		break;
	case 6:
		pageNum = 25;
		for (int i = 0; i < 5; ++i){
			m_pRes->CardCodeFinder(cost, kind, cardIndex[pageNum], damge, shild,canuse, rec);
			m_pBuyCard[i]->AddOnButtonImage(*rec);
			m_pBuyCard[i]->AddUsualButtonImage(*rec);
		

			pageNum++;
		}
		break;


	}
}
void ShopScene::update(float eTime){
	ISceneNode::update(eTime);
	int randcard;
	static float currentTime = 0.f;
	m_pBackGround->update(eTime);
	m_pright_card->update(eTime);
	m_pleft_card->update(eTime);
	m_pcard_5->update(eTime);
	m_pcard_15->update(eTime);
	m_pcard_30->update(eTime);
	m_pBuyBtn->update(eTime);
	m_pCusor->update(eTime);
	m_pBackBtn->update(eTime);

	for (int i = 0; i < 5; ++i){
		m_pBuyCard[i]->update(eTime);
	}

	if (m_pBackBtn->OnMouseClicked()){
		SceneMgr->changeScene(new GameScene);
	}
	
	else if (m_pcard_5->OnMouseClicked()){
		buycard = 2;
		limitPage = 1;
		m_pBuyBtn->AddOnButtonImage("resource/shop/buy_bt_2.png");
		m_pBuyBtn->AddUsualButtonImage("resource/shop/buy_btn.png");


	}
	else if (m_pcard_30->OnMouseClicked()){
		buycard = 2;
		limitPage = 6;
		
		m_pBuyBtn->AddOnButtonImage("resource/shop/buy_bt_2.png");
		m_pBuyBtn->AddUsualButtonImage("resource/shop/buy_btn.png");
	}
	else if (m_pcard_15->OnMouseClicked()){
		buycard = 2;
		limitPage = 3;
	
		m_pBuyBtn->AddOnButtonImage("resource/shop/buy_bt_2.png");
		m_pBuyBtn->AddUsualButtonImage("resource/shop/buy_btn.png");
	}

	switch (buycard){
	case 1:
		if (m_pright_card->OnMouseClicked()){
			if (page != limitPage){
				page++;
				CardUpdate(page);
			}
		}
		else if (m_pleft_card->OnMouseClicked()){
			if (page - 1 != 0){
				page--;
				CardUpdate(page);
			}
		}
		else if (m_pBuyCard[0]->OnMouseClicked()){

		}
		break;

	case 2:
		if (m_pBuyBtn->OnMouseClicked()){
			for (int i = 0; i < 30; ++i){
				randcard = rand() % 20 + 1;
				cardIndex[i] = randcard;
			}
			buycard = 1;
			CardUpdate(page);

		}
	}

}

void ShopScene::render(){
	ISceneNode::render();

	m_pBackGround->render();


	m_pright_card->render();
	m_pleft_card->render();
	m_pBackBtn->render();
	m_pcard_5->render();
	m_pcard_15->render();
	m_pcard_30->render();
	switch (buycard)
	{
	case 1:
		for (int i = 0; i < 5; ++i){
			m_pBuyCard[i]->render();
		}
		break;
	case 2:
		m_pBuyBtn->render();
		break;
	}
	m_pCusor->render();

}