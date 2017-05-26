#ifndef _DECKSCENE_H_
#define _DECKSCENE_H_

#include "ISceneNode.h"
#include "GUIButton.h"
#include "BackGround.h"
#include "Font.h"
#include <Windows.h>
#include <tchar.h>
#include <locale.h>
#include "ResourceFinder.h"
#include "MouseCusor.h"
//#include "CardProtocol.h"
class DeckScene : public ISceneNode{
private:
	GUIButton *m_pSaveBtn;
	GUIButton *m_pDeckBackBtn;
	GUIButton *m_pSelect;

	GUIButton *m_pCard_Lists[8];
	GUIButton *m_pDeckCard[40];
	GUIButton *m_pHeroSelect[3];
	GUIButton *m_pNextPage;
	GUIButton *m_pBackPage;
	GUIButton *m_pDeckPageNext;
	GUIButton *m_pDeckPageBack;

	BackGround *m_pDeckBackGround;
	BackGround *m_pSelectBackGround;
	BackGround *m_pHero;
	MouseCusor *m_pCusor;

	POINT	        currentMousePoint;
	
	CFont *m_pDeckListText[40];
	
	ResourceFinder *m_pRes;
	bool clicked = false;

	int cardSpecialNum[8];

	int checker1 = 0;
	int checker2 = 0;
	int checker3 = 0;
	int checker4 = 0;
	int checker5 = 0;
	int checker6 = 0;
	int checker7 = 0;
	int checker8 = 0;
	
	int HeroSelected = 1;
	int hero=0;
	int deckListPage = 1;
	int deckList[40];
	int deckListCounter = 0;

	int x, y;
public:

	DeckScene();
	~DeckScene();

	void DeckFileSave();
	void saveTest();
	void CardClicked(int cardNum);
	void CardTexter(int cardNum,char *recText[]);
	void update(float eTime);
	void render();
};

#endif