#include "GameOverScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"
#include "Statistic.h"
USING_NS_CC;
using namespace std;
unsigned int score;
unsigned int repl;
unsigned int bonus;
Scene* GameOverScene::createScene( unsigned int tempScore,unsigned int replace,unsigned int Bonus)
{
    score = tempScore;
	repl = replace;
	bonus = Bonus;
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
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
    
    auto retryItem = MenuItemImage::create( "r1.png", "r2.png", CC_CALLBACK_1( GameOverScene::GoToGameScene, this ) );
    retryItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 4 * 3 ) );
    retryItem->setScale(0.2);
    
    auto mainMenuItem = MenuItemImage::create( "M1.png", "M2.png", CC_CALLBACK_1( GameOverScene::GoToMainMenuScene, this ) );
    mainMenuItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 4 ) );
    mainMenuItem->setScale(0.3);

    
    auto menu = Menu::create( retryItem, mainMenuItem, NULL );
    menu->setPosition( Point::ZERO );
    
    this->addChild( menu );
    
	
	
	
	//__String *name;
	if (repl >= 0 && repl <= 2) {
		if (repl == 0) {
			Lvl = LabelTTF::create("Easy", "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);
			name = "Easy";
		}
		else if (repl == 1) {
			Lvl = LabelTTF::create("Hard", "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);
			name = "Hard";
		}
		else {
			Lvl = LabelTTF::create("Insane", "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);
			name = "Insane";
		}
		Lvl->setPosition(Point(visibleSize.width * 0.75 + origin.x, (visibleSize.height / 2)*1.2 + origin.y));
		Lvl->setColor(Color3B::YELLOW);
		this->addChild(Lvl);



		UserDefault *def = UserDefault::getInstance();

		auto highScore = def->getIntegerForKey(name, 0);
		auto maxBonus = def->getIntegerForKey("Bonus", 0);
		if (bonus > maxBonus) {
			maxBonus = bonus;
			def->setIntegerForKey("Bonus", maxBonus);
		}
		if (score > highScore)
		{
			highScore = score;

			def->setIntegerForKey(name, highScore);

		}
		def->flush();

		__String *tempScore = __String::createWithFormat("%i", score);

		auto currentScore = LabelTTF::create(tempScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);
		currentScore->setPosition(Point(visibleSize.width * 0.25 + origin.x, visibleSize.height / 2 + origin.y));

		this->addChild(currentScore);

		__String *tempHighScore = __String::createWithFormat("%i", highScore);

		auto highScoreLabel = LabelTTF::create(tempHighScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);

		highScoreLabel->setColor(Color3B::YELLOW);
		highScoreLabel->setPosition(Point(visibleSize.width * 0.75 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(highScoreLabel);
	}
    return true;
}

void GameOverScene::GoToMainMenuScene( cocos2d::Ref *sender )
{
    auto scene = MainMenuScene::createScene( );
    
    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}

void GameOverScene::GoToGameScene( cocos2d::Ref *sender )
{
    auto scene = GameScene::createScene(repl);
    
    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}







