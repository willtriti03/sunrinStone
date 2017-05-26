#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "ISceneNode.h"
#include "Sprite.h"
#include <string>
class BackGround:public ISceneNode {
private:
	Sprite* backGroundImg;

public:
	BackGround();
	~BackGround();
	void BackGroundRsc(std::string path);

	void update(float eTime);
	void render();
};
#endif