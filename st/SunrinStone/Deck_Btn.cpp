#include "Deck_Btn.h"

Deck_Btn::Deck_Btn(std::string path) {
	isOn = false;  //�����͵��� nullptr�� �ʱ�ȭ
	m_pSprite = new Sprite;
	GetCursorPos(&currentMousePoint); //���� ���콺 �������� ��ġ�� ������
}
Deck_Btn::~Deck_Btn() {
	//�����Ҵ�� ��� ���ҽ��� ����
}

bool GUIButton::IsDown() {
	GetCursorPos(&currentMousePoint);
	if (currentMousePoint.x > Image[0]->pos.x && currentMousePoint.x < Image[0]->pos.x + Image[0]->rect.right &&
		currentMousePoint.y > Image[0]->pos.y && currentMousePoint.y < Image[0]->pos.y + Image[0]->rect.bottom) {
		isOn = true;
		return true;
	}
	isOn = false;
	return false;
}
void GUIButton::Update(float eTime) {
	GetCursorPos(&currentMousePoint);
	if (currentMousePoint.x > Image[0]->pos.x && currentMousePoint.x < Image[0]->pos.x + Image[0]->rect.right &&
		currentMousePoint.y > Image[0]->pos.y && currentMousePoint.y < Image[0]->pos.y + Image[0]->rect.bottom) {
		isOn = true;
	}
	else {
		isOn = false;
	}
}
void GUIButton::Render(D3DXMATRIX* pmat) {
	IObject::Render(pmat);
	if (isOn) {
		Image[0]->Render(NULL);
	}
	else {
		Image[0]->Render(pmat);
	}
}
