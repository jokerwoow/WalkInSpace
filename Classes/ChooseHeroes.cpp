#include "ChooseHeroes.h"
#include "Definitions.h"
#include "GameScene.h"
#include "GameMode.h"
#include "Authors.h"
#include "GameHubScene.h"
#include "Statistic.h"

USING_NS_CC;
using namespace cocos2d;

Scene* ChooseHeroes::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = ChooseHeroes::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool ChooseHeroes::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto coinSprite = Sprite::create("Coin.png");
	coinSprite->setAnchorPoint(Vec2(0, 1));
	coinSprite->setPosition(Point(0 + Sprite::create("Pipe&Ball/Ball.png")->getContentSize().width + origin.x, visibleSize.height - Sprite::create("Pipe&Ball/Ball.png")->getContentSize().height + origin.y));
	coinSprite->setScale(0.07);
	this->addChild(coinSprite);

	coins = cocos2d::UserDefault::getInstance()->getIntegerForKey("Coins", 0);

	__String *coinScore = __String::createWithFormat("%i", coins);
	coinLabel = Label::createWithTTF(coinScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);
	coinLabel->setColor(Color3B::WHITE);
	coinLabel->setAnchorPoint(Vec2(0, 1));
	coinLabel->setPosition(Point(0 + Sprite::create("Pipe&Ball/Ball.png")->getContentSize().width*4.5 + origin.x, visibleSize.height - Sprite::create("Pipe&Ball/Ball.png")->getContentSize().height*1.2 + origin.y));
	coinLabel->setScale(0.3);
	coinLabel->setString(coinScore->getCString());
	this->addChild(coinLabel, 1);

	hero1 = MenuItemImage::create("MissionsBox.png", "MissionsBox.png", " ",CC_CALLBACK_0(ChooseHeroes::Name,this,"hero1",0,0));
		 hero1->setPosition(Point(visibleSize.width / FIRST_COLUMN + origin.x, visibleSize.height / FIRST_ROW));
		

		 hero1->setScale(0.3);

	auto hero1Sprite = Sprite::create("hero/hero1.png");
		 hero1Sprite->setPosition(Point(visibleSize.width / FIRST_COLUMN + origin.x, visibleSize.height / FIRST_ROW));
	this->addChild(hero1Sprite,1);

	mag1 = MenuItemImage::create("MissionsBox.png", "MissionsBox.png", " ", CC_CALLBACK_0(ChooseHeroes::Name, this, "mag1",10,1));
		 mag1->setPosition(Point(visibleSize.width / SECOND_COLUMN + origin.x, visibleSize.height / FIRST_ROW));
		 mag1->setScale(0.3);

	//auto darkmag1 = Sprite::create("DarkMissionsBox.png");
	//	darkmag1->setPosition(Point(visibleSize.width / SECOND_COLUMN + origin.x, visibleSize.height / FIRST_ROW));
	//	darkmag1->setScale(0.3);
	//	darkmag1->setOpacityModifyRGB(true);
	//	this->addChild(darkmag1,2);
	auto mag1Sprite = Sprite::create("hero/mag1.png");
		 mag1Sprite->setPosition(Point(visibleSize.width / SECOND_COLUMN + origin.x, visibleSize.height / FIRST_ROW));
	this->addChild(mag1Sprite, 1);


	mag2 = MenuItemImage::create("MissionsBox.png", "MissionsBox.png", " ", CC_CALLBACK_0(ChooseHeroes::Name, this, "mag2",20,2));
		 mag2->setPosition(Point(visibleSize.width / THIRD_COLUMN + origin.x, visibleSize.height / FIRST_ROW));
		 mag2->setScale(0.3);

	auto mag2Sprite = Sprite::create("hero/mag2.png");
		 mag2Sprite->setPosition(Point(visibleSize.width / THIRD_COLUMN + origin.x, visibleSize.height / FIRST_ROW+origin.y));
	this->addChild(mag2Sprite, 1);
	auto mag2Price = Sprite::create("Coin.png");
	mag2Price->setScale(0.05);
	mag2Price->setPosition(Point(visibleSize.width / THIRD_COLUMN  + origin.x, visibleSize.height / FIRST_ROW *1.065 + origin.y));
	auto Mag2Coin= Label::createWithTTF("20", "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);
	Mag2Coin->setScale(0.2);
	Mag2Coin->setColor(Color3B::BLACK);
	Mag2Coin->setPosition(Point(visibleSize.width / THIRD_COLUMN + origin.x, visibleSize.height / FIRST_ROW * 1.065 + origin.y));
	if (cocos2d::UserDefault::getInstance()->getBoolForKey("mag2") == false) {
		Mag2Coin->setVisible(true);
		mag2Price->setVisible(true);
	}
	else {
		Mag2Coin->setVisible(false);
		mag2Price->setVisible(false);
	}
	this->addChild(Mag2Coin, 1);
	this->addChild(mag2Price, 1);

	mag3 = MenuItemImage::create("MissionsBox.png", "MissionsBox.png", " ", CC_CALLBACK_0(ChooseHeroes::Name, this, "mag3",50,3));
		 mag3->setPosition(Point(visibleSize.width / FIRST_COLUMN + origin.x, visibleSize.height / SECOND_ROW+origin.y));
		 mag3->setScale(0.3);
	auto mag3Sprite = Sprite::create("hero/mag3.png");
		 mag3Sprite->setPosition(Point(visibleSize.width / FIRST_COLUMN + origin.x, visibleSize.height / SECOND_ROW));

	auto mag3Price = Sprite::create("Coin.png");
		 mag3Price->setScale(0.05);
		 mag3Price->setPosition(Point(visibleSize.width / FIRST_COLUMN /1.2 +origin.x, visibleSize.height / SECOND_ROW *1.065+ origin.y));
	auto coinLabell = Label::createWithTTF("50", "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);
		coinLabell->setScale(0.2);
		coinLabell->setColor(Color3B::BLACK);
		coinLabell->setPosition(Point(visibleSize.width / FIRST_COLUMN  + origin.x, visibleSize.height / SECOND_ROW * 1.065 + origin.y));
		if (cocos2d::UserDefault::getInstance()->getBoolForKey("mag3") == false) {
			coinLabell->setVisible(true);
			mag3Price->setVisible(true);
		}
		else {
			coinLabell->setVisible(false);
			mag3Price->setVisible(false);
		}
	this->addChild(coinLabell,1);
	this->addChild(mag3Price, 1);

	this->addChild(mag3Sprite, 1);


	auto menu = Menu::create(hero1,mag1,mag2,mag3, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	MenuItemImage *items[] = { hero1,mag1,mag2,mag3 };
	items[cocos2d::UserDefault::getInstance()->getIntegerForKey("CurrentHero")]->setNormalImage(Sprite::create("DarkMissionsBox.png"));
	return true;
}

void ChooseHeroes::Name(const char *name,int coin,int numb)
{
	
	__String *named = __String::createWithFormat("%s", name);
	if (cocos2d::UserDefault::getInstance()->getBoolForKey(name) == true) {
		cocos2d::UserDefault::getInstance()->setStringForKey("hero", named->getCString());
		cocos2d::UserDefault::getInstance()->setIntegerForKey("CurrentHero", numb);

		auto scene = GameMode::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	

	}
	//
	else if (coins>=coin && cocos2d::UserDefault::getInstance()->getBoolForKey(name)==false) {
		coins = coins - coin;
		cocos2d::UserDefault::getInstance()->setIntegerForKey("Coins", coins);
		cocos2d::UserDefault::getInstance()->setStringForKey("hero", named->getCString());
		cocos2d::UserDefault::getInstance()->setBoolForKey(name, true);
		cocos2d::UserDefault::getInstance()->setIntegerForKey("CurrentHero", numb);

		__String *coinScore = __String::createWithFormat("%i", coins);
		coinLabel->setString(coinScore->getCString());
		auto scene = GameMode::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
	//
	else {
		about("Faaaaaaaaaaaaaaaarm");
	}
	
}
void ChooseHeroes::about(const char *xz) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	sprite = Sprite::create("MissionsBox.png");
	sprite->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
	sprite->setScale(1);
	auto Label = LabelTTF::create(xz, "fonts/Marker Felt.ttf", 22);
	Label->setPosition(sprite->getContentSize().width / 2 + origin.x, sprite->getContentSize().height / 2 + origin.y);
	Label->setColor(Color3B::BLACK);
	sprite->addChild(Label);

	auto startButton = MenuItemImage::create("p1.png", "p2.png", CC_CALLBACK_0(ChooseHeroes::backToMainMenu, this));
	startButton->setPosition(Point(sprite->getContentSize().width / 2 + origin.x, sprite->getContentSize().height * 0 + origin.y));
	startButton->setScale(0.09);
	startButton->setAnchorPoint(Vec2(0.5, 0));

	auto menuButton = Menu::create(startButton, NULL);
	menuButton->setPosition(Vec2::ZERO);
	//menu->setEnabled(false);
	//visible = true;
	sprite->addChild(menuButton);
	this->addChild(sprite, 10000);

}
void ChooseHeroes::backToMainMenu() {
	sprite->setVisible(false);	
}
