#include "stdafx.h"
#include "DeckScene.h"
#include "Application.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "GameScene.h"
#include <time.h>

#define WIDTH 100 
#define HEIGHT 200
#define FALL_FROM_SIDE_BTN 50
#define FALL_FROM_TOP_BTN 50
#define FALL_FROM_TOP 130
#define FALL_FROM_SIDE 150

DeckScene::DeckScene(){
	std::string *rec = new std::string;

	m_pRes = new ResourceFinder();

	m_pDeckBackGround = new BackGround();
	m_pHero = new BackGround();
	m_pCusor = new MouseCusor();

	m_pDeckBackGround->BackGroundRsc("resource/deck/deck_main.png");
	m_pHero->BackGroundRsc("resource/share/blank.png");
	pushScene(m_pDeckBackGround, false);
	pushScene(m_pHero, false);
	m_pDeckBackGround->setPosition(D3DXVECTOR2(0, 0));
	m_pHero->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 200,200));

	m_pSaveBtn = new GUIButton();
	m_pDeckBackBtn = new GUIButton();
	m_pNextPage = new GUIButton();
	m_pBackPage = new GUIButton();
	m_pSelect = new GUIButton();
	m_pDeckPageBack = new GUIButton();
	m_pDeckPageNext = new GUIButton();
	m_pHeroSelect[0] = new GUIButton();
	m_pHeroSelect[1] = new GUIButton();
	m_pHeroSelect[2] = new GUIButton();


	m_pSaveBtn->AddOnButtonImage("resource/deck/save_bt_in.png");
	m_pDeckBackBtn->AddOnButtonImage("resource/deck/back_bt_in.png");	// 마우스가 올라왔을때 이미지 추가
	m_pNextPage->AddOnButtonImage("resource/deck/deck_next.png");
	m_pBackPage->AddOnButtonImage("resource/deck/deck_next.png");
	m_pSelect->AddOnButtonImage("resource/deck/sl.png");
	m_pHeroSelect[0]->AddOnButtonImage("resource/hero/card_1.png");
	m_pHeroSelect[1]->AddOnButtonImage("resource/hero/card_2.png");
	m_pHeroSelect[2]->AddOnButtonImage("resource/hero/card_3.png");
	m_pDeckPageBack->AddOnButtonImage("resource/deck/bck_in.png");
	m_pDeckPageNext->AddOnButtonImage("resource/deck/r_in.png");

	m_pSaveBtn->AddUsualButtonImage("resource/deck/save_bt_out.png");
	m_pDeckBackBtn->AddUsualButtonImage("resource/deck/back_bt_on.png");
	m_pNextPage->AddUsualButtonImage("resource/deck/deck_next.png");
	m_pBackPage->AddUsualButtonImage("resource/deck/deck_next.png");
	m_pSelect->AddUsualButtonImage("resource/deck/sl.png");
	m_pHeroSelect[0]->AddUsualButtonImage("resource/hero/card_1.png");
	m_pHeroSelect[1]->AddUsualButtonImage("resource/hero/card_2.png");
	m_pHeroSelect[2]->AddUsualButtonImage("resource/hero/card_3.png");
	m_pDeckPageBack->AddUsualButtonImage("resource/deck/bck.png");
	m_pDeckPageNext->AddUsualButtonImage("resource/deck/r.png");

	pushScene(m_pSaveBtn, false);
	pushScene(m_pDeckBackBtn, false);								 //GameScene의 자식으로 추가
	pushScene(m_pNextPage, false);
	pushScene(m_pBackPage, false);
	pushScene(m_pSelect, false);
	pushScene(m_pHeroSelect[0], false);
	pushScene(m_pHeroSelect[1], false);
	pushScene(m_pHeroSelect[2], false);
	pushScene(m_pDeckPageBack, false);
	pushScene(m_pDeckPageNext, false);

	m_pSaveBtn->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 197, GameApp->GetWindowHeight() - 130));
	m_pDeckBackBtn->setPosition(D3DXVECTOR2(25, 10));
	m_pNextPage->setPosition(D3DXVECTOR2(740, 80));
	m_pBackPage->setPosition(D3DXVECTOR2(30, 80));
	m_pSelect->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 182, GameApp->GetWindowHeight() - 100));
	m_pHeroSelect[0]->setPosition(D3DXVECTOR2(90,200));
	m_pHeroSelect[1]->setPosition(D3DXVECTOR2(320, 200));
	m_pHeroSelect[2]->setPosition(D3DXVECTOR2(550, 200));
	m_pDeckPageBack->setPosition(D3DXVECTOR2(870, 550));
	m_pDeckPageNext->setPosition(D3DXVECTOR2(920, 550));

	int j = 0;

	for (int i = 0; i < 40; ++i){
		char *textRec[60];
		deckList[i] = 0;
		m_pDeckCard[i] = new GUIButton();
		m_pDeckListText[i] = new CFont(60, 36);

		CardTexter(DeckScene::deckList[i], textRec);
		m_pDeckListText[i]->setString(*textRec);

		m_pDeckCard[i]->AddUsualButtonImage("resource/deck/in_card.png");
		m_pDeckCard[i]->AddOnButtonImage("resource/deck/in_card.png");


		pushScene(m_pDeckListText[i], false);
		pushScene(m_pDeckCard[i], false);

		if (j != 10){
			m_pDeckCard[i]->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 200, 150 + ((31 + 2)*j)));
			m_pDeckListText[i]->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 192, 145 + ((31 + 2)*j)));
			j++;
		}
		else{
			j = 0;
			m_pDeckCard[i]->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 200, 150 + ((31 + 2)*j)));
			m_pDeckListText[i]->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 192, 145 + ((31 + 2)*j)));
			j++;
		}
	}

	for (int i = 0; i < 8; i++)
		cardSpecialNum[i] = i + 1;
	int blank;
	for (int i = 0; i < 8; i++){
		m_pCard_Lists[i] = new GUIButton();
		m_pRes->CardCodeFinder(blank, blank, cardSpecialNum[i], blank, blank, blank,rec);
		m_pCard_Lists[i]->AddOnButtonImage(*rec);
		m_pCard_Lists[i]->AddUsualButtonImage(*rec);
		pushScene(m_pCard_Lists[i], false);
	}

	m_pCard_Lists[0]->setPosition(D3DXVECTOR2(FALL_FROM_SIDE, FALL_FROM_TOP));
	m_pCard_Lists[1]->setPosition(D3DXVECTOR2(FALL_FROM_SIDE + WIDTH + FALL_FROM_SIDE_BTN, FALL_FROM_TOP));
	m_pCard_Lists[2]->setPosition(D3DXVECTOR2(FALL_FROM_SIDE + (WIDTH + FALL_FROM_SIDE_BTN) * 2, FALL_FROM_TOP));
	m_pCard_Lists[3]->setPosition(D3DXVECTOR2(FALL_FROM_SIDE + (WIDTH + FALL_FROM_SIDE_BTN) * 3, FALL_FROM_TOP));
	m_pCard_Lists[4]->setPosition(D3DXVECTOR2(FALL_FROM_SIDE, FALL_FROM_TOP + HEIGHT + FALL_FROM_TOP_BTN));
	m_pCard_Lists[5]->setPosition(D3DXVECTOR2(FALL_FROM_SIDE + WIDTH + FALL_FROM_SIDE_BTN, FALL_FROM_TOP + HEIGHT + FALL_FROM_TOP_BTN));
	m_pCard_Lists[6]->setPosition(D3DXVECTOR2(FALL_FROM_SIDE + (WIDTH + FALL_FROM_SIDE_BTN) * 2, FALL_FROM_TOP + HEIGHT + FALL_FROM_TOP_BTN));
	m_pCard_Lists[7]->setPosition(D3DXVECTOR2(FALL_FROM_SIDE + (WIDTH + FALL_FROM_SIDE_BTN) * 3, FALL_FROM_TOP + HEIGHT + FALL_FROM_TOP_BTN));

	//AddFontResourceEx( 폰트경로, FR_PRIVATE, 0 );
}

DeckScene::~DeckScene(){

}



void DeckScene::DeckFileSave(){
	FILE *DeckFile;
	DeckFile = fopen("decks/deckfile.deck","w");
	fprintf(DeckFile, "%d\n", DeckScene::hero);
	for (int i = 0; i < 40; i++){
		int locked_Card_Code = DeckScene::deckList[i];
		fprintf(DeckFile, "%d\n", locked_Card_Code);
	}
	fclose(DeckFile);
	

}




void DeckScene::CardClicked(int cardNum){
	char *textRec[60];
	int overlap = 0;
	if (DeckScene::deckListCounter < 40){
		for (int i = 0; i < DeckScene::deckListCounter; i++)
			if (cardNum == DeckScene::deckList[i]) overlap++;
		if (overlap < 2){
			DeckScene::deckList[DeckScene::deckListCounter] = cardNum;

			CardTexter(DeckScene::deckList[DeckScene::deckListCounter], textRec);
			m_pDeckListText[DeckScene::deckListCounter]->setString(*textRec);

			printf("%d %d\n", DeckScene::deckList[DeckScene::deckListCounter], DeckScene::deckListCounter);

			switch (DeckScene::deckListCounter / 10){
			case 1:
				deckListPage = 2;
				break;
			case 2:
				deckListPage = 3;
				break;
			case 3:
				deckListPage = 4;
				break;
			}

			DeckScene::deckListCounter += 1;
		}
	}

}




void DeckScene::CardTexter(int cardNum, char *recText[]){
	switch (cardNum){
	case 1:
		*recText = "3    장검";
		break;
	case 2:
		*recText = "6 강철스큐툼";
		break;
	case 3:
		*recText = "2    손도끼";
		break;
	case 4:
		*recText = "3    그물";
		break;
	case 5:
		*recText = "2 글라디우스";
		break;
	case 6:
		*recText = "2    몽둥이";
		break;
	case 7:
		*recText = "3    단궁";
		break;
	case 8:
		*recText = "5    철퇴";
		break;
	case 9:
		*recText = "3    버클러";
		break;
	case 10:
		*recText = "2    우드버클러";
		break;
	case 11:
		*recText = "6    워해머";
		break;
	case 12:
		*recText = "2    삼지창";
		break;
	case 13:
		*recText = "H    두날단검";
		break;
	case 14:
		*recText = "4    스큐툼";
		break;
	case 15:
		*recText = "4    스파타";
		break;
	case 16:
		*recText = "3    창";
		break;
	case 17:
		*recText = "H    낫";
		break;
	case 18:
		*recText = "1    단검";
		break;
	case 19:
		*recText = "6    투창";
		break;
	case 20:
		*recText = "5 미스틸..";
		break;
	default:
		*recText = "error";
		break;

	}
}

void DeckScene::update(float eTime){
	ISceneNode::update(eTime);
	int blank;
	std::string *rec = new std::string;
	static float currentTime = 0.f;
	
	m_pHero->update(eTime);
	m_pSaveBtn->update(eTime);
	m_pSelect->update(eTime);
	m_pHeroSelect[0]->update(eTime);
	m_pHeroSelect[1]->update(eTime);
	m_pHeroSelect[2]->update(eTime);
	m_pDeckBackGround->update(eTime);
	m_pDeckBackBtn->update(eTime);
	m_pSaveBtn->update(eTime);
	m_pDeckPageBack->update(eTime);
	m_pDeckPageNext->update(eTime);
	m_pCusor->update(eTime);
	for (int i = 0; i < 8; ++i)
		m_pCard_Lists[i]->update(eTime);
	m_pNextPage->update(eTime);
	m_pBackPage->update(eTime);
	for (int i = 0; i < 40; ++i){
		m_pDeckCard[i]->update(eTime);
		m_pDeckListText[i]->update(eTime);
	}

	if (m_pDeckBackBtn->OnMouseClicked()){

		SceneMgr->changeScene(new GameScene);
		//if (deckListPage - 1 != 0)
		//	deckListPage--;
	}
	switch (HeroSelected){
	case 1:
		if (m_pSelect->OnMouseClicked()){
			if (hero!=0)
				HeroSelected = 2;
			printf("%d\n", DeckScene::hero);

		}
		else if (m_pHeroSelect[0]->OnMouseClicked()){
			DeckScene::hero = 1;
			m_pHero->BackGroundRsc("resource/hero/card_1.png");
			printf("%d\n", DeckScene::hero);
		}
		else if (m_pHeroSelect[1]->OnMouseClicked()){
			DeckScene::hero = 2;
			m_pHero->BackGroundRsc("resource/hero/card_2.png");
			printf("%d\n", DeckScene::hero);

		}
		else if (m_pHeroSelect[2]->OnMouseClicked()){
			DeckScene::hero = 3;
			m_pHero->BackGroundRsc("resource/hero/card_3.png");
			printf("%d\n", DeckScene::hero);

		}
		break;

	case 2:
		if (m_pSaveBtn->OnMouseClicked()){
			DeckFileSave();

		}
		else if (m_pDeckPageNext->OnMouseClicked()){
			printf("++\n");
			if (deckListPage != 4)
				DeckScene::deckListPage++;
	
		}
		else if (m_pDeckPageBack->OnMouseClicked()){
			printf("--\n");

			if (deckListPage != 1)
				DeckScene::deckListPage--;
		
		}
		else if (m_pNextPage->OnMouseClicked()){
			for (int i = 0; i < 8; i++)
				cardSpecialNum[i] += 8;
			checker1 = 0;
			checker2 = 0;
			checker3 = 0;
			checker4 = 0;
			checker5 = 0;
			checker6 = 0;
			checker7 = 0;
			checker8 = 0;
			for (int i = 0; i < 8; i++){
				m_pRes->CardCodeFinder(blank, blank, cardSpecialNum[i], blank, blank, blank,rec);
				m_pCard_Lists[i]->AddOnButtonImage(*rec);
				m_pCard_Lists[i]->AddUsualButtonImage(*rec);
			}

		}
		else if (m_pBackPage->OnMouseClicked()){
			if (cardSpecialNum[0] - 8 > 0){
				for (int i = 0; i < 8; i++)
					cardSpecialNum[i] -= 8;
				checker1 = 0;
				checker2 = 0;
				checker3 = 0;
				checker4 = 0;
				checker5 = 0;
				checker6 = 0;
				checker7 = 0;
				checker8 = 0;
				for (int i = 0; i < 8; i++){
					m_pRes->CardCodeFinder(blank, blank, cardSpecialNum[i], blank, blank, blank,rec);
					m_pCard_Lists[i]->AddOnButtonImage(*rec);
					m_pCard_Lists[i]->AddUsualButtonImage(*rec);
				}
			}
		}

		else if (m_pCard_Lists[0]->OnMouseClicked()){
			if (checker1 < 2){
				CardClicked(cardSpecialNum[0]);
				checker1++;
			}
		}
		else if (m_pCard_Lists[1]->OnMouseClicked()){
			if (checker2 < 2)
				CardClicked(cardSpecialNum[1]);


			checker2++;

		}
		else if (m_pCard_Lists[2]->OnMouseClicked()){
			if (checker3 < 2)
				CardClicked(cardSpecialNum[2]);


			checker3++;

		}
		else if (m_pCard_Lists[3]->OnMouseClicked()){
			if (checker4 < 2)
				CardClicked(cardSpecialNum[3]);


			checker4++;

		}
		else if (m_pCard_Lists[4]->OnMouseClicked()){
			if (checker5 < 2)
				CardClicked(cardSpecialNum[4]);


			checker5++;

		}
		else if (m_pCard_Lists[5]->OnMouseClicked()){
			if (checker6 < 2)
				CardClicked(cardSpecialNum[5]);


			checker6++;

		}
		else if (m_pCard_Lists[6]->OnMouseClicked()){
			if (checker7 < 2)
				CardClicked(cardSpecialNum[6]);


			checker7++;

		}
		else if (m_pCard_Lists[7]->OnMouseClicked()){
			if (checker8 < 2)
				CardClicked(cardSpecialNum[7]);


			checker8++;

		}
		break;
	}


}



void DeckScene::render(){
	ISceneNode::render();
	m_pDeckBackGround->render();
	switch (HeroSelected){
	case 1:
		m_pHeroSelect[0]->render();
		m_pHeroSelect[1]->render();
		m_pHeroSelect[2]->render();
		m_pSelect->render();
		m_pDeckBackBtn->render();
		m_pHero->render();
		break;


	case 2:

		m_pSaveBtn->render();
		m_pNextPage->render();
		m_pBackPage->render();
		m_pDeckPageNext->render();
		m_pDeckPageBack->render();
		m_pDeckBackBtn->render();

		for (int i = 0; i < 8; i++)
			m_pCard_Lists[i]->render();



		switch (deckListPage){
		case 1:
			for (int i = 0; i < 10; ++i){
				if (DeckScene::deckList[i] != 0){
					m_pDeckCard[i]->render();
					m_pDeckListText[i]->render();
				}

			}
			break;
		case 2:
			for (int i = 10; i < 20; ++i){
				if (DeckScene::deckList[i] != 0){
					m_pDeckCard[i]->render();
					m_pDeckListText[i]->render();

				}

			}
		case 3:
			for (int i = 20; i < 30; ++i){
				if (DeckScene::deckList[i] != 0){
					m_pDeckCard[i]->render();
					m_pDeckListText[i]->render();

				}
			}
		case 4:
			for (int i = 30; i < 40; ++i){
				if (DeckScene::deckList[i] != 0){
					m_pDeckCard[i]->render();
					m_pDeckListText[i]->render();

				}
			}
		}
		break;
	}
	m_pCusor->render();
}

