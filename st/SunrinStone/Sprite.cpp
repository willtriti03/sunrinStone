#include "stdafx.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "SpriteManager.h"
#include "Application.h"

Sprite::Sprite() : m_pTexture(NULL), m_useBlend(false) {
	m_color = D3DXCOLOR(1.0f ,1.0f, 1.0f, 1.0f);
}
Sprite::~Sprite() {}
void Sprite::Create(std::string path) {
	m_pTexture = TextureMgr->LoadTextureFromFile(path);
	D3DSURFACE_DESC desc;
	m_pTexture->GetLevelDesc(0, &desc);
	m_width = desc.Width;
	m_height = desc.Height;

	m_rect.left = 0;
	m_rect.top = 0;
	m_rect.right = m_width;
	m_rect.bottom = m_height;
}
void Sprite::update(float eTime) {
	ISceneNode::update(eTime);
}
void Sprite::render() {
	ISceneNode::render();
	SpriteMgr->Sprite()->SetTransform(&m_matrix);
	SpriteMgr->Sprite()->Begin(D3DXSPRITE_ALPHABLEND);

	if(m_useBlend) {
		GameApp->GetDevice()->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		GameApp->GetDevice()->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_ONE);
		GameApp->GetDevice()->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	}

	SpriteMgr->Sprite()->Draw(m_pTexture, &m_rect, NULL, NULL, m_color);
	SpriteMgr->Sprite()->End();
}