#include "stdafx.h"
#include "Application.h"
#include "ResourceFinder.h"
#include <string>
#include <iostream>
#include <fstream>

ResourceFinder::ResourceFinder(){
}
ResourceFinder::~ResourceFinder(){}
void ResourceFinder::CardCodeFinder(int &cost, int &kind, int cardCode, int &damge, int &shild, int &canUse, std::string *rec){
	int i = 0;
	char szBuf[_MAX_PATH] = { 0, };
	sprintf_s(szBuf, _MAX_PATH, "cardFile/card_%d.card", cardCode);
	std::ifstream DeckFile(szBuf);
	DeckFile >> *rec >> cost >> damge >> shild >> canUse >> kind;
	DeckFile.close();
	
}
void ResourceFinder::NumSetting(int destroyNum,std::string *ten, std::string *one){
	char szBuf[_MAX_PATH] = { 0, };
	switch (destroyNum / 10){
	case 0:
		*ten = "resource/share/blank.png";
		break;
	default:
		sprintf_s(szBuf, _MAX_PATH, "resource/number/%d.png", destroyNum / 10);
		*ten = szBuf;
		break;
	}

	sprintf_s(szBuf, _MAX_PATH, "resource/number/%d.png", destroyNum % 10);
	*one = szBuf;
}
void ResourceFinder::Spell(int cardcode){
	switch (cardcode)
	{
	case 1:
		break;
	}

}
void ResourceFinder::update(float eTime){
	ISceneNode::update(eTime);
}
void ResourceFinder::render(){
	ISceneNode::render();
}