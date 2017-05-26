#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include "GameScene.h"
#include "Application.h"
#include "InputManager.h"
#include "Computer.h"
#include "SceneManager.h"
#define START 5

Computer::Computer(SoloScene *Solo) {
	m_pRes = new ResourceFinder();
	m_pSolo = Solo;

	srand((unsigned int)time(NULL));

}
Computer::~Computer(){}
void Computer::TurnStart() {
	Card_draw(1);
}


void Computer::Card_draw(int draw){
	srand((unsigned)time(NULL));
	int rd, bk;
	std::string *rec = new std::string;
	for (int i = 0; i < draw; ++i){
		for (int j = 0; j < 8; ++j){
			if (m_pSolo->comHand[j] == 0){
				m_pSolo->comHand[j] = m_pSolo->comdeck[m_pSolo->nowdeck];
				m_pSolo->comdeck[m_pSolo->nowdeck] == 0;

				m_pSolo->nowdeck++;
				j = 8;
			}
			else if (j == 7){
				rd = rand() % 8;
				m_pSolo->comHand[rd] = m_pSolo->comdeck[m_pSolo->nowdeck];
				m_pSolo->comdeck[m_pSolo->nowdeck] == 0;

				m_pSolo->nowdeck++;
			}

		}
	}

}
void Computer::ComDeckStart(){
	std::ifstream DeckFile("decks/comdeckfile.deck");
	DeckFile >> m_pSolo->comhero;
	for (int i = 0; i < 40; ++i){
		DeckFile >> m_pSolo->imsisave[i];
	}
	DeckFile.close();
	int rd;
	int returns = 1;
	for (int i = 0; i < 40; ++i){
		returns = 1;
		while (returns){
			rd = rand() % 40;
			if (m_pSolo->SoloScene::comdeck[rd] == 0){
				m_pSolo->SoloScene::comdeck[rd] = m_pSolo->SoloScene::imsisave[i];
				m_pSolo->SoloScene::imsisave[i] = 0;
				returns = 0;
			}
		}



	}

}



void Computer::UseWeapon(int attackingItem, int weaponBlank) {
	std::string *rec = new std::string;
	//if(컴퓨터의 비밀함수가==false){
	int damge;
	int kind, canUse, cost,shild;
	m_pRes->CardCodeFinder(cost, kind, attackingItem, damge, shild,canUse, rec);
	if (!m_pSolo->SecretCheck(1)){
		if (m_pSolo->comWeaponUse[weaponBlank][0] == 0){
			printf("%d %d %d\n", m_pSolo->comlife, damge, attackingItem);
			m_pSolo->comlife = m_pSolo->comlife+damge;
			m_pSolo->comWeaponUse[weaponBlank][0] = 1;
			m_pSolo->comWeaponUse[weaponBlank][1]++;
			if (m_pSolo->comWeaponUse[weaponBlank][1] == canUse){
				m_pSolo->comWeapon[weaponBlank] = 0;
			}
		}
	}

}

void Computer::Deckdestroy(int target, int destroy) { //덱파괴
	if (!m_pSolo->SecretCheck(2)){
		if (target == 1){
			m_pSolo->nowdeck += destroy;
		}
		else if (target == 2){
			m_pSolo->nowNum += destroy;
		}
	}
}
void Computer::Wear(int cardcode){
	int kind, damge, shild,canuse, cost;
	std::string *rec = new std::string;
	m_pRes->CardCodeFinder(cost, kind, cardcode, damge, shild,canuse, rec);
	if (cost <= topatz){
		topatz -= cost;
		if (m_pSolo->comWeapon[0] == 0){
			if (m_pSolo->comWeapon[1] != 0){
				m_pSolo->comWeapon[0] = m_pSolo->comWeapon[1];
				m_pSolo->comWeaponUse[0][0] = m_pSolo->comWeaponUse[1][0];
				m_pSolo->comWeaponUse[0][1] = m_pSolo->comWeaponUse[1][1];
				m_pSolo->comWeapon[1] = cardcode;
				m_pSolo->comWeaponUse[1][1] = 0;
			}
			else{
				m_pSolo->comWeapon[0] = cardcode;
				m_pSolo->comWeaponUse[0][1] = 0;
			}
		}
		else if (m_pSolo->comWeapon[1] == 0){
			m_pSolo->comWeapon[1] = cardcode;
			m_pSolo->comWeaponUse[1][1] = 0;
		}
		else {
			m_pSolo->comWeapon[0] = m_pSolo->comWeapon[1];
			m_pSolo->comWeaponUse[0][0] = m_pSolo->comWeaponUse[1][0];
			m_pSolo->comWeaponUse[0][1] = m_pSolo->comWeaponUse[1][1];
			m_pSolo->comWeapon[1] = cardcode;
			m_pSolo->comWeaponUse[1][1] = 0;
		}
	}
}
void Computer::Spell(int cardcode){
	switch (cardcode)
	{
	case 1:
		//g효과 구현
		break;
	}
}

bool Computer::SecretCheck(int whatkind) {
	switch (whatkind){
	case 1:
		for (int i = 0; i < 3; ++i){
			if (m_pSolo->comSecret[i] == 23){//덱파괴 방어 카드확인
				return true;
			}
		}
		return false;
		break;
	case 2:
		break;
	}
}

void Computer::Turnend(){
	Card_draw(1);
	topatz = m_pSolo->topatz-1;
	ComThinking();
	m_pSolo->comWeaponUse[0][0] = 0;
	

	m_pSolo->comWeaponUse[1][0] = 0;

}

void Computer::ComThinking(){

	int i;
	int rand_hand;
	int kind, damge, shild,canuse, cost;
	std::string *rec = new std::string;

	m_pRes->CardCodeFinder(cost, kind, m_pSolo->myWeapon[0], damge, shild,canuse, rec);
	if (damge == 1) {
		m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[0], damge, shild,canuse, rec);
		if (damge == 3) {
			UseWeapon(m_pSolo->comWeapon[0], 0);
		}
		else if (damge == 2) {
			UseWeapon(m_pSolo->comWeapon[0], 0);
		}

		else if (damge == 1) {
			UseWeapon(m_pSolo->comWeapon[0], 0);

		}

		else if (damge == 0) {
			int i;
			for (i = 0; i < 8; ++i) {
				m_pRes->CardCodeFinder(cost, kind, m_pSolo->comHand[i], damge, shild,canuse, rec);
				if (damge == 0) break;
			}

			rand_hand = rand() % i - 1;
			Wear(m_pSolo->comHand[rand_hand]);

			m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[1], damge, shild,canuse, rec);
			if (damge == 3) {
				UseWeapon(m_pSolo->comWeapon[1], 1);
			}
			else if (damge == 2){
				UseWeapon(m_pSolo->comWeapon[1], 1);
			}
			else if (damge == 1) {
				UseWeapon(m_pSolo->comWeapon[1], 1);
			}
		}
	}

	else if (damge == 2) {
		m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[0], damge, shild,canuse, rec);
		if (damge == 4) {
			UseWeapon(m_pSolo->comWeapon[0], 0);
		}
		else if (damge == 3) {
			UseWeapon(m_pSolo->comWeapon[0], 0);
		}
		else if (damge == 2) {
			UseWeapon(m_pSolo->comWeapon[0], 0);
		}
		else if (damge == 1) {
			int i;
			for (i = 0; i < 8; ++i) {
				m_pRes->CardCodeFinder(cost, kind, m_pSolo->comHand[i], damge, shild,canuse, rec);
				if (damge == 0) break;
			}
			rand_hand = rand() % i - 1;
			Wear(m_pSolo->comHand[rand_hand]);

			m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[1], damge, shild,canuse, rec);
			if (damge == 4) {
				UseWeapon(m_pSolo->comWeapon[1], 1);
			}
			else if (damge == 3) {
				UseWeapon(m_pSolo->comWeapon[1], 1);
			}
			else if (damge == 2) {
				UseWeapon(m_pSolo->comWeapon[1], 1);
			}

			else if (damge == 0) {
				int i;
				for (i = 0; i < 8; ++i) {
					m_pRes->CardCodeFinder(cost, kind, m_pSolo->comHand[i], damge, shild,canuse, rec);
					if (damge == 0) break;
				}

				rand_hand = rand() % i - 1;
				Wear(m_pSolo->comHand[rand_hand]);
			}
		}
	}

	else if (damge == 3) {
		m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[0], damge, shild,canuse, rec);
		if (damge == 4) {
			UseWeapon(m_pSolo->comWeapon[0], 0);
		}
		else if (damge == 3) {
			UseWeapon(m_pSolo->comWeapon[0], 0);
		}
		else if (damge == 2 || damge == 1) {
			m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[1], damge, shild,canuse, rec);
			if (damge == 4) {
				UseWeapon(m_pSolo->comWeapon[1], 1);
			}
			else if (damge == 3) {
				UseWeapon(m_pSolo->comWeapon[1], 1);
			}
			else if (damge == 0) {
				int i;
				for (i = 0; i < 8; ++i) {
					m_pRes->CardCodeFinder(cost, kind, m_pSolo->comHand[i], damge, shild,canuse, rec);
					if (damge == 0) break;
				}

				rand_hand = rand() % i - 1;
				Wear(m_pSolo->comHand[rand_hand]);
			}
		}
	}

	else if (damge == 4) {
		m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[0], damge, shild,canuse, rec);
		if (damge == 4) {
			UseWeapon(m_pSolo->comWeapon[0], 0);
		}
		else if (damge == 0) {
			int i;
			for (i = 0; i < 8; ++i) {
				m_pRes->CardCodeFinder(cost, kind, m_pSolo->comHand[i], damge, shild,canuse, rec);
				if (damge == 0) break;
			}

			rand_hand = rand() % i - 1;
			Wear(m_pSolo->comHand[rand_hand]);
		}
		else if (damge == 3 || damge == 2 || damge == 1) {
			m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[1], damge, shild,canuse, rec);
			if (damge == 4) {
				UseWeapon(m_pSolo->comWeapon[1], 1);
			}
			else if (damge != 4) {
				m_pRes->CardCodeFinder(cost, kind, m_pSolo->myWeapon[1], damge, shild,canuse, rec);
				if (damge == 1) {
					m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[0], damge, shild,canuse, rec);
					if (damge == 3) {
						UseWeapon(m_pSolo->comWeapon[0], 0);
					}
					else if (damge == 2) {
						UseWeapon(m_pSolo->comWeapon[0], 0);
					}

					else if (damge == 1) {
						UseWeapon(m_pSolo->comWeapon[0], 0);
					}

					else if (damge == 0) {
						int i;
						for (i = 0; i < 8; ++i) {
							m_pRes->CardCodeFinder(cost, kind, m_pSolo->comHand[i], damge, shild,canuse, rec);
							if (damge == 0) break;
						}

						rand_hand = rand() % i - 1;
						Wear(m_pSolo->comHand[rand_hand]);

						m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[1], damge, shild,canuse, rec);
						if (damge == 3) {
							UseWeapon(m_pSolo->comWeapon[1], 1);
						}
						else if (damge == 2){
							UseWeapon(m_pSolo->comWeapon[1], 1);
						}
						else if (damge == 1) {
							UseWeapon(m_pSolo->comWeapon[1], 1);
						}
						else if (damge == 0) {
							int i;
							for (i = 0; i < 8; ++i) {
								m_pRes->CardCodeFinder(cost, kind, m_pSolo->comHand[i], damge, shild,canuse, rec);
								if (damge == 0) break;
							}

							rand_hand = rand() % i - 1;
							Wear(m_pSolo->comHand[rand_hand]);
						}
					}
				}

				else if (damge == 2) {
					m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[0], damge, shild,canuse, rec);
					if (damge == 4) {
						UseWeapon(m_pSolo->comWeapon[0], 0);
					}
					else if (damge == 3) {
						UseWeapon(m_pSolo->comWeapon[0], 0);
					}
					else if (damge == 2) {
						UseWeapon(m_pSolo->comWeapon[0], 0);
					}
					else if (damge == 1 || damge == 0) {
						m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[1], damge, shild,canuse, rec);
						if (damge == 4) {
							UseWeapon(m_pSolo->comWeapon[1], 1);
						}
						else if (damge == 3) {
							UseWeapon(m_pSolo->comWeapon[1], 1);
						}
						else if (damge == 2) {
							UseWeapon(m_pSolo->comWeapon[1], 1);
						}
						else if (damge == 0) {
							int i;
							for (i = 0; i < 8; ++i) {
								m_pRes->CardCodeFinder(cost, kind, m_pSolo->comHand[i], damge, shild,canuse, rec);
								if (damge == 0) break;
							}

							rand_hand = rand() % i - 1;
							Wear(m_pSolo->comHand[rand_hand]);
						}
					}
				}

				else if (damge == 3) {
					m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[0], damge, shild,canuse, rec);
					if (damge == 4) {
						UseWeapon(m_pSolo->comWeapon[0], 0);
					}
					else if (damge == 3) {
						UseWeapon(m_pSolo->comWeapon[0], 0);
					}
					else if (damge == 0) {
						int i;
						for (i = 0; i < 8; ++i) {
							m_pRes->CardCodeFinder(cost, kind, m_pSolo->comHand[i], damge, shild,canuse, rec);
							if (damge == 0) break;
						}

						rand_hand = rand() % i - 1;
						Wear(m_pSolo->comHand[rand_hand]);
					}

					else if (damge == 2 || damge == 1) {
						m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[1], damge, shild,canuse, rec);
						if (damge == 4) {
							UseWeapon(m_pSolo->comWeapon[1], 1);
						}
						else if (damge == 3) {
							UseWeapon(m_pSolo->comWeapon[1], 1);
						}
						else if (damge == 0) {
							int i;
							for (i = 0; i < 8; ++i) {
								m_pRes->CardCodeFinder(cost, kind, m_pSolo->comHand[i], damge, shild,canuse, rec);
								if (damge == 0) break;
							}

							rand_hand = rand() % i - 1;
							Wear(m_pSolo->comHand[rand_hand]);

						}
					}
				}

				else if (damge == 4) {
					m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[0], damge, shild,canuse, rec);
					if (damge == 4) {
						UseWeapon(m_pSolo->comWeapon[0], 0);
					}
					else if (damge == 0) {
						int i;
						for (i = 0; i < 8; ++i) {
							m_pRes->CardCodeFinder(cost, kind, m_pSolo->comHand[i], damge, shild,canuse, rec);
							if (damge == 0) break;
						}

						rand_hand = rand() % i - 1;
						Wear(m_pSolo->comHand[rand_hand]);
					}
					else if (damge == 3 || damge == 2 || damge == 1) {
						m_pRes->CardCodeFinder(cost, kind, m_pSolo->comWeapon[1], damge, shild,canuse, rec);
						if (damge == 4) {
							UseWeapon(m_pSolo->comWeapon[1], 1);
						}
						else if (damge == 0) {
							int i;
							for (i = 0; i < 8; ++i) {
								m_pRes->CardCodeFinder(cost, kind, m_pSolo->comHand[i], damge, shild,canuse, rec);
								if (damge == 0) break;
							}

							rand_hand = rand() % i - 1;
							Wear(m_pSolo->comHand[rand_hand]);
						}
					}
				}
			}
		}
	}
}