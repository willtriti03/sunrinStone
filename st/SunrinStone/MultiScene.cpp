#include "stdafx.h"
#include "MultiScene.h"
#include "ResourceFinder.h"

#include<thread>

void MultiScene::run(){	//자바의 void run()과 같음
	char readBuf[BUFSIZ];
	int readInt;

	while (true){
		if ((cli->read(&readInt, readBuf)) != CCLIENT_NO_MORE_DATA){	//전송
			if (readInt == -1){//읽어들일 버퍼 없음
				continue;
			}

			//값확인
			std::cout << readInt << " / " << readBuf << std::endl;
		}
	}
}

MultiScene::MultiScene() {

	for (int i = 0; i < 2; ++i){
		myWeapon[i]= comWeapon[i] = 0;
	}

	for (int i = 0; i < 3; ++i){
		comSecret[i] = 0;
	}

	for (int i = 0; i < 8; ++i){
		myHand[i] = comHand[i]=0;
	}

	for (int i = 0; i < 40; ++i){
		imsiSave[i]= imsisave[i]= comdeck[i] = myDeck[i] = 0;
	}

	cli = new CClient("127.0.0.1", 10000);

	start();//쓰레드 시작

	////////////BackGround//////////////
	m_pCusor = new MouseCusor();
	m_pBackGround = new BackGround();
	m_pMultiHand = new BackGround();
	m_pShowWindow = new BackGround();
	m_pTopatz[0] = new BackGround();
	m_pTopatz[1] = new BackGround();

	m_pMyLifePoint[0] = new BackGround();
	m_pMyLifePoint[1] = new BackGround();
	m_pMultiLifePoint[0] = new BackGround();
	m_pMultiLifePoint[1] = new BackGround();

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
	m_pRes = new ResourceFinder();

	///////////////////////BackGround////////////////////////////////
	m_pBackGround->BackGroundRsc("resource/solo/ma_2.png");
	m_pMultiHand->BackGroundRsc("resource/share/blank.png");
	m_pShowWindow->BackGroundRsc("resource/share/blank.png");



	m_pTopatz[0]->BackGroundRsc("resource/share/blank.png");
	m_pTopatz[1]->BackGroundRsc("resource/share/blank.png");

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
	m_pMultiHero->AddUsualButtonImage("resource/share/blank.png");
	m_pMultiDeck->AddUsualButtonImage("resource/solo/deck.jpg");
	m_pMultiWeapon[0]->AddUsualButtonImage("resource/solo/weapon_card.png");
	m_pMultiWeapon[1]->AddUsualButtonImage("resource/solo/weapon_card.png");

	//Clicked
	m_pOptionBtn->AddOnButtonImage("resource/deck/back_bt_in.png");//("resource/solo/set_up.png");
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
	m_pShowWindow->setPosition(D3DXVECTOR2(460, 250));
	m_pTopatz[0]->setPosition(D3DXVECTOR2(440, 380));
	m_pTopatz[1]->setPosition(D3DXVECTOR2(460, 380));

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
	m_pMultiWeapon[1]->setPosition(D3DXVECTOR2(600, 0));

	m_pMyLifePoint[0]->setPosition(D3DXVECTOR2(657, 363));
	m_pMyLifePoint[1]->setPosition(D3DXVECTOR2(677, 363));

	m_pMultiLifePoint[0]->setPosition(D3DXVECTOR2(293, 309));
	m_pMultiLifePoint[1]->setPosition(D3DXVECTOR2(313, 309));
	//Font

	///////////FOR////////////////////////////


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


	DeckLoading();
	DeckSupl();
	DrawCard(5);

	for (int i = 0; i < 40; ++i)
		printf("%d\n", MultiScene::comdeck[i]);
	for (int i = 0; i < 8; ++i)
		printf("%d  ", comHand[i]);
	printf("\n");

}

MultiScene::~MultiScene() {}

void MultiScene::Action(int *cardcode){
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

void MultiScene::AIUpdate(){
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
	case 0:
		*rec = "resource/share/blank.png";

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

void MultiScene::Attack(int attackingItem, int weaponBlank){
	std::string *rec = new std::string;
	//if(컴퓨터의 비밀함수가==false){
	int damge;
	int kind, canUse, cost,shild;
	m_pRes->CardCodeFinder(cost, kind, attackingItem, damge, shild,canUse, rec);
	if (myWeaponUse[weaponBlank][0] == 0){
		MultiScene::myLife += damge;
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
	printf("%d %d\n", myWeapon[0], myWeapon[1]);
	printf("%d  %d %d %d\n", myWeaponUse[0][0], myWeaponUse[0][1], myWeaponUse[1][0], myWeaponUse[1][1]);

}

void MultiScene::DeckBurst(int burst_Me_OR_You, int cards){
	
		if (burst_Me_OR_You == 1){
			nowNum += cards;
		}
		else if (burst_Me_OR_You == 2){
			nowdeck += cards;
		}
	
}


void MultiScene::DeckSupl(){
	int rd;
	int returns = 1;
	for (int i = 0; i < 40; ++i){
		returns = 1;
		while (returns){
			rd = rand() % 40;
			if (MultiScene::myDeck[rd] == 0){
				MultiScene::myDeck[rd] = MultiScene::imsiSave[i];
				MultiScene::imsiSave[i] = 0;
				returns = 0;
			}
		}



	}

}

void MultiScene::DrawCard(int drawCard){
	srand((unsigned)time(NULL));
	int rd, bk;
	std::string *rec = new std::string;
	for (int i = 0; i < drawCard; ++i){
		for (int j = 0; j < 8; ++j){
			if (MultiScene::myHand[j] == 0){
				MultiScene::myHand[j] = MultiScene::myDeck[nowNum];
				MultiScene::myDeck[nowNum] =0;

				nowNum++;
				j = 8;
			}
			else if (j == 7){
				rd = rand() % 8;
				MultiScene::myHand[rd] = MultiScene::myDeck[nowNum];
				MultiScene::myDeck[nowNum] = 0;

				nowNum++;
			}

		}
	}
	for (int i = 0; i < 8; ++i){
		m_pRes->CardCodeFinder(bk, bk, myHand[i],bk, bk, bk, rec);
		m_pMyHand[i]->AddOnButtonImage(*rec);
		m_pMyHand[i]->AddUsualButtonImage(*rec);
	}

}

void MultiScene::MulitiHandRec(){
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

void MultiScene::NumUpdate(){
	std::string *ten = new std::string;
	std::string *one = new std::string;

	m_pRes->NumSetting(comlife, ten, one);
	m_pMultiLifePoint[0]->BackGroundRsc(*ten);
	m_pMultiLifePoint[1]->BackGroundRsc(*one);

	m_pRes->NumSetting(myLife, ten, one);
	m_pMyLifePoint[0]->BackGroundRsc(*ten);
	m_pMyLifePoint[1]->BackGroundRsc(*one);


	m_pRes->NumSetting(topatz, ten, one);
	m_pTopatz[0]->BackGroundRsc(*ten);
	m_pTopatz[1]->BackGroundRsc(*one);

}

bool MultiScene::SecretCheck(int whatKind){
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

void MultiScene::Spell(int cardcode){
	switch (cardcode)
	{
	case 1:
		//g효과 구현
		break;
	}
}

void MultiScene::Wear(int cardcode){
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
		printf("%d %d\n", myWeapon[0], myWeapon[1]);
		printf("%d  %d %d %d\n", myWeaponUse[0][0], myWeaponUse[0][1], myWeaponUse[1][0], myWeaponUse[1][1]);
		m_pRes->CardCodeFinder(cost, kind, myWeapon[0], damge, shild,canUse, rec);
		m_pMyWeapon[0]->AddOnButtonImage(*rec);
		m_pMyWeapon[0]->AddUsualButtonImage(*rec);
		m_pRes->CardCodeFinder(cost, kind, myWeapon[1], damge, shild,canUse, rec);
		m_pMyWeapon[1]->AddOnButtonImage(*rec);
		m_pMyWeapon[1]->AddUsualButtonImage(*rec);
		*clickedWeapon = 0;

	}
}

void MultiScene::WeaponAction(int *cardcode, int weaponUse){
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

}




void MultiScene::update(float eTime){
	ISceneNode::update(eTime);
	int damge, kind, canUse,shild, cost;
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

	m_pTopatz[0]->update(eTime);
	m_pTopatz[1]->update(eTime);

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

	
	////////////////////////////////////////////////////
	NumUpdate();
	AIUpdate();
	MulitiHandRec();

	////////////////////////////////////////////////////



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

	else{
		m_pShowWindow->BackGroundRsc("resource/share/blank.png");
		m_pShowWindow->setPosition(D3DXVECTOR2(460, 250));

	}
	/////////////////////////////////////////////////////////////////////////
	if (m_pOptionBtn->OnMouseClicked()) {
		m_pShowWindow->BackGroundRsc("resource/setting/set_1.png");
		m_pShowWindow->setPosition(D3DXVECTOR2(0, 0));
	}

	else if (m_pTurnBtn->OnMouseClicked()) {
		if (full_topatz + 1 <= 10)
			full_topatz++;
		topatz = full_topatz;
		myWeaponUse[0][0] = 0;
		myWeaponUse[1][0] = 0;
		useBtn = 4;
		useBtn = 0;
		DrawCard(1);
	}


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
			strcpy(buf, "m_pUse OnClick");
			cli->write(++i, buf);

			m_pRes->CardCodeFinder(cost, kind, *clickedWeapon, damge, shild,canUse, rec);
			switch (kind){
			case 1:
				Wear(*clickedWeapon);
				break;
			case 2:
				Spell(*clickedWeapon);
				break;
			}
			useBtn = 0;
		}
		else if (m_pCancle->OnMouseClicked()){
			strcpy(buf, "m_pCancel OnClick");
			cli->write(++i, buf);

			useBtn = 0;
		}
	case 3:
		if (m_pAttacking->OnMouseClicked()){
			strcpy(buf, "m_pAttack OnClick");
			cli->write(++i, buf);

			Attack(*clickedWeapon, clickW);
			useBtn = 0;

		}
		else if (m_pCancle->OnMouseClicked()){
			strcpy(buf, "m_pCancel OnClick");
			cli->write(++i, buf);

			useBtn = 0;
		}
	}

}

void MultiScene::render(){
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