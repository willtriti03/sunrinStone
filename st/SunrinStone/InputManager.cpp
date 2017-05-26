#include "stdafx.h"
#include "InputManager.h"
#include "GUIButton.h"

InputManager::InputManager() {
	for (int i = 0; i < 256; ++i) {
		rkey[i] = lkey[i] = false;
	}

}

InputManager::~InputManager() {}

void InputManager::update() {
	for (int i = 0; i < 256; ++i) {
		rkey[i] = lkey[i];
		lkey[i] = GetKeyState(i) & 0x8000;
	}
}

int InputManager::keyState(unsigned int key) {
	if (rkey[key] == true && lkey[key] == false) {

		return 2;
	}
	else if (rkey[key] == true && lkey[key] == true){
		return 3;
	}

}

InputManager* InputManager::GetInstance() {
	static InputManager Instance;
	return &Instance;
}