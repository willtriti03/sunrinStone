#include "stdafx.h"

#include "Soting.h"
#include "SoloScene.h"

void Soting::HandSoting(char MEorYOU){
	int bk;
	std::string *rec = new std::string;
	if (MEorYOU == 'm'){
		for (int i = 0; i < 8; ++i){
			if (m_pSolo->myHand[i] == 0){
				for (int j = i + 1; j < 8; ++j){
					if (m_pSolo->myHand[j] != 0){
						m_pSolo->myHand[i] = m_pSolo->myHand[j];
						m_pSolo->myHand[j] = 0;
						j = 9;
					}
				}
			}

		}
		for (int i = 0; i < 8; ++i){

			m_pRes->CardCodeFinder(bk, bk, m_pSolo->myHand[i], bk, bk,bk, rec);
			m_pSolo->m_pMyHand[i]->AddOnButtonImage(*rec);
			m_pSolo->m_pMyHand[i]->AddUsualButtonImage(*rec);
		}

	}
	else{
		for (int i = 0; i < 8; ++i){
			if (m_pSolo->comHand[i] == 0){
				for (int j = i + 1; j < 8; ++j){
					if (m_pSolo->comHand[j] != 0){
						m_pSolo->comHand[i] = m_pSolo->comHand[j];
						m_pSolo->comHand[j] = 0;
						j = 9;
					}
				}
			}

		}
	

	}
}