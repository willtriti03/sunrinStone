#include "stdafx.h"
#include "Font.h"

CFont::CFont(int bufferSize, UINT size, char* fontname)
{
	string = new char[bufferSize];
	this->fontname = fontname;
	D3DXCreateFontA(GameApp->GetInstance()->GetDevice(), size, size / 2 - size / 10, FW_HEAVY, D3DX_DEFAULT, NULL, DEFAULT_CHARSET, OUT_TT_PRECIS, CLEARTYPE_QUALITY, NULL, fontname, &font);

	color = D3DCOLOR_ARGB(255, 0, 0, 0);
}
CFont::~CFont()
{
	//delete( font );
	delete[] string;
}

void CFont::render()
{
	ISceneNode::render();

	SpriteMgr->Sprite()->SetTransform(&getMatrix());
	SpriteMgr->Sprite()->Begin(D3DXSPRITE_ALPHABLEND);
	font->DrawTextA(SpriteMgr->Sprite(), string, len, NULL, DT_TOP | DT_LEFT | DT_NOCLIP, color);
	SpriteMgr->Sprite()->End();
}
void CFont::update(float eTime)
{
	ISceneNode::update(eTime);
}

void CFont::setString(char string[], bool autosize)
{
	strcpy_s(this->string, strlen(string) + 1, string);
	if (autosize)
	{
		len = strlen(this->string);
	}
}