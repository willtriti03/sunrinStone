#include "stdafx.h"
#include "SoloScene.h"
#include "Computer.h"
#include "ResourceFinder.h"
#include "Deck.h"
#include <atlstr.h>
#include "WinScene.h"
#include "LoseScene.h"
#include "SoloStopScene.h"
#include <fstream>
SoloScene::SoloScene() {

	////////////BackGround//////////////
	m_pBackGround = new BackGround();
	m_pMultiHand = new BackGround();
	m_pShowWindow = new BackGround();
	m_pTopatz[0] = new BackGround();
	m_pTopatz[1] = new BackGround();

	m_pMyLifePoint[0] = new BackGround();
	m_pMyLifePoint[1] = new BackGround();
	m_pMultiLifePoint[0] = new BackGround();
	m_pMultiLifePoint[1] = new BackGround();
	m_pComTopatz[0] = new BackGround();
	m_pComTopatz[1] = new BackGround();

	

	m_pCusor = new MouseCusor();
	////////////GUIButton///////////////
	m_pOptionBtn = new GUIButton();
	m_pTurnBtn = new GUIButton();
	m_pUse = new GUIButton();
	m_pAttacking = new GUIButton();
	m_pCancle = new GUIButton();

	m_pMyHero = new GUIButton();
	m_pMyDeck = new GUIButton();
	m_pMyWeapon[0] = new GUIButton();
	m_pMyWeapon[1] = new GUIButton();

	m_pMultiHero = new GUIButton();
	m_pMultiDeck = new GUIButton();
	m_pMultiWeapon[0] = new GUIButton();
	m_pMultiWeapon[1] = new GUIButton();

	//////////CFont/////////////////////////
	m_pCom = new Computer(this);
	m_pRes = new ResourceFinder();
	m_pDeck = new Deck(this);
	///////////////////////BackGround////////////////////////////////

	m_pBackGround->BackGroundRsc("resource/solo/ma_2.png");
	m_pMultiHand->BackGroundRsc("resource/share/blank.png");
	m_pShowWindow->BackGroundRsc("resource/share/blank.png");

	m_pTopatz[0]->BackGroundRsc("resource/share/blank.png");
	m_pTopatz[1]->BackGroundRsc("resource/share/blank.png");

	m_pComTopatz[0]->BackGroundRsc("resource/share/blank.png");
	m_pComTopatz[1]->BackGroundRsc("resource/share/blank.png");

	m_pMultiLifePoint[0]->BackGroundRsc("resource/share/blank.png");
	m_pMultiLifePoint[1]->BackGroundRsc("resource/share/blank.png");

	m_pMultiLifePoint[0]->BackGroundRsc("resource/share/blank.png");
	m_pMultiLifePoint[1]->BackGroundRsc("resource/share/blank.png");

	m_pMyLifePoint[0]->BackGroundRsc("resource/share/blank.png");
	m_pMyLifePoint[1]->BackGroundRsc("resource/share/blank.png");



	///////////////////////GUIButton////////////////////////////
	//Usual
	m_pOptionBtn->AddUsualButtonImage("resource/solo/set_up.png");
	m_pTurnBtn->AddUsualButtonImage("resource/deck/back_bt_on.png");
	m_pUse->AddUsualButtonImage("resource/solo/use.png");
	m_pAttacking->AddUsualButtonImage("resource/solo/attack.png");
	m_pCancle->AddUsualButtonImage("resource/solo/cancle.png");
	///MY////
	m_pMyHero->AddUsualButtonImage("resource/multi/card.png");
	m_pMyDeck->AddUsualButtonImage("resource/solo/deck.jpg");
	m_pMyWeapon[0]->AddUsualButtonImage("resource/solo/weapon_card.png");
	m_pMyWeapon[1]->AddUsualButtonImage("resource/solo/weapon_card.png");

	///MULTI////
	m_pMultiHero->AddUsualButtonImage("resource/multi/card.png");
	m_pMultiDeck->AddUsualButtonImage("resource/solo/deck.jpg");
	m_pMultiWeapon[0]->AddUsualButtonImage("resource/solo/weapon_card.png");
	m_pMultiWeapon[1]->AddUsualButtonImage("resource/solo/weapon_card.png");

	//Clicked
	m_pOptionBtn->AddOnButtonImage("resource/deck/back_bt_in.png");
	m_pTurnBtn->AddOnButtonImage("resource/deck/back_bt_in.png");
	m_pUse->AddOnButtonImage("resource/solo/use_1.png");
	m_pAttacking->AddOnButtonImage("resource/solo/attack_1.png");
	m_pCancle->AddOnButtonImage("resource/solo/cancle_1.png");

	m_pMyHero->AddOnButtonImage("resource/multi/card.png");
	m_pMyDeck->AddOnButtonImage("resource/solo/deck.jpg");
	m_pMyWeapon[0]->AddOnButtonImage("resource/solo/weapon_card.png");
	m_pMyWeapon[1]->AddOnButtonImage("resource/solo/weapon_card.png");

	m_pMultiHero->AddOnButtonImage("resource/multi/card.png");
	m_pMultiDeck->AddOnButtonImage("resource/solo/deck.jpg");
	m_pMultiWeapon[0]->AddOnButtonImage("resource/solo/weapon_card.png");
	m_pMultiWeapon[1]->AddOnButtonImage("resource/solo/weapon_card.png");

	///////////////CFont///////////


	/////////////PUSHSCENE/////////////////
	//Back
	pushScene(m_pBackGround, false);
	pushScene(m_pMultiHand, false);
	pushScene(m_pShowWindow, false);
	pushScene(m_pAttacking, false);
	pushScene(m_pCancle, false);
	pushScene(m_pTopatz[0], false);
	pushScene(m_pTopatz[1], false);
	pushScene(m_pComTopatz[0],false);
	pushScene(m_pComTopatz[1],false);
	//Button
	pushScene(m_pOptionBtn, false);
	pushScene(m_pTurnBtn, false);
	pushScene(m_pUse, false);

	pushScene(m_pMyHero, false);
	pushScene(m_pMyDeck, false);
	pushScene(m_pMyWeapon[0], false);
	pushScene(m_pMyWeapon[1], false);

	pushScene(m_pMultiHero, false);
	pushScene(m_pMultiDeck, false);
	pushScene(m_pMultiWeapon[0], false);
	pushScene(m_pMultiWeapon[1], false);
	pushScene(m_pMyLifePoint[0], false);
	pushScene(m_pMyLifePoint[1], false);
	pushScene(m_pMultiLifePoint[0], false);
	pushScene(m_pMultiLifePoint[1], false);


	//Font    


	///////////POSITION//////////////////
	//Back

	m_pBackGround->setPosition(D3DXVECTOR2(0, 0));
	m_pMultiHand->setPosition(D3DXVECTOR2(640, -80));
	m_pShowWindow->setPosition(D3DXVECTOR2(420, 250));
	m_pTopatz[0]->setPosition(D3DXVECTOR2(440, 380));
	m_pTopatz[1]->setPosition(D3DXVECTOR2(460, 380));
	m_pComTopatz[0]->setPosition(D3DXVECTOR2(530, 310));
	m_pComTopatz[1]->setPosition(D3DXVECTOR2(550, 310));
	//Button
	m_pOptionBtn->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 45, 0));
	m_pTurnBtn->setPosition(D3DXVECTOR2(GameApp->GetWindowWidth() - 110, GameApp->GetWindowHeight() - 400));

	m_pMyHero->setPosition(D3DXVECTOR2(450, 420));
	m_pMyDeck->setPosition(D3DXVECTOR2(0, 450));
	m_pMyWeapon[0]->setPosition(D3DXVECTOR2(680, 450));
	m_pMyWeapon[1]->setPosition(D3DXVECTOR2(850, 450));

	m_pMultiHero->setPosition(D3DXVECTOR2(450, 0));
	m_pMultiDeck->setPosition(D3DXVECTOR2(1024 - 30, 110));
	m_pMultiWeapon[0]->setPosition(D3DXVECTOR2(250, 0));
	m_pMultiWeapon[1]->setPosition(D3DXVECTOR2(100, 0));

	m_pMyLifePoint[0]->setPosition(D3DXVECTOR2(657, 363));
	m_pMyLifePoint[1]->setPosition(D3DXVECTOR2(677, 363));

	m_pMultiLifePoint[0]->setPosition(D3DXVECTOR2(303, 326));
	m_pMultiLifePoint[1]->setPosition(D3DXVECTOR2(323, 326));
	//Font

	///////////FOR////////////////////////////
	for (int i = 0; i < 2; ++i){
		m_pDamge_My1[i] = new BackGround();
		m_pDamge_My2[i] = new BackGround();
		m_pUse_My1[i] = new BackGround();
		m_pUse_My2[i] = new BackGround();

		m_pDamge_Com1[i] = new BackGround();
		m_pDamge_Com2[i] = new BackGround();
		m_pUse_Com1[i] = new BackGround();
		m_pUse_Com2[i] = new BackGround();

		m_pDamge_My1[i]		->BackGroundRsc("resource/share/blank.png");
		m_pDamge_My2[i]		->BackGroundRsc("resource/share/blank.png");
		m_pUse_My1[i]		->BackGroundRsc("resource/share/blank.png");
		m_pUse_My2[i]		->BackGroundRsc("resource/share/blank.png");

		m_pDamge_Com1[i]	->BackGroundRsc("resource/share/blank.png");
		m_pDamge_Com2[i]	->BackGroundRsc("resource/share/blank.png");
		m_pUse_Com1[i]		->BackGroundRsc("resource/share/blank.png");
		m_pUse_Com2[i]		->BackGroundRsc("resource/share/blank.png");
	
		pushScene(m_pDamge_My1[i]  ,false);
		pushScene(m_pDamge_My2[i]  ,false);
		pushScene(m_pUse_My1[i]	   ,false);
		pushScene(m_pUse_My2[i]	   ,false);
								
		pushScene(m_pDamge_Com1[i] ,false);
		pushScene(m_pDamge_Com2[i] ,false);
		pushScene(m_pUse_Com1[i]   ,false);
		pushScene(m_pUse_Com2[i]   ,false);

		m_pDamge_My1[i]		->setPosition(D3DXVECTOR2(680+10*i,600));
		m_pDamge_My2[i]		->setPosition(D3DXVECTOR2(855+10*i,600));

		m_pUse_My1[i]		->setPosition(D3DXVECTOR2(790+10*i,600));
		m_pUse_My2[i]		->setPosition(D3DXVECTOR2(955+10*i,600));
												   
		m_pDamge_Com1[i]	->setPosition(D3DXVECTOR2(260+10*i,150));
		m_pDamge_Com2[i]	->setPosition(D3DXVECTOR2(610+10*i,150));

		m_pUse_Com1[i]		->setPosition(D3DXVECTOR2(290+10*i,150));
		m_pUse_Com2[i]		->setPosition(D3DXVECTOR2(630+10*i,150));
	}

	for (int i = 0; i < 8; i++){
		m_pMyHand[i] = new GUIButton();

		m_pMyHand[i]->AddOnButtonImage("resource/multi/card.png");

		m_pMyHand[i]->AddUsualButtonImage("resource/multi/card.png");

		pushScene(m_pMyHand[i], false);

		m_pMyHand[i]->setPosition(D3DXVECTOR2(30 + (120 * i), GameApp->GetWindowHeight() - 100));
	}

	myWeaponUse[0][0] = 0;
	myWeaponUse[0][1] = 0;

	myWeaponUse[1][0] = 0;
	myWeaponUse[1][1] = 0;

	comWeaponUse[0][0] = 0;
	comWeaponUse[0][1] = 0;

	comWeaponUse[1][0] = 0;
	comWeaponUse[1][1] = 0;



	DeckLoading();
	DeckSupl();
	DrawCard(5);
	comlife = 0;
	m_pCom->ComDeckStart();
	m_pCom->Card_draw(5);
	NumUpdate();
	AIUpdate();
	MulitiHandRec();

}

SoloScene::~SoloScene() {}

void SoloScene::Action(int *cardcode){
	int kind, damge;
	std::string *rec = new std::string;
	GetCursorPos(&currentMousePoint);
	RECT tmp;
	GetWindowRect(GameApp->GetHWND(), &tmp);

	int x = currentMousePoint.x - tmp.left;
	int y = currentMousePoint.y - tmp.top;
	m_pUse->setPosition(D3DXVECTOR2(x + 10, y));
	m_pCancle->setPosition(D3DXVECTOR2(x + 10, y - 40));
	clickedWeapon = cardcode;
	useBtn = 1;

}

void SoloScene::AIUpdate(){
	int kind, damge, shild,canUse, cost;
	std::string *rec = new std::string;

	switch (comhero)
	{
	case 1:
		*rec = "resource/hero/card_1.png";
		break;
	case 2:
		*rec = "resource/hero/card_2.png";
		break;
	case 3:
		*rec = "resource/hero/card_3.png";
		break;
	}
	m_pMultiHero->AddOnButtonImage(*rec);
	m_pMultiHero->AddUsualButtonImage(*rec);
	switch (hero)
	{
	case 1:
		*rec = "resource/hero/card_1.png";
		break;
	case 2:
		*rec = "resource/hero/card_2.png";
		break;
	case 3:
		*rec = "resource/hero/card_3.png";
		break;
	}
	m_pMyHero->AddOnButtonImage(*rec);
	m_pMyHero->AddUsualButtonImage(*rec);
	for (int i = 0; i < 2; ++i){
		m_pRes->CardCodeFinder(cost, kind, comWeapon[i], damge, shild,canUse, rec);
		m_pMultiWeapon[i]->AddOnButtonImage(*rec);
		m_pMultiWeapon[i]->AddUsualButtonImage(*rec);
	}

}

void SoloScene::Attack(int attackingItem, int weaponBlank){
	std::string *rec = new std::string;
	//if(컴퓨터의 비밀함수가==false){
	if (full_topatz != 1){
		int damge;
		int kind, canUse, cost,shild;
		m_pRes->CardCodeFinder(cost, kind, attackingItem, damge, shild,canUse, rec);
		if (myWeaponUse[weaponBlank][0] == 0){
			SoloScene::myLife += damge;
			myWeaponUse[weaponBlank][0] = 1;
			myWeaponUse[weaponBlank][1]++;
			if (myWeaponUse[weaponBlank][1] == canUse){
				myWeapon[weaponBlank] = 0;
				myWeaponUse[weaponBlank][1] = 0;
			}
		}
		m_pRes->CardCodeFinder(cost, kind, myWeapon[0], damge, shild,canUse, rec);
		m_pMyWeapon[0]->AddOnButtonImage(*rec);
		m_pMyWeapon[0]->AddUsualButtonImage(*rec);
		m_pRes->CardCodeFinder(cost, kind, myWeapon[1], damge, shild,canUse, rec);
		m_pMyWeapon[1]->AddOnButtonImage(*rec);
		m_pMyWeapon[1]->AddUsualButtonImage(*rec);

	}
}

void SoloScene::DeckBurst(int burst_Me_OR_You, int cards){
	if (!m_pCom->SecretCheck(2)){
		if (burst_Me_OR_You == 1){
			nowNum += cards;
		}
		else if (burst_Me_OR_You == 2){
			nowdeck += cards;
		}
	}

}

void SoloScene::DeckLoading(){
	std::ifstream DeckFile("decks/deckfile.deck");
	DeckFile >> hero;
	for (int i = 0; i < 40; ++i){
		DeckFile >> imsiSave[i];
	}
	DeckFile.close();
}

void SoloScene::DeckSupl(){
	int rd;
	int returns = 1;
	for (int i = 0; i < 40; ++i){
		returns = 1;
		while (returns){
			rd = rand() % 40;
			if (SoloScene::myDeck[rd] == 0){
				SoloScene::myDeck[rd] = SoloScene::imsiSave[i];
				SoloScene::imsiSave[i] = 0;
				returns = 0;
			}
		}



	}

}

void SoloScene::DrawCard(int drawCard){
	srand((unsigned)time(NULL));
	int rd, bk;
	std::string *rec = new std::string;
	HandSoting();
	for (int i = 0; i < drawCard; ++i){
		for (int j = 0; j < 8; ++j){
			if (SoloScene::myHand[j] == 0){
				SoloScene::myHand[j] = SoloScene::myDeck[nowNum];
				SoloScene::myDeck[nowNum]= 0;

				nowNum++;
				j = 8;
			}
			else if (j == 7){
				rd = rand() % 8;
				SoloScene::myHand[rd] = SoloScene::myDeck[nowNum];
				SoloScene::myDeck[nowNum]= 0;

				nowNum++;
			}

		}
	}
	for (int i = 0; i < 8; ++i){
		m_pRes->CardCodeFinder(bk, bk, myHand[i], bk, bk,bk, rec);
		m_pMyHand[i]->AddOnButtonImage(*rec);
		m_pMyHand[i]->AddUsualButtonImage(*rec);
	}
	MulitiHandRec();




}

void SoloScene::GameEnd(){
	if (myLife == 80){
		SceneMgr->changeScene(new WinScene);

	}
	else if(comlife == 80){
		SceneMgr->changeScene(new LoseScene);

	}
	else if ((myDeck[39] == 0 || comdeck[39] == 0)&&myLife > comlife){
		SceneMgr->changeScene(new WinScene);

	}
	else if ((myDeck[39] == 0 || comdeck[39] == 0)&&myLife < comlife){
		SceneMgr->changeScene(new LoseScene);

	}
	else if ((myDeck[39] == 0 || comdeck[39] == 0)&&myLife == comlife){
		SceneMgr->changeScene(new LoseScene);
	}


}
void SoloScene::HandSoting(){
	int bk;
	std::string *rec = new std::string;
	for (int i = 0; i < 8; ++i){
		if (SoloScene::myHand[i] == 0){
			for (int j = i + 1; j < 8; ++j){
				if (SoloScene::myHand[j] != 0){
					SoloScene::myHand[i] = SoloScene::myHand[j];
					SoloScene::myHand[j] = 0;
					j = 9;
				}
			}
		}

	}
	for (int i = 0; i < 8; ++i){

		m_pRes->CardCodeFinder(bk, bk, SoloScene::myHand[i], bk,bk, bk, rec);
		SoloScene::m_pMyHand[i]->AddOnButtonImage(*rec);
		SoloScene::m_pMyHand[i]->AddUsualButtonImage(*rec);
	}

}
void SoloScene::MulitiHandRec(){
	int cnt = 0;
	std::string *rec = new std::string;
	for (int i = 0; i < 8; ++i){
		if (comHand[i] != 0)cnt++;
	}
	switch (cnt)
	{
	case 1:
		*rec = "resource/card/hand_1.png";
		break;
	case 2:
		*rec = "resource/card/hand_2.png";
		break;

	case 3:
		*rec = "resource/card/hand_3.png";
		break;

	case 4:
		*rec = "resource/card/hand_4.png";
		break;

	case 5:
		*rec = "resource/card/hand_5.png";
		break;

	case 6:
		*rec = "resource/card/hand_6.png";
		break;

	case 7:
		*rec = "resource/card/hand_7.png";
		break;

	case 8:
		*rec = "resource/card/hand_8.png";
		break;

	case 0:
		*rec = "resource/share/blank.png";
		break;
	}
	m_pMultiHand->BackGroundRsc(*rec);
}

void SoloScene::NumUpdate(){
	std::string *ten = new std::string;
	std::string *one = new std::string;
	int bl, damge,shild, use;
	m_pRes->NumSetting(comlife, ten, one);
	m_pMultiLifePoint[0]->BackGroundRsc(*ten);
	m_pMultiLifePoint[1]->BackGroundRsc(*one);

	m_pRes->NumSetting(myLife, ten, one);
	m_pMyLifePoint[0]->BackGroundRsc(*ten);
	m_pMyLifePoint[1]->BackGroundRsc(*one);


	m_pRes->NumSetting(topatz, ten, one);
	m_pTopatz[0]->BackGroundRsc(*ten);
	m_pTopatz[1]->BackGroundRsc(*one);

	m_pRes->CardCodeFinder(bl, bl, myWeapon[0], damge,shild, use, ten);
	m_pRes->NumSetting(damge, ten, one);
	m_pDamge_My1[0]->BackGroundRsc(*ten);
	m_pDamge_My1[1]->BackGroundRsc(*one);

	m_pRes->NumSetting(use-myWeaponUse[0][1], ten, one);
	m_pUse_My1[0]->BackGroundRsc(*ten);
	m_pUse_My1[1]->BackGroundRsc(*one);

	m_pRes->CardCodeFinder(bl, bl, myWeapon[1], damge,shild, use, ten);
	m_pRes->NumSetting(damge, ten, one);
	m_pDamge_My2[0]->BackGroundRsc(*ten);
	m_pDamge_My2[1]->BackGroundRsc(*one);

	m_pRes->NumSetting(use - myWeaponUse[1][1], ten, one);
	m_pUse_My2[0]->BackGroundRsc(*ten);
	m_pUse_My2[1]->BackGroundRsc(*one);

	m_pRes->CardCodeFinder(bl, bl, comWeapon[0], damge,shild, use, ten);
	m_pRes->NumSetting(damge, ten, one);
	m_pDamge_Com1[0]->BackGroundRsc(*ten);
	m_pDamge_Com1[1]->BackGroundRsc(*one);

	m_pRes->NumSetting(use - comWeaponUse[0][1], ten, one);
	m_pUse_Com1[0]->BackGroundRsc(*ten);
	m_pUse_Com1[1]->BackGroundRsc(*one);

	m_pRes->CardCodeFinder(bl, bl, comWeapon[1], damge,shild, use, ten);
	m_pRes->NumSetting(damge, ten, one);
	m_pDamge_Com2[0]->BackGroundRsc(*ten);
	m_pDamge_Com2[1]->BackGroundRsc(*one);

	m_pRes->NumSetting(use - comWeaponUse[1][1], ten, one);
	m_pUse_Com2[0]->BackGroundRsc(*ten);
	m_pUse_Com2[1]->BackGroundRsc(*one);
	
	m_pRes->NumSetting(m_pCom->topatz, ten, one);
	m_pComTopatz[0]->BackGroundRsc(*ten);
	m_pComTopatz[1]->BackGroundRsc(*one);
}

bool SoloScene::SecretCheck(int whatKind){
	switch (whatKind){
	case 1:
		for (int i = 0; i < 3; ++i){
			if (mySecret[i] == 23){//덱파괴 방어 카드확인
				return true;
			}
		}
		return false;
		break;
	case 2:
		break;

	}
}

void SoloScene::Wear(int cardcode){
	int kind, damge, shild,canUse, cost;
	std::string *rec = new std::string;
	m_pRes->CardCodeFinder(cost, kind, cardcode, damge, shild,canUse, rec);
	if (cost <= topatz){
		topatz -= cost;
		if (myWeapon[0] == 0){
			if (myWeapon[1] != 0){
				myWeapon[0] = myWeapon[1];
				myWeaponUse[0][0] = myWeaponUse[1][0];
				myWeaponUse[0][1] = myWeaponUse[1][1];
				myWeapon[1] = cardcode;
				myWeaponUse[1][1] = 0;

			}
			else{
				myWeapon[0] = cardcode;
				myWeaponUse[0][1] = 0;


			}
		}
		else if (myWeapon[1] == 0){
			myWeapon[1] = cardcode;
			myWeaponUse[1][1] = 0;


		}
		else {
			myWeapon[0] = myWeapon[1];
			myWeaponUse[0][0] = myWeaponUse[1][0];
			myWeaponUse[0][1] = myWeaponUse[1][1];
			myWeapon[1] = cardcode;
			myWeaponUse[1][1] = 0;


		}
		m_pRes->CardCodeFinder(cost, kind, myWeapon[0], damge, shild,canUse, rec);
		m_pMyWeapon[0]->AddOnButtonImage(*rec);
		m_pMyWeapon[0]->AddUsualButtonImage(*rec);
		m_pRes->CardCodeFinder(cost, kind, myWeapon[1], damge, shild,canUse, rec);
		m_pMyWeapon[1]->AddOnButtonImage(*rec);
		m_pMyWeapon[1]->AddUsualButtonImage(*rec);
		*clickedWeapon = 0;

	}
	NumUpdate();
	AIUpdate();
	MulitiHandRec();

}

void SoloScene::WeaponAction(int *cardcode, int weaponUse){
	GetCursorPos(&currentMousePoint);
	RECT tmp;
	GetWindowRect(GameApp->GetHWND(), &tmp);
	int x = currentMousePoint.x - tmp.left;
	int y = currentMousePoint.y - tmp.top;
	m_pCancle->setPosition(D3DXVECTOR2(x + 10, y - 40));
	m_pAttacking->setPosition(D3DXVECTOR2(x + 10, y));
	clickedWeapon = cardcode;
	clickW = weaponUse;
	useBtn = 3;
	NumUpdate();
	AIUpdate();
	MulitiHandRec();


}

void SoloScene::update(float eTime){
	ISceneNode::update(eTime);
	int damge, kind, canUse, cost,shild;
	std::string *rec = new std::string;
	static float currentTime = 0.f;

	/////////////////////////Update///////////////////////////
	m_pTurnBtn->update(eTime);
	m_pOptionBtn->update(eTime);
	m_pUse->update(eTime);
	m_pAttacking->update(eTime);
	m_pCancle->update(eTime);
	m_pBackGround->update(eTime);
	m_pShowWindow->update(eTime);
	m_pCusor->update(eTime);

	m_pTopatz[0]->update(eTime);
	m_pTopatz[1]->update(eTime);
	m_pComTopatz[0]->update(eTime);
	m_pComTopatz[1]->update(eTime);
	//////////////My////////////////
	m_pMyDeck->update(eTime);

	m_pMyWeapon[0]->update(eTime);
	m_pMyWeapon[1]->update(eTime);



	m_pMyLifePoint[0]->update(eTime);
	m_pMyLifePoint[1]->update(eTime);

	for (int i = 0; i < 8; ++i){
		m_pMyHand[i]->update(eTime);
	}
	/////////////MULTI/////////////////
	m_pMultiHand->update(eTime);


	m_pMultiLifePoint[0]->update(eTime);
	m_pMultiLifePoint[1]->update(eTime);

	for (int i = 0; i < 2; ++i){
		m_pDamge_My1[i] ->update(eTime);
		m_pDamge_My2[i] ->update(eTime);
		m_pUse_My1[i] ->update(eTime);
		m_pUse_My2[i] ->update(eTime);

		m_pDamge_Com1[i] ->update(eTime);
		m_pDamge_Com2[i] ->update(eTime);
		m_pUse_Com1[i] ->update(eTime);
		m_pUse_Com2[i] ->update(eTime);
	}
	////////////////////////////////////////////////////

	
	////////////////////////////////////////////////////

	if (m_pOptionBtn->OnMouseClicked()) {
		SceneMgr->changeScene(new SoloStopScene(this),false);

	}

	else if (m_pTurnBtn->OnMouseClicked()) {
		if (full_topatz + 1 <= 8)
			full_topatz++;
			topatz = full_topatz;
			myWeaponUse[0][0] = 0;
			myWeaponUse[1][0] = 0;
			useBtn = 4;
			m_pCom->Turnend();
			useBtn = 0;
			DrawCard(1);
			NumUpdate();
			AIUpdate();
			MulitiHandRec();

	}

	///////////////////////////HandRealse//////////////////////////////
	if (m_pMyHand[0]->OnReleased()&&myHand[0] != 0){
		m_pRes->CardCodeFinder(cost, kind, myHand[0], damge, shild,canUse, rec);
		m_pShowWindow->BackGroundRsc(*rec);

	}
	else if (m_pMyHand[1]->OnReleased()&&myHand[1] != 0){
		m_pRes->CardCodeFinder(cost, kind, myHand[1], damge, shild,canUse, rec);
		m_pShowWindow->BackGroundRsc(*rec);

	}
	else if (m_pMyHand[2]->OnReleased()&&myHand[2] != 0){
		m_pRes->CardCodeFinder(cost, kind, myHand[2], damge, shild,canUse, rec);
		m_pShowWindow->BackGroundRsc(*rec);

	}
	else if (m_pMyHand[3]->OnReleased()&&myHand[3] != 0){
		m_pRes->CardCodeFinder(cost, kind, myHand[3], damge, shild,canUse, rec);
		m_pShowWindow->BackGroundRsc(*rec);

	}
	else if (m_pMyHand[4]->OnReleased()&&myHand[4] != 0){
		m_pRes->CardCodeFinder(cost, kind, myHand[4], damge, shild,canUse, rec);
		m_pShowWindow->BackGroundRsc(*rec);

	}
	else if (m_pMyHand[5]->OnReleased()&&myHand[5] != 0){
		m_pRes->CardCodeFinder(cost, kind, myHand[5], damge, shild,canUse, rec);
		m_pShowWindow->BackGroundRsc(*rec);

	}
	else if (m_pMyHand[6]->OnReleased()&&myHand[6] != 0){
		m_pRes->CardCodeFinder(cost, kind, myHand[6], damge, shild,canUse, rec);
		m_pShowWindow->BackGroundRsc(*rec);

	}
	else if (m_pMyHand[7]->OnReleased()&&myHand[7] != 0){
		m_pRes->CardCodeFinder(cost, kind, myHand[7], damge, shild,canUse, rec);
		m_pShowWindow->BackGroundRsc(*rec);

	}
	else if (m_pMyWeapon[0]->OnReleased()&&myWeapon[0] != 0){
		m_pRes->CardCodeFinder(cost, kind, myWeapon[0], damge, shild,canUse, rec);
		m_pShowWindow->BackGroundRsc(*rec);

	}
	else if (m_pMyWeapon[1]->OnReleased()&&myWeapon[1] != 0){
		m_pRes->CardCodeFinder(cost, kind, myWeapon[1], damge, shild,canUse, rec);
		m_pShowWindow->BackGroundRsc(*rec);

	}
	else if (m_pMultiWeapon[0]->OnReleased()&&myWeapon[0] != 0){
		m_pRes->CardCodeFinder(cost, kind, myWeapon[0], damge, shild,canUse, rec);
		m_pShowWindow->BackGroundRsc(*rec);

	}
	else if (m_pMultiWeapon[1]->OnReleased()&&myWeapon[1] != 0){
		m_pRes->CardCodeFinder(cost, kind, myWeapon[1], damge, shild,canUse, rec);
		m_pShowWindow->BackGroundRsc(*rec);

	}

	else
		m_pShowWindow->BackGroundRsc("resource/share/blank.png");
	/////////////////////////////////////////////////////////////////////////

	////////////////////////////Use///////////////////////////////
	switch (useBtn){
	case 0:
		if (m_pMyHand[0]->OnMouseClicked()&&myHand[0] != 0){
			Action(&myHand[0]);

		}
		else if (m_pMyHand[1]->OnMouseClicked()&&myHand[1] != 0){
			Action(&myHand[1]);

		}
		else if (m_pMyHand[2]->OnMouseClicked()&&myHand[2] != 0){
			Action(&myHand[2]);

		}
		else if (m_pMyHand[3]->OnMouseClicked()&&myHand[3] != 0){
			Action(&myHand[3]);

		}
		else if (m_pMyHand[4]->OnMouseClicked()&&myHand[4] != 0){
			Action(&myHand[4]);

		}
		else if (m_pMyHand[5]->OnMouseClicked()&&myHand[5] != 0){
			Action(&myHand[5]);

		}
		else if (m_pMyHand[6]->OnMouseClicked()&&myHand[6] != 0){
			Action(&myHand[6]);

		}
		else if (m_pMyHand[7]->OnMouseClicked()&&myHand[7] != 0){
			Action(&myHand[7]);

		}
		else if (m_pMyWeapon[0]->OnMouseClicked()&&myWeapon[0] != 0){
			WeaponAction(&myWeapon[0], 0);

		}
		else if (m_pMyWeapon[1]->OnMouseClicked()&&myWeapon[1] != 0){
			WeaponAction(&myWeapon[1], 1);

		}
	}



	//////////////////////////////////////////////////
	switch (useBtn){
	case 1:
		if (m_pUse->OnMouseClicked()){
			m_pRes->CardCodeFinder(cost, kind, *clickedWeapon, damge, shild,canUse, rec);
			switch (kind){
			case 1:
				Wear(*clickedWeapon);
				HandSoting();
				break;
			case 2:
				
				break;
			}
			useBtn = 0;
		}
		else if (m_pCancle->OnMouseClicked()){
			useBtn = 0;
		}
	case 3:
		if (m_pAttacking->OnMouseClicked()){
			Attack(*clickedWeapon, clickW);
			useBtn = 0;

		}
		else if (m_pCancle->OnMouseClicked()){
			useBtn = 0;
		}
	}
	//////////////////////////////////////////////////
	GameEnd();
}

void SoloScene::render(){
	ISceneNode::render();


	m_pBackGround->render();

	m_pTurnBtn->render();
	m_pOptionBtn->render();

	m_pMyHero->render();
	m_pMyDeck->render();
	m_pMyWeapon[0]->render();
	m_pMyWeapon[1]->render();


	m_pMultiHero->render();
	m_pMultiDeck->render();
	m_pMultiWeapon[0]->render();
	m_pMultiWeapon[1]->render();


	m_pTopatz[0]->render();
	m_pTopatz[1]->render();
	m_pComTopatz[0]->render();
	m_pComTopatz[1]->render();
	m_pMultiHand->render();
	m_pShowWindow->render();
	for (int i = 0; i < 8; ++i){
		if (myHand[i] != 0)
			m_pMyHand[i]->render();
	}



	m_pMyLifePoint[0]->render();
	m_pMyLifePoint[1]->render();
	m_pMultiLifePoint[0]->render();
	m_pMultiLifePoint[1]->render();
	for (int i = 0; i < 2; ++i){
		if (myWeapon[0] != 0){
			m_pDamge_My1[i]->render();
			m_pUse_My1[i]->render();
		}
		if (myWeapon[1] != 0){
			m_pUse_My2[i]->render();
			m_pDamge_My2[i]->render();
		}
		if (comWeapon[0] != 0){
			m_pDamge_Com1[i]->render();
			m_pUse_Com1[i]->render();
		}
		if (comWeapon[1] != 0){
			m_pDamge_Com2[i]->render();
			m_pUse_Com2[i]->render();
		}
	}
	switch (useBtn)
	{
	case 1:
		m_pUse->render();
		m_pCancle->render();

		break;
	case 3:
		m_pAttacking->render();
		m_pCancle->render();

		break;
	}
	m_pCusor->render();
}