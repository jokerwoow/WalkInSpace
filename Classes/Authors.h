#pragma once
#ifndef __AUTHORS_H__
#define __AUTHORS_H__

#include "cocos2d.h"
class Authors : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Authors);
private:
	bool backToMainMenu(cocos2d::Touch *touch, cocos2d::Event *event);
};

#endif // __GAME_SCENE_H__
