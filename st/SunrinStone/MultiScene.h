#ifndef _MULTISCENE_H_
#define _MULTISCENE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "GameScene.h"
#include "SceneManager.h"
#include "Application.h"
#include "InputManager.h"
#include "ISceneNode.h"
#include "GUIButton.h"
#include "BackGround.h"
#include "Font.h"
#include "CClient.h"
#include "MouseCusor.h"
class ResourceFinder;

class MultiScene : public ISceneNode, ThreadClass {
private:
	GUIButton	    *m_pTurnBtn;
	GUIButton	    *m_pOptionBtn;
	GUIButton	    *m_pUse;
	GUIButton       *m_pAttacking;
	GUIButton       *m_pCancle;

	GUIButton	    *m_pMyHero;
	GUIButton	    *m_pMyHand[8];
	GUIButton	    *m_pMyDeck;
	GUIButton	    *m_pMyWeapon[2];

	GUIButton	    *m_pMultiHero;
	GUIButton	    *m_pMultiDeck;
	GUIButton	    *m_pMultiWeapon[2];

	GUIButton       *m_pMySecret[3];
	GUIButton       *m_pMultiSecret[3];

	BackGround	    *m_pMyLifePoint[2];
	BackGround	    *m_pMultiLifePoint[2];

	BackGround      *m_pMultiHand;
	BackGround      *m_pTopatz[2];
	BackGround      *m_pBackGround;
	BackGround      *m_pShowWindow;
	MouseCusor		*m_pCusor;

	POINT	        currentMousePoint;

	ResourceFinder  *m_pRes;

	int x, y;

	int  imsiSave[40];

	int  myDeck[40];
	int  myHand[8];
	int  mySecret[3];
	int  myWeaponUse[2][2];

	int  hero = 0;
	int  myLife = 0;
	int  useBtn = 0;

	int  *clickedWeapon;
	int  clickW;

	void Action(int *cardcode);
	void AIUpdate();
	void Attack(int attackingItem, int weaponBlank);
	void DeckBurst(int burst_Me_OR_You, int cards);
	void DeckLoading();
	void DeckSupl();
	void DrawCard(int DrawCards);
	void MulitiHandRec();
	void NumUpdate();
	void Spell(int spellCard);
	void Wear(int WeaponCode);
	void WeaponAction(int *cardcode, int weaponUse);

	///////////////////////

	CClient *cli;
	void run();

	char buf[BUFSIZ];
	int i = 0;

public:
	MultiScene();
	~MultiScene();
	int	 topatz = 1;
	int  full_topatz = 1;

	int  myWeapon[2];
	int  nowNum = 0;

	int nowdeck = 0;
	int comlife = 0;

	int comWeaponUse[2][2];
	int imsisave[40];

	int comSecret[3];
	int comdeck[40];
	int comhero = 0;
	int comHand[8];

	int comWeapon[2];

	bool SecretCheck(int whatKind);

	void update(float eTime);
	void render();

};

#endif