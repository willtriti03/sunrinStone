#ifndef _ISCENENODE_H_
#define _ISCENENODE_H_

#include <list>
#include "DXUT.h"

class ISceneNode {
protected:
	ISceneNode* m_pParent; //부모노드
	std::list<ISceneNode*> m_child; //자식노드

protected:
	D3DXMATRIX m_matrix; //변환행렬
	D3DXVECTOR2 m_scale; //크기비율
	D3DXVECTOR2 m_scalingCenter; //크기가 변하는 중심점
	D3DXVECTOR2 m_rotationCenter; //회전 중심점
	D3DXVECTOR2 m_position; //위치
	float m_rotation; //회전각도 (라디안)
	bool m_erase; //지워지는 여부
	bool m_update; //업데이트 여부

public:
	ISceneNode();
	virtual ~ISceneNode();

	virtual void update(float eTime);
	virtual void render();

public:
	void pushScene(ISceneNode* p, bool update = true);
	void popScene(ISceneNode* p, bool erase = false);

public:
	//set함수
	void setMatrix(D3DXMATRIX m)				{ m_matrix = m; }
	void setScale(D3DXVECTOR2 s)					{ m_scale = s; }
	void setScalingCenter(D3DXVECTOR2 sc)	{ m_scalingCenter = sc; }
	void setRotation(float angle)						{ m_rotation = angle; }
	void setRotationCenter(D3DXVECTOR2 rc)	{ m_rotationCenter = rc; }
	void setPosition(D3DXVECTOR2 p)				{ m_position = p; }

public:
	//get함수
	D3DXMATRIX getMatrix()						{ return m_matrix; }
	D3DXVECTOR2 getScale()					{ return m_scale; }
	D3DXVECTOR2 getScalingCenter()		{ return m_scalingCenter; }
	D3DXVECTOR2 getRotationCenter()		{ return m_rotationCenter; }
	D3DXVECTOR2 getPosition()					{ return m_position; }
	float getRotation()								{ return m_rotation; }
};

#endif