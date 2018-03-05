#include "PauseScene.h"
#include "Definitions.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

Scene* PauseScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PauseScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PauseScene::init()
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

	//menu retry and go main
	//*************************
	//back to game 
    auto resume = MenuItemImage::create("res2.png", "res1.png", CC_CALLBACK_1(PauseScene::Resume, this));
	resume->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 200));
	resume->setScale(0.5);

	//calling yes or no question
	auto BackToMenu = MenuItemImage::create("M1.png", "M2.png", CC_CALLBACK_0(PauseScene::GoToMenu, this));
    
	BackToMenu->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 3 + origin.y + 200));
    BackToMenu->setAnchorPoint(Vec2(0.5,1));
    BackToMenu->setScale(0.3);

	//music on-off
	MusicBool = cocos2d::UserDefault::getInstance()->getBoolForKey("music", true);
	musicion = MenuItemImage::create();
	//musicion->initWithNormalImage("MusicOn.png");
	
    musicion->setScale(0.1);

	musicion->setCallback(CC_CALLBACK_0(PauseScene::Music, this));
	musicion->setPosition(Point(0+origin.x, visibleSize.height + origin.y));
	musicion->setAnchorPoint(Vec2(0, 1));


	//creating menu
	menu = Menu::create(resume, BackToMenu,musicion, NULL);
	menu->setPosition(Point::ZERO);
	//*************************

	
	
	//Yes-No menu
	//*************************
	//create background sprite for "yes-no" menu
	back = Sprite::create("Backgrounds/bg.jpg");
    back->setAnchorPoint(Vec2(0.5, 0.5));
    back->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    back->setVisible(false);
    this->addChild(back,2);

	//question label
	auto question = Sprite::create("GoToMenu.png");
	question->setPosition(Point(visibleSize.width + origin.x+175, visibleSize.height + origin.y+200));
    question->setAnchorPoint(Vec2(1, 1));
    question->setScale(0.8);
	back->addChild(question);

	//calling yes function
	auto yes = MenuItemImage::create("yes.png","yes1.png",CC_CALLBACK_1(PauseScene::Yes,this));
	yes->setPosition(Point(visibleSize.width + origin.x-150, visibleSize.height  + origin.y-300));
    yes->setAnchorPoint(Vec2(1, 1));
	
	//calling no function
	auto no = MenuItemImage::create("NO.png","NO1.png", CC_CALLBACK_1(PauseScene::No,this));
	no->setPosition(Point(visibleSize.width+100  + origin.x, visibleSize.height  + origin.y-290));
    no->setAnchorPoint(Vec2(1, 1));

	//creating menu
	backMenu = Menu::create(yes, no, NULL);
	backMenu->setPosition(Point::ZERO);
	backMenu->setEnabled(false);
	back->addChild(backMenu);
	//*************************

	this->addChild(menu);
	
	mamba();
	return true;
}

void PauseScene::Resume(cocos2d::Ref *sender) {
	Director::getInstance()->popScene();
}

void PauseScene::GoToMenu() {
	back->setVisible(true);
	backMenu->setEnabled(true);
	menu->setEnabled(false);
}
void PauseScene::Yes(cocos2d::Ref *sender) {
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene( scene);
}
void PauseScene::No(cocos2d::Ref *sender) {
	back->setVisible(false);
	backMenu->setEnabled(false);
	menu->setEnabled(true);
}
void PauseScene::Music() {
	MusicBool = !MusicBool;

	if (MusicBool ==true) {
		cocos2d::UserDefault::getInstance()->setBoolForKey("music", true);
		CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(1);
		musicion->setNormalImage(Sprite::create("but/o1.png"));
	}
	else {
		cocos2d::UserDefault::getInstance()->setBoolForKey("music", false);
		CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0);
		musicion->setNormalImage(Sprite::create("but/f1.png"));
	}
}

void PauseScene::mamba() {
	if (MusicBool == true) {
		CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(1);
		musicion->setNormalImage(Sprite::create("but/o1.png"));
	}
	else {
		musicion->setNormalImage(Sprite::create("but/f1.png"));
		CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0);
	}
}