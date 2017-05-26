#ifndef _LOADSCENE_H_
#define _LOADSCENE_H_

#include "ISceneNode.h"
#include "Sprite.h"
#include <string>

class LoadScene : public ISceneNode{
private:
	Sprite* loadImg[2];
public:
	LoadScene();
	~LoadScene();
	void LoadAnimation(std::string path_R,  std::string path_L);
	void update(float eTime);
	void render();


};
#endif