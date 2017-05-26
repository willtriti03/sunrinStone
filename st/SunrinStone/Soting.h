#ifndef _SOTING_H_
#define _SOTING_H_

#include "ResourceFinder.h"

class SoloScene;

class Soting {
public:
	Soting();
	~Soting();
	SoloScene *m_pSolo;
	ResourceFinder *m_pRes;
	void HandSoting(char MEorYOU);

};

#endif