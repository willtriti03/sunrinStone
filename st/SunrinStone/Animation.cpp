#include "stdafx.h"
#include <cstring>
#include <stdio.h>
#include <io.h>
#include "Application.h"
#include "Animation.h"

Animation::Animation() :
m_fNowFrame(0.f), m_fFrameSpeed(0.f), m_MaxFrame(0), m_start(true), m_loop(true)
{
}
Animation::~Animation() {
	for(int i = 0;i < m_MaxFrame; ++i) {
		popScene(m_Frame[i]);
		if(m_Frame[i]!=NULL) delete m_Frame[i];
	}
}
void Animation::Create(int MaxFrame, float speed, bool loop) {
	m_MaxFrame = MaxFrame;
	m_fFrameSpeed = speed;
	m_loop = loop;
	m_Frame = (Sprite**)calloc(m_MaxFrame, sizeof(Sprite*));
}
void Animation::update(float eTime) {
	ISceneNode::update(eTime);
	if(m_start && m_loop) {
		m_fNowFrame += m_fFrameSpeed * eTime;
		if(m_fNowFrame >= m_MaxFrame)
			m_fNowFrame = 0;
	}
}
void Animation::render() {
	ISceneNode::render();
	m_Frame[(int)m_fNowFrame]->render();
}
void Animation::PushFrame(std::string path, int index) {
	if(m_Frame[index] != NULL)
		delete m_Frame[index];
	m_Frame[index] = new Sprite();
	m_Frame[index]->Create(path);
	pushScene(m_Frame[index], false);
}
void Animation::GenerateAnimation(std::string path) {
	_finddata_t search_file;
	char search_path[100];
	char* fullpath;
	long file_HANDLE;
	int prior = 0;

	sprintf_s(search_path, "%s/*.*", path.c_str());
	if((file_HANDLE = _findfirst(search_path, &search_file)) == -1L) {
		MessageBox(NULL, L"������ �������� ����", GameApp->GetAppName(), MB_OK);
	} else {
		do {
			if(strcmp(search_file.name, ".") == 0 || strcmp(search_file.name, "..") == 0) {
				continue;
			} else {
				fullpath = new char[strlen(search_path) + strlen(search_file.name)];
				sprintf_s(search_path, "%s/%s", path.c_str(), search_file.name);
				strcpy(fullpath, search_path);
				PushFrame(fullpath, prior);
				prior++;
			}
		} while(_findnext(file_HANDLE, &search_file) == 0);
		_findclose(file_HANDLE);
	}
}