#ifndef _SHOPSCENE_H_
#define _SHOPSCENE_H_

#include "ISceneNode.h"
#include "GUIButton.h"
#include "BackGround.h"
#include "ResourceFinder.h"
#include "MouseCusor.h"


class ShopScene : public ISceneNode{
private:

	ResourceFinder *m_pRes;
	MouseCusor *m_pCusor;

	GUIButton *m_pright_card;
	GUIButton *m_pleft_card;
	GUIButton *m_pBackBtn;
	GUIButton *m_pBuyBtn;

	GUIButton *m_pcard_5;
	GUIButton *m_pcard_15;
	GUIButton *m_pcard_30;

	GUIButton *m_pBuyCard[5];


	BackGround *m_pBackGround;
	BackGround *m_pMoney[3];

	POINT	   currentMousePoint;

	int x, y;


	int page;
	int limitPage;
	int buycard = 0;
	int cardIndex[30];

	void CardUpdate(int page);

public:
	ShopScene();
	~ShopScene();
	int money=1;

	void update(float eTime);
	void render();


};
#endif