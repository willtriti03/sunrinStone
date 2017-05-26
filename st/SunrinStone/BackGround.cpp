#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround(){
	
	backGroundImg = nullptr;
}
BackGround:: ~BackGround(){

}
void BackGround::BackGroundRsc(std::string path){

	backGroundImg = new Sprite();
	backGroundImg->Create(path);
	pushScene(backGroundImg, false);
	
}
void BackGround::update(float eTime){
	ISceneNode::update(eTime);
	backGroundImg->update(eTime);

}
void BackGround::render(){
	ISceneNode::render();
	backGroundImg->render();
}
