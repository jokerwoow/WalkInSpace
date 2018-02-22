#include "GameHubScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* GameHubScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameHubScene::create();

	// add layer as a child to scene
	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool GameHubScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto white = Sprite::create("white.jpg");
	white->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	white->setScale(2);
	this->addChild(white,-1);

	auto bg = Sprite::create("gamehub.png");
	bg->setScale(0.5);
	auto ScaleBy=ScaleBy::create(2,2.5);
	bg->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	bg->runAction(ScaleBy);
	this->addChild(bg);
	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(false);
	listener1->onTouchBegan = CC_CALLBACK_2(GameHubScene::backToMainMenu, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);

	
	
	return true;
}
bool GameHubScene::backToMainMenu(cocos2d::Touch *touch, cocos2d::Event *event) {
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	return true;
}
