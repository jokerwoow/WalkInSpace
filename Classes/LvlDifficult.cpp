#include "LvlDifficult.h"
#include "Definitions.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "GameMode.h"
USING_NS_CC;

Scene* LvlDifficult::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LvlDifficult::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LvlDifficult::init()
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

	auto easy = MenuItemImage::create("Buttons/E1.png","Buttons/E2.png", CC_CALLBACK_1(LvlDifficult::Easy, this));
		 easy->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 200));
		 easy->setScale(0.3);

	auto hard = MenuItemImage::create("Buttons/H1.png","Buttons/H2.png", CC_CALLBACK_1(LvlDifficult::Hard, this));
		 hard->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.2 + origin.y));
		 hard->setScale(0.3);

	auto insane = MenuItemImage::create("Buttons/I1.png","Buttons/I2.png", CC_CALLBACK_1(LvlDifficult::Insane, this));
		 insane->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.4 + origin.y - 200));
		 insane->setScale(0.3);

	auto back = MenuItemFont::create("Back", CC_CALLBACK_1(LvlDifficult::backToGameMode, this));
		 back->setPosition(Point(0+origin.x, 0+origin.y));
		 back->setAnchorPoint(Vec2(0, 0));
	
	auto menu = Menu::create(easy, hard, insane,back,  NULL);
		 menu->setPosition(Point::ZERO);



	this->addChild(menu);
	


	return true;
}

void LvlDifficult::Easy(cocos2d::Ref *sender) {
	sc = 0;
	auto scene = GameScene::createScene(sc);
	Director::getInstance()->replaceScene(scene);
}
void LvlDifficult::Hard(cocos2d::Ref *sender) {
	sc = 1;
	auto scene = GameScene::createScene(sc );
	Director::getInstance()->replaceScene(scene);
}
void LvlDifficult::Insane(cocos2d::Ref *sender) {
	sc = 2;
	auto scene = GameScene::createScene(sc);
	Director::getInstance()->replaceScene(scene);
}
void LvlDifficult::backToGameMode(cocos2d::Ref *senre) {
	auto scene = GameMode::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}



