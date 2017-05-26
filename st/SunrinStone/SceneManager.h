#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include "ISceneNode.h"

#define SceneMgr SceneManager::getInstance()

class SceneManager {
	ISceneNode* m_pNowScene; //���� GameScene�� ������

private:
	SceneManager();

public:
	virtual ~SceneManager();

	static SceneManager* getInstance() {
		static SceneManager Instance;
		return &Instance;
	}

	void changeScene(ISceneNode* p, bool erase = true);
	void update(float eTime);
	void render();
	void releaseScene();
};

#endif