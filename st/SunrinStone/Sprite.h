#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "ISceneNode.h"
#include <string>

class Sprite : public ISceneNode {
private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	RECT m_rect;
	int m_width;
	int m_height;
	D3DXCOLOR m_color;
	bool m_useBlend;

public:
	Sprite();
	~Sprite();

	void Create(std::string path);

	void update(float eTime);
	void render();

public:
	void SetColor(D3DXCOLOR c) { m_color = c; }
	void SetBlend(bool b) { m_useBlend = b; }

	D3DXVECTOR2 GetCenterPosition() {
		return D3DXVECTOR2(m_position.x + m_width/2, m_position.y + m_height/2);
	}
	RECT GetRect() { return m_rect; }
};

#endif