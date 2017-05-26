#include "stdafx.h"
#include "MouseCusor.h"

MouseCusor::MouseCusor(){
	m_pCusor = new BackGround();
	m_pCusor->BackGroundRsc("resource/cusor/mus.png");
	pushScene(m_pCusor, false);
	m_pCusor->setPosition(D3DXVECTOR2(0, 0));

	
};
MouseCusor::~MouseCusor(){};
void MouseCusor::update(float eTime){
	ISceneNode::update(eTime);
	m_pCusor->update(eTime);

	RECT tmp;
	GetCursorPos(&currentMousePoint);
	GetWindowRect(GameApp->GetHWND(), &tmp);
	x = currentMousePoint.x - tmp.left;
	y = currentMousePoint.y - tmp.top;
	m_pCusor->setPosition(D3DXVECTOR2(x - 10, y - 30 + 0.05*(y % (tmp.bottom - tmp.top))));
}
void MouseCusor::render(){
	m_pCusor->render();
}
