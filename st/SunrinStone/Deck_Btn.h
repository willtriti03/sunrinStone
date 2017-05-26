#ifndef _DECKBTN_H_
#define _DECKBTN_H_

#include "ISceneNode.h"
#include "Sprite.h"
#include <string>

class Deck_Btn :public ISceneNode{
private:
	Sprite* m_pSprite;
	POINT	 currentMousePoint;

public:
	Deck_Btn(std::string path);
	virtual~Deck_Btn();

	void AddUsual(std::string path);	//버튼에 아무 이벤트가 없는 평상시의 이미지


	bool IsDown();						//버튼이 눌리면 true 안눌리면 false반환
	bool isOn;
	void Update(float eTime);
	void Render();
};

#endif