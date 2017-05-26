#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "Sprite.h"
#include <string>

class Animation : public ISceneNode {
private:
	Sprite** m_Frame;
	float m_fNowFrame;
	float m_fFrameSpeed;
	int m_MaxFrame;
	bool m_start;
	bool m_loop;

public:
	Animation();
	~Animation();

	void Create(int MaxFrame, float speed, bool loop = true);

	void update(float eTime);
	void render();

public:
	void PushFrame(std::string, int index);
	void GenerateAnimation(std::string path);

	void Start() { m_start = true; }
	void Stop() { m_start = false; }

	float GetFrameSpeed() { return m_fFrameSpeed; }
	float GetFrame() { return (int)m_fNowFrame; }
	Sprite* GetNowFrameSprite() { return m_Frame[(int)m_fNowFrame]; }
	D3DXVECTOR2 GetCenterPosition() { return m_Frame[(int)m_fNowFrame]->GetCenterPosition(); }
	int GetMaxFrame() { return m_MaxFrame; }

	void SetFrameSpeed(float speed) { m_fFrameSpeed = speed; }
	void SetFrame(float frame) { m_fNowFrame = frame; }
};

#endif