#include "MissionsScene.h"
#include "Definitions.h"
#include "GameScene.h"
#include "GameMode.h"
#include "cocos2d.h"

USING_NS_CC;

Scene* MissionsScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MissionsScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MissionsScene::init()
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

	
	auto back = MenuItemFont::create("Back", CC_CALLBACK_1(MissionsScene::backToGameMode, this));
		 back->setPosition(Point(0+origin.x, 0+origin.y));
		 back->setAnchorPoint(Vec2(0, 0));
	auto menu = Menu::create(back, NULL);
		 menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	
	//lvl 1
	//******************************************************************
		 lvl1 = MenuItemImage::create(/*"MissionsBox.png", "MissionsBox.png", " ",CC_CALLBACK_0(MissionsScene::lvl1f,this,3)*/);
		 //cocos2d::UserDefault::getInstance()->getIntegerForKey("Bonus");
	
		 lvl1->setNormalImage(Sprite::create("MissionsBox.png"));

		 lvl1->setCallback(CC_CALLBACK_0(MissionsScene::about, this, "Earn 20 points", 3));
		 lvl1->setPosition(Point(visibleSize.width / FIRST_COLUMN + origin.x, visibleSize.height / FIRST_ROW));
		 lvl1->setScale(0.3);

	auto Label1 = Label::createWithTTF("1", "fonts/Marker Felt.ttf", visibleSize.height*SCORE_FONT_SIZE);
		 Label1->setPosition(Point(visibleSize.width / FIRST_COLUMN + origin.x, visibleSize.height / FIRST_ROW));
		 Label1->setAnchorPoint(Vec2(0.5, 0.5));
		 Label1->setColor(Color3B::BLACK);
		 this->addChild(Label1,1);
	//******************************************************************
	//lvl 2
		 lvl2 = MenuItemImage::create();

		 lvl2->setNormalImage(Sprite::create("MissionsBox.png"));

		 lvl2->setCallback(CC_CALLBACK_0(MissionsScene::about, this,"Get bonus 10x", 4));
		 lvl2->setPosition(Point(visibleSize.width / SECOND_COLUMN + origin.x, visibleSize.height / FIRST_ROW));
		 lvl2->setScale(0.3);

	auto Label2 = Label::createWithTTF("2", "fonts/Marker Felt.ttf", visibleSize.height*SCORE_FONT_SIZE);
		 Label2->setPosition(Point(visibleSize.width / SECOND_COLUMN + origin.x, visibleSize.height / FIRST_ROW));
		 Label2->setAnchorPoint(Vec2(0.5, 0.5));
		 Label2->setColor(Color3B::BLACK);
		 this->addChild(Label2, 1);
	//******************************************************************
	//lvl 3
		 lvl3 = MenuItemImage::create();

		 lvl3->setNormalImage(Sprite::create("MissionsBox.png"));

		 lvl3->setCallback(CC_CALLBACK_0(MissionsScene::about, this,"Lost 10 points", 5));
		 lvl3->setPosition(Point(visibleSize.width / THIRD_COLUMN + origin.x, visibleSize.height / FIRST_ROW));
		 lvl3->setScale(0.3);

		 auto Label3 = Label::createWithTTF("3", "fonts/Marker Felt.ttf", visibleSize.height*SCORE_FONT_SIZE);
		 Label3->setPosition(Point(visibleSize.width / THIRD_COLUMN + origin.x, visibleSize.height / FIRST_ROW));
		 Label3->setAnchorPoint(Vec2(0.5, 0.5));
		 Label3->setColor(Color3B::BLACK);
		 this->addChild(Label3, 1);
	//******************************************************************

	//lvl 4
		 lvl4 = MenuItemImage::create();
	
		 lvl4->setNormalImage(Sprite::create("MissionsBox.png"));

		 lvl4->setCallback(CC_CALLBACK_0(MissionsScene::about, this,"Don`t die 30sec", 6));
		 lvl4->setPosition(Point(visibleSize.width / FIRST_COLUMN + origin.x, visibleSize.height / SECOND_ROW + origin.y));
		 lvl4->setScale(0.3);

		 auto Label4 = Label::createWithTTF("4", "fonts/Marker Felt.ttf", visibleSize.height*SCORE_FONT_SIZE);
		 Label4->setPosition(Point(visibleSize.width / FIRST_COLUMN + origin.x, visibleSize.height / SECOND_ROW + origin.y));
		 Label4->setAnchorPoint(Vec2(0.5, 0.5));
		 Label4->setColor(Color3B::BLACK);
		 this->addChild(Label4, 1);
	//******************************************************************

	//lvl 5
		 lvl5 = MenuItemImage::create();
	
		 lvl5->setNormalImage(Sprite::create("MissionsBox.png"));

		 lvl5->setCallback(CC_CALLBACK_0(MissionsScene::about, this,"Earn 50 points", 7));
		 lvl5->setPosition(Point(visibleSize.width / SECOND_COLUMN + origin.x, visibleSize.height / SECOND_ROW + origin.y));
		 lvl5->setScale(0.3);

		 auto Label5 = Label::createWithTTF("5", "fonts/Marker Felt.ttf", visibleSize.height*SCORE_FONT_SIZE);
		 Label5->setPosition(Point(visibleSize.width / SECOND_COLUMN + origin.x, visibleSize.height / SECOND_ROW + origin.y));
		 Label5->setAnchorPoint(Vec2(0.5, 0.5));
		 Label5->setColor(Color3B::BLACK);
		 this->addChild(Label5, 1);
	//******************************************************************

	//lvl 6
		 lvl6 = MenuItemImage::create();
		
		 lvl6->setNormalImage(Sprite::create("MissionsBox.png"));

		 lvl6->setCallback(CC_CALLBACK_0(MissionsScene::about, this,"Earn 60 points", 8));
		 lvl6->setPosition(Point(visibleSize.width / THIRD_COLUMN + origin.x, visibleSize.height / SECOND_ROW + origin.y));
		 lvl6->setScale(0.3);

		 auto Label6 = Label::createWithTTF("6", "fonts/Marker Felt.ttf", visibleSize.height*SCORE_FONT_SIZE);
		 Label6->setPosition(Point(visibleSize.width / THIRD_COLUMN + origin.x, visibleSize.height / SECOND_ROW + origin.y));
		 Label6->setAnchorPoint(Vec2(0.5, 0.5));
		 Label6->setColor(Color3B::BLACK);
		 this->addChild(Label6, 1);
	//******************************************************************
	//lvl 7
		 lvl7 = MenuItemImage::create();
	
		 lvl7->setNormalImage(Sprite::create("MissionsBox.png"));

		 lvl7->setCallback(CC_CALLBACK_0(MissionsScene::about, this,"Earn 10 coins", 9));
		 lvl7->setPosition(Point(visibleSize.width / FIRST_COLUMN + origin.x, visibleSize.height / 3 + origin.y));
		 lvl7->setScale(0.3);

		 auto Label7 = Label::createWithTTF("7", "fonts/Marker Felt.ttf", visibleSize.height*SCORE_FONT_SIZE);
		 Label7->setPosition(Point(visibleSize.width / FIRST_COLUMN + origin.x, visibleSize.height / 3 + origin.y));
		 Label7->setAnchorPoint(Vec2(0.5, 0.5));
		 Label7->setColor(Color3B::BLACK);
		 this->addChild(Label7, 1);
	//******************************************************************

	LvlMenu = Menu::create(lvl1,lvl2,lvl3,lvl4,lvl5,lvl6,lvl7, NULL);
	LvlMenu->setPosition(Vec2::ZERO);
	this->addChild(LvlMenu);
	

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(false);
	listener1->onTouchBegan = CC_CALLBACK_2(MissionsScene::backToMainMenu, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);
	MissionsSkin();
	return true;
}


void MissionsScene::backToGameMode(cocos2d::Ref *senre) {
	auto scene = GameMode::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}


void MissionsScene::about(const char *xz,int lvl) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

		 sprite = Sprite::create("MissionsBox.png");
		 sprite->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
	
	auto Label = LabelTTF::create(xz, "fonts/Marker Felt.ttf", 22);
		 Label->setPosition(sprite->getContentSize().width / 2 + origin.x, sprite->getContentSize().height / 2 + origin.y);
		 Label->setColor(Color3B::BLACK);
	sprite->addChild(Label);

	auto startButton = MenuItemImage::create("p1.png","p2.png", CC_CALLBACK_0(MissionsScene::start,this,lvl));
		 startButton->setPosition(Point(sprite->getContentSize().width / 2 + origin.x, sprite->getContentSize().height*0 + origin.y));
		 startButton->setScale(0.09);
		 startButton->setAnchorPoint(Vec2(0.5, 0));

	auto menuButton = Menu::create(startButton, NULL);
		 menuButton->setPosition(Vec2::ZERO);
		 LvlMenu->setEnabled(false);
		 visible = true;
	sprite->addChild(menuButton);
	this->addChild(sprite,10000);
	
}
void MissionsScene::start(int lvl) {
	auto scene = GameScene::createScene(lvl);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	
}
bool MissionsScene::backToMainMenu(cocos2d::Touch *touch, cocos2d::Event *event) {
	
	if (visible ==true) {
		sprite->setVisible(false);
		LvlMenu->setEnabled(true);
	}
	return true;
}
void MissionsScene::MissionsSkin() {

	MenuItemImage *a[] = {lvl1,lvl2,lvl3,lvl4,lvl5,lvl6,lvl7};

	for (int i = 1; i <= (sizeof(a)/sizeof(*a)); i++) {

		__String *Mission = __String::createWithFormat("%c""%c""%c" "%i", 'l', 'v', 'l', i);

		const char *xz = Mission->getCString();
		
		if (cocos2d::UserDefault::getInstance()->getBoolForKey(xz) == true) {
			a[i-1]->setNormalImage(Sprite::create("MissionsBoxOk.png"));
		}
	}
}
