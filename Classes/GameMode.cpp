#include "GameMode.h"
#include "Definitions.h"
#include "LvlDifficult.h"
#include "MainMenuScene.h"
#include "MissionsScene.h"
#include "ChooseHeroes.h"

USING_NS_CC;

Scene* GameMode::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameMode::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameMode::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("Backgrounds/bg.jpg");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgroundSprite);

	auto LvlDifficult = MenuItemImage::create("but/c1.png", "but/c2.png",CC_CALLBACK_1(GameMode::GoToLvlDifficult, this));
		 LvlDifficult->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y+200));
        LvlDifficult->setScale(0.4);

	auto Missions = MenuItemImage::create("but/m1.png","but/m2.png", CC_CALLBACK_1(GameMode::GoToMissions, this));
		 Missions->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.2 + origin.y));
    Missions->setScale(0.6);

	auto back = MenuItemImage::create("but/b1.png", "but/b2.png",CC_CALLBACK_1(GameMode::backToMainMenu, this));
		 back->setPosition(Point(0+origin.x, 0));
		 back->setAnchorPoint(Vec2(0, 0));
    back->setScale(0.1);
    
	auto Heroes = MenuItemImage::create("but/h1.png", "but/h2.png", CC_CALLBACK_1(GameMode::GoToHeroChoose, this));
		 Heroes->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.4 + origin.y-200));
    Heroes->setScale(0.4);

	auto menu = Menu::create(LvlDifficult, Missions, Heroes,back,NULL);
		 menu->setPosition(Vec2::ZERO);
		 this->addChild(menu);
	





	return true;
}
void GameMode::GoToLvlDifficult(cocos2d::Ref *sender)
{
	auto scene = LvlDifficult::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void GameMode::backToMainMenu(cocos2d::Ref *senre) {
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}

void GameMode::GoToMissions(Ref* sender) {
	auto scene = MissionsScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void GameMode::GoToHeroChoose(Ref* sender) {
	auto scene = ChooseHeroes::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
