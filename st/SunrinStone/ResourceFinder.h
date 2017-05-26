#ifndef _RESOURCEFINDER_H_
#define _RESOURCEFINDER_H_

#include "ISceneNode.h"

class ResourceFinder:public ISceneNode{
public:

	ResourceFinder();
	~ResourceFinder();
	void CardCodeFinder(int &cost, int &kind, int cardCode, int &damge, int &shild, int &canUse,std::string *rec);
	void NumSetting(int destoryNum, std::string *ten, std::string *one);
	void Spell(int cardcode);
	void update(float eTime);
	void render();
};

#endif