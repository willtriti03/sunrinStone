#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#define InputMgr InputManager::GetInstance()

#include <windows.h>

class InputManager {
private:
	bool rkey[256], lkey[256];

	InputManager();

public:
	~InputManager();

	static InputManager* GetInstance();

	void update();

	int keyState(unsigned int key);
};

#endif