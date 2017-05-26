#ifndef _MOUSECUSOR_H_
#define _MOUSECUSOR_H_
#include "ISceneNode.h"
#include "BackGround.h"
#include "Application.h"
class MouseCusor: public ISceneNode{
public:
	BackGround *m_pCusor;
	POINT	    currentMousePoint;
	MouseCusor();
	~MouseCusor();
	int x, y;
	void update(float eTime);
	void render();


};
#endif