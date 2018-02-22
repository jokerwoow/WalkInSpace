#pragma once
#ifndef __MISSIONSSCENE_H__
#define __MISSIONSSCENE_H__

#include "cocos2d.h"


class MissionsScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(MissionsScene);

private:
	
	
	void backToGameMode(Ref *sender);
	void about(const char *xz,int lvl);
	cocos2d::Menu *LvlMenu;

	cocos2d::MenuItemImage *lvl1;

	cocos2d::MenuItemImage *lvl2;


	cocos2d::MenuItemImage *lvl3;

	cocos2d::MenuItemImage *lvl4;


	cocos2d::MenuItemImage *lvl5;


	cocos2d::MenuItemImage *lvl6;


	cocos2d::MenuItemImage *lvl7;
	void start(int lvl);
	void MissionsSkin();
	cocos2d::Sprite *sprite;
	bool backToMainMenu(cocos2d::Touch *touch, cocos2d::Event *event);
	bool visible = false;
};

#endif // __GAME_SCENE_H__
