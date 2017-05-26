#include "stdafx.h"
#include "SceneManager.h"

SceneManager::SceneManager() : m_pNowScene(NULL) {}
SceneManager::~SceneManager() {}
void SceneManager::changeScene(ISceneNode* p, bool erase) {
	if(erase) delete m_pNowScene;
	m_pNowScene = p;
}
void SceneManager::update(float eTime) {
	if(m_pNowScene) {

		m_pNowScene->update(eTime);
	}
}
void SceneManager::render() {
	if(m_pNowScene) {
		m_pNowScene->render();
	}
}
void SceneManager::releaseScene() {
	if(m_pNowScene) {
		delete m_pNowScene;
	}
}