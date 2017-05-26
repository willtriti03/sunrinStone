#include "Deck_Btn.h"

Deck_Btn::Deck_Btn(std::string path) {
	isOn = false;  //포인터들을 nullptr로 초기화
	m_pSprite = new Sprite;
	GetCursorPos(&currentMousePoint); //현재 마우스 포인터의 위치를 저장함
}
Deck_Btn::~Deck_Btn() {
	//동적할당된 모든 리소스를 해제
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
