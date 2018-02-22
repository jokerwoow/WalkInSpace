#ifndef __CHOOSE_HEROES_H__
#define __CHOOSE_HEROES_H__

#include "cocos2d.h"

class ChooseHeroes : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	int easy;
	// implement the "static create()" method manually
	CREATE_FUNC(ChooseHeroes);

private:
	void Name(const char *name,int coin,int numb);
	void about(const char *xz);
	cocos2d::Label *coinLabel;
	int coins;
	void backToMainMenu();
	cocos2d::Menu *menu;
	//cocos2d::MenuItemImage *mag2;
	bool visible=true;
	cocos2d::Sprite *sprite;
	cocos2d::MenuItemImage *hero1;
	cocos2d::MenuItemImage *mag1;
	cocos2d::MenuItemImage *mag2;
	cocos2d::MenuItemImage *mag3;
};

#endif // __MAIN_MENU_SCENE_H__
