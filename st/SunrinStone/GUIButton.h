#ifndef _GUIBUTTON_H_
#define _GUIBUTTON_H_

#include "ISceneNode.h"
#include "Sprite.h"
#include <string>

class GUIButton :public ISceneNode{
private:
	Sprite* Image[2];			//��ư �̹���			0���׸� : �����̹���, 1���׸� : ���콺 �ö���� �� �̹���
	POINT	currentMousePoint;	//���콺�� ���� ��ġ
	RECT	collision;			//��ư�� �浹����
	int		btn_state=0;			//��ư�� ����			���� : 0, ���콺 �ö�� : 1
	bool    renderSleep;
	bool    clickBool;
public:
	GUIButton();
	~GUIButton();

	void AddUsualButtonImage(std::string path);
	void AddOnButtonImage(std::string path);
	bool OnMouseClicked();		//��ư�̺�Ʈ : ��ư�� ���콺�� Ŭ���Ǹ� true, Ŭ������ ������ false�� ��ȯ
	bool OnReleased();

	void update(float eTime);
	void render();

private:
	void updateCollision();		//��ư�� �浹������ ������Ʈ����
	bool OnMouseEnter();		//���콺�� ��ư���� �ö���� true �ƴϸ� false�� ��ȯ
};

#endif