#ifndef _ISCENENODE_H_
#define _ISCENENODE_H_

#include <list>
#include "DXUT.h"

class ISceneNode {
protected:
	ISceneNode* m_pParent; //�θ���
	std::list<ISceneNode*> m_child; //�ڽĳ��

protected:
	D3DXMATRIX m_matrix; //��ȯ���
	D3DXVECTOR2 m_scale; //ũ�����
	D3DXVECTOR2 m_scalingCenter; //ũ�Ⱑ ���ϴ� �߽���
	D3DXVECTOR2 m_rotationCenter; //ȸ�� �߽���
	D3DXVECTOR2 m_position; //��ġ
	float m_rotation; //ȸ������ (����)
	bool m_erase; //�������� ����
	bool m_update; //������Ʈ ����

public:
	ISceneNode();
	virtual ~ISceneNode();

	virtual void update(float eTime);
	virtual void render();

public:
	void pushScene(ISceneNode* p, bool update = true);
	void popScene(ISceneNode* p, bool erase = false);

public:
	//set�Լ�
	void setMatrix(D3DXMATRIX m)				{ m_matrix = m; }
	void setScale(D3DXVECTOR2 s)					{ m_scale = s; }
	void setScalingCenter(D3DXVECTOR2 sc)	{ m_scalingCenter = sc; }
	void setRotation(float angle)						{ m_rotation = angle; }
	void setRotationCenter(D3DXVECTOR2 rc)	{ m_rotationCenter = rc; }
	void setPosition(D3DXVECTOR2 p)				{ m_position = p; }

public:
	//get�Լ�
	D3DXMATRIX getMatrix()						{ return m_matrix; }
	D3DXVECTOR2 getScale()					{ return m_scale; }
	D3DXVECTOR2 getScalingCenter()		{ return m_scalingCenter; }
	D3DXVECTOR2 getRotationCenter()		{ return m_rotationCenter; }
	D3DXVECTOR2 getPosition()					{ return m_position; }
	float getRotation()								{ return m_rotation; }
};

#endif