#pragma once
#ifndef __PAUSESCENE_H__
#define __PAUSESCENE_H__

#include "cocos2d.h"


class PauseScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(PauseScene);

private:
	void Resume(Ref *sender);
	void GoToMenu();
	cocos2d::Sprite *back;
	void Yes(Ref *sender);
	void No(Ref *sender);
	cocos2d::Menu *backMenu;
	cocos2d::Menu *menu;
	cocos2d::MenuItemImage *musicion;
	void Music();
	bool MusicBool = true;
};

#endif // __GAME_SCENE_H__
