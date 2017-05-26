#include "stdafx.h"

#include "Deck.h"
#include "SoloScene.h"

Deck::Deck(SoloScene *Solo){};
Deck::~Deck(){};
void Deck::DrawCard(char MEorYOU,int drawCard){
	srand((unsigned)time(NULL));
	int rd, bk;
	std::string *rec = new std::string;
	if (MEorYOU == 'm'){
		m_pSoting->HandSoting(MEorYOU);
		for (int i = 0; i < drawCard; ++i){
			for (int j = 0; j < 8; ++j){
				if (m_pSolo->SoloScene::myHand[j] == 0){
					m_pSolo->SoloScene::myHand[j] = m_pSolo->SoloScene::myDeck[m_pSolo->nowNum];
					m_pSolo->SoloScene::myDeck[m_pSolo->nowNum] = 0;

					m_pSolo->nowNum++;
					j = 8;
				}
				else if (j == 7){
					rd = rand() % 8;
					m_pSolo->SoloScene::myHand[rd] = m_pSolo->SoloScene::myDeck[m_pSolo->nowNum];
					m_pSolo->SoloScene::myDeck[m_pSolo->nowNum] = 0;

					m_pSolo->nowNum++;
				}

			}
		}



		for (int i = 0; i < 8; ++i){


			m_pRes->CardCodeFinder(bk, bk, m_pSolo->myHand[i], bk,bk, bk, rec);
			m_pSolo->SoloScene::m_pMyHand[i]->AddOnButtonImage(*rec);
			m_pSolo->SoloScene::m_pMyHand[i]->AddUsualButtonImage(*rec);
		}


	}


	/////////////////////////////////////////////////////
	if (MEorYOU == 'y'){
		m_pSoting->HandSoting(MEorYOU);
		for (int i = 0; i < drawCard; ++i){
			for (int j = 0; j < 8; ++j){
				if (m_pSolo->SoloScene::comHand[j] == 0){
					m_pSolo->SoloScene::comHand[j] = m_pSolo->SoloScene::comdeck[m_pSolo->nowNum];
					m_pSolo->SoloScene::comdeck[m_pSolo->nowNum] = 0;

					m_pSolo->nowNum++;
					j = 8;
				}
				else if (j == 7){
					rd = rand() % 8;
					m_pSolo->SoloScene::comHand[rd] = m_pSolo->SoloScene::comdeck[m_pSolo->nowNum];
					m_pSolo->SoloScene::comdeck[m_pSolo->nowNum] = 0;

					m_pSolo->nowNum++;
				}

			}
		}
	}
}