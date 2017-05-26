#ifndef _FONT_H_
#define _FONT_H_

#include "ISceneNode.h"
#include "Application.h"
#include "SpriteManager.h"

class CFont :public ISceneNode{
private:
	LPD3DXFONT font;
public:
	char *string;
	char *fontname;
	DWORD color;
	int len;

	CFont(int bufferSize, UINT size, char* fontname = "¸¼Àº °íµñ");
	~CFont();

	void render();
	void update(float eTime);

	void setString(char string[], bool autosize = true);
};

#endif