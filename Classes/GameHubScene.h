#pragma once
#ifndef __GAMEHUBSCENE_H__
#define __GAMEHUBSCENE_H__

#include "cocos2d.h"

class GameHubScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();


	CREATE_FUNC(GameHubScene);
private:
	bool backToMainMenu(cocos2d::Touch *touch, cocos2d::Event *event);
	
};

#endif // __GAME_SCENE_H__
