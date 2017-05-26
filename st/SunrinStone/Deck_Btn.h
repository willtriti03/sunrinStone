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

	void AddUsual(std::string path);	//��ư�� �ƹ� �̺�Ʈ�� ���� ������ �̹���


	bool IsDown();						//��ư�� ������ true �ȴ����� false��ȯ
	bool isOn;
	void Update(float eTime);
	void Render();
};

#endif