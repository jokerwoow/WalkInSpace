#include "Statistic.h"
#include "MainMenuScene.h"
#include "Definitions.h"
#include "GameOverScene.h"
#include "cocos2d.h"
USING_NS_CC;

Scene* Statistic::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Statistic::create();

	// add layer as a child to scene
	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool Statistic::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	


	

	auto easyValue = cocos2d::UserDefault::getInstance()->getIntegerForKey("Easy");
	auto hardValue = cocos2d::UserDefault::getInstance()->getIntegerForKey("Hard");
	auto insaneValue = cocos2d::UserDefault::getInstance()->getIntegerForKey("Insane");
	auto bonusValue = cocos2d::UserDefault::getInstance()->getIntegerForKey("Bonus");

	

	__String *easyHighScore = __String::createWithFormat("%s" "%i","Easy ", easyValue);
	__String *hardHighScore = __String::createWithFormat("%s" "%i","Hard ", hardValue);
	__String *insaneHighScore = __String::createWithFormat("%s" "%i","Insane ", insaneValue);
	__String *maxBonus = __String::createWithFormat("%s" "%i", "Max Bonus ", bonusValue);

	auto EasyScore = LabelTTF::create(easyHighScore->getCString(), "fonts/Marker Felt.ttf", 22);
	EasyScore->setPosition(Point(visibleSize.width/2+origin.x, visibleSize.height / 2  + origin.y));
	this->addChild(EasyScore);


	auto HardScore = LabelTTF::create(hardHighScore->getCString(), "fonts/Marker Felt.ttf", 22);
	HardScore->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.2 + origin.y));
	this->addChild(HardScore);

	auto InsaneScore = LabelTTF::create(insaneHighScore->getCString(), "fonts/Marker Felt.ttf", 22);
	InsaneScore->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.4 + origin.y));
	this->addChild(InsaneScore);

	auto Bonus = LabelTTF::create(maxBonus->getCString(), "fonts/Marker Felt.ttf", 22);
	Bonus->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.6 + origin.y));
	this->addChild(Bonus);

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(false);
	listener1->onTouchBegan = CC_CALLBACK_2(Statistic::backToMainMenu, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);
	//


	

	/*auto Label = LabelTTF::create(npg->getCString(), "fonts/Marker Felt.ttf", 22);
	Label->setPosition(Point(visibleSize.width / 3+ origin.x, visibleSize.height / 2.6 + origin.y));
	this->addChild(Label);*/



	return true;
}
bool Statistic::backToMainMenu(cocos2d::Touch *touch, cocos2d::Event *event) {
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	return true;
}
