#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include "ISceneNode.h"
#include "SoloScene.h"
#include "ResourceFinder.h"
class Computer : public ISceneNode {
private:
	SoloScene *m_pSolo;
	ResourceFinder *m_pRes;

	void Damage();
	void Bigyo();
	void Deckdestroy(int you, int destroy);

	void Wear(int cardcode);
	void Spell(int cardcode);
public:
	Computer(SoloScene *Solo);
	~Computer();

	int topatz = 0;


	void TurnStart();
	void ComDeckStart();
	void Card_draw(int draw);
	void UseWeapon(int damge, int weapon);
	void ComThinking();
	bool SecretCheck(int whatKind);
	void Turnend();

};

#endif