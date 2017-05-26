#ifndef _DECK_H_
#define _DECK_H_

#include "ResourceFinder.h"
#include "Soting.h"
class SoloScene;

class Deck {
public:
	Deck(SoloScene *Solo);
	~Deck();
	SoloScene *m_pSolo;
	ResourceFinder *m_pRes;
	Soting *m_pSoting;
	void DrawCard(char MEorYOU, int drawCard);
};

#endif