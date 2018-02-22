#include "MainMenuScene.h"
#include "Definitions.h"
#include "GameScene.h"
#include "GameMode.h"
#include "Authors.h"
#include "GameHubScene.h"
#include "Statistic.h"

USING_NS_CC;
using namespace cocos2d;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create( "Backgrounds/bg.jpg" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    this->addChild( backgroundSprite );

	

    auto playItem = MenuItemImage::create( "p1.png", "p2.png", CC_CALLBACK_1( MainMenuScene::GoToGameScene, this ) );
    playItem->setPosition( Point( visibleSize.width / 2+origin.x, visibleSize.height / 2+origin.y) );
    playItem->setScale(0.3);


	auto astro = MenuItemImage::create("Backgrounds/Logomakr_4LqnPv.png", " ", CC_CALLBACK_1(MainMenuScene::GoToGameHubScene, this));
	astro->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 280));
	astro->setScale(0.1);



	auto authors = MenuItemImage::create("i2.png", "i1.png", CC_CALLBACK_1(MainMenuScene::GoToAuthors, this));
	authors->setPosition(Point(visibleSize.width+origin.x , 0 ));
	authors->setAnchorPoint(Vec2(1, 0));
	authors->setScale(0.1);
   
    auto statistic = MenuItemImage::create("statistic.png", "statistic1.png", CC_CALLBACK_1(MainMenuScene::GoToStatisticScene, this));
    statistic->setPosition(Point(0+origin.x, 0));
    statistic->setAnchorPoint(Vec2(0, 0));
    statistic->setScale(1);
    statistic->setScale(0.1);

    auto menu = Menu::create( playItem, authors,astro,statistic,NULL );
    menu->setPosition( Point::ZERO );
    this->addChild( menu );
    
    auto name=Sprite::create("Backgrounds/Logomakr_25ibfG.png");
    name->setAnchorPoint(Vec2(1, 1));
    name->setPosition( Point( visibleSize.width/2+origin.x+250, visibleSize.height+origin.y) );
    name->setScale(0.65);
    this->addChild( name );


    return true;
}

void MainMenuScene::GoToGameScene( cocos2d::Ref *sender )
{
    auto scene = GameMode::createScene();
    
    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}
void MainMenuScene::GoToAuthors(cocos2d::Ref *sender)
{
	auto scene = Authors::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenuScene::GoToStatisticScene(cocos2d::Ref *sender)
{
	auto scene = Statistic::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


void MainMenuScene::GoToGameHubScene(cocos2d::Ref *sender) {
	count++;
	if (count == 6) {
		auto scene = GameHubScene::createScene();

		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

	}
}

