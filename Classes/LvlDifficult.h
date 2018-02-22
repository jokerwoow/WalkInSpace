#pragma once
#ifndef __LVLDIFFICULT_H__
#define __LVLDIFFICULT_H__

#include "cocos2d.h"


class LvlDifficult : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(LvlDifficult);
	
private:
	void Easy(Ref *sender);
	void Hard(Ref *sender);
	void Insane(Ref *sender);
	unsigned int sc;
	cocos2d::PhysicsWorld *sceneWorld;
	void backToGameMode(Ref *sender);




};

#endif // __GAME_SCENE_H__
