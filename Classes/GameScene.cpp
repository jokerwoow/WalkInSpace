#include "GameScene.h"
#include "Definitions.h"
#include "GameOverScene.h"
#include "SimpleAudioEngine.h"
#include "PauseScene.h"
#include "MissionsScene.h"
USING_NS_CC;
unsigned int newLvl;

Scene* GameScene::createScene(unsigned int lvl)
{
	newLvl = lvl;
	//scores = lvl;
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics( );
    //scene->getPhysicsWorld( )->setDebugDrawMask( PhysicsWorld::DEBUGDRAW_ALL );
    scene->getPhysicsWorld( )->setGravity( Vec2( 0, 0 ) );
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    layer->SetPhysicsWorld( scene->getPhysicsWorld( ) );

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
  

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Music/Flappy.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Music/coin.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Music/dead.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Music/LostPoint.wav");

    auto backgroundSprite = Sprite::create( "Backgrounds/bg.jpg" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2+origin.x , visibleSize.height / 2 +origin.y ) );
    this->addChild( backgroundSprite );


    // World physics body
	//***********************************
    auto edgeBody = PhysicsBody::createEdgeBox( visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3 );
    edgeBody->setCollisionBitmask( OBSTACLE_COLLISION_BITMASK );
    edgeBody->setContactTestBitmask( true );
    
    auto edgeNode = Node::create();
    edgeNode->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    edgeNode->setPhysicsBody( edgeBody );
    
    this->addChild( edgeNode );
	//***********************************
	//Score label
	//***********************************
	score = 0;
	__String *tempScore = __String::createWithFormat("%i", score);
	scoreLabel = Label::createWithTTF(tempScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);
	scoreLabel->setColor(Color3B::WHITE);
	scoreLabel->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height * 0.75 + origin.y));
	this->addChild(scoreLabel);
	//***********************************

	//Coins label
	//***********************************
	auto coinSprite = Sprite::create("Coin.png");
	coinSprite->setAnchorPoint(Vec2(0, 1));
	coinSprite->setPosition(Point(0+ Sprite::create("Pipe&Ball/Ball.png")->getContentSize().width+origin.x, visibleSize.height- Sprite::create("Pipe&Ball/Ball.png")->getContentSize().height+origin.y));
	coinSprite->setScale(0.07);
	this->addChild(coinSprite);

	coins=cocos2d::UserDefault::getInstance()->getIntegerForKey("Coins",0);

	__String *coinScore = __String::createWithFormat("%i" ,coins);
	coinLabel = Label::createWithTTF(coinScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);
	coinLabel->setColor(Color3B::WHITE);
	coinLabel->setAnchorPoint(Vec2(0, 1));
	coinLabel->setPosition(Point(0+Sprite::create("Pipe&Ball/Ball.png")->getContentSize().width*4.5+origin.x, visibleSize.height - Sprite::create("Pipe&Ball/Ball.png")->getContentSize().height*1.2 + origin.y));
	coinLabel->setScale(0.3);
	coinLabel->setString(coinScore->getCString());
	this->addChild(coinLabel, 1);


	__String *CoinsNullScore = __String::createWithFormat("%i", nullcoins);
	CoinsNullLabel = Label::createWithTTF(CoinsNullScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);
	CoinsNullLabel->setColor(Color3B::WHITE);
	CoinsNullLabel->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height * 0.75 + origin.y));
	CoinsNullLabel->setVisible(false);
	this->addChild(CoinsNullLabel);
											//free game
	//***********************************
	hero = new Hero(this);
	
	if (newLvl==0) {
		
		this->schedule(schedule_selector(GameScene::SpawnPipe), PIPE_SPAWN_FREQUENCY * visibleSize.width);
		this->schedule(schedule_selector(GameScene::SpawnCoins), (PIPE_SPAWN_FREQUENCY * 2.5) * visibleSize.width);
	}
	else if (newLvl==1) {
		hero->astroBoy->setScale(heroScale+0.2);
		this->schedule(schedule_selector(GameScene::SpawnPipe), (PIPE_SPAWN_FREQUENCY/1.5) * visibleSize.width);
		this->schedule(schedule_selector(GameScene::SpawnCoins), (PIPE_SPAWN_FREQUENCY * 2.5) * visibleSize.width);
	}		
	else if (newLvl==2) {
		hero->astroBoy->setScale(heroScale+0.2);
		this->schedule(schedule_selector(GameScene::SpawnPipe), (PIPE_SPAWN_FREQUENCY/1.5) * visibleSize.width);
		this->schedule(schedule_selector(GameScene::SpawnCoins), (PIPE_SPAWN_FREQUENCY * 2.5) * visibleSize.width);
	}
											//Missions
	//lvl 1
	else if (newLvl == 3) {
		this->schedule(schedule_selector(GameScene::SpawnPipe), PIPE_SPAWN_FREQUENCY * visibleSize.width);
	}
	//lvl 2
	else if (newLvl == 4) {
		this->schedule(schedule_selector(GameScene::SpawnPipe), PIPE_SPAWN_FREQUENCY * visibleSize.width);
	}
	//lvl 3
	else if (newLvl == 5) {
		this->schedule(schedule_selector(GameScene::SpawnPipe), PIPE_SPAWN_FREQUENCY * visibleSize.width);
	}
	//lvl 4
	else if (newLvl == 6) {
		pipe.sec = 30;
		scoreLabel->setVisible(false);
		this->schedule(schedule_selector(GameScene::SpawnPipe), PIPE_SPAWN_FREQUENCY * visibleSize.width);
		this->schedule(schedule_selector(GameScene::Timer), 1);
	}
	//lvl 5
	else if (newLvl == 7) {
		this->schedule(schedule_selector(GameScene::SpawnPipe), PIPE_SPAWN_FREQUENCY * visibleSize.width);
	}
	//lvl 6
	else if (newLvl == 8) {
		this->schedule(schedule_selector(GameScene::SpawnPipe), PIPE_SPAWN_FREQUENCY * visibleSize.width);
	}
	//lvl 7
	else if (newLvl == 9) {
		scoreLabel->setVisible(false);
		CoinsNullLabel->setVisible(true);
		this->schedule(schedule_selector(GameScene::FreeObstacles), (PIPE_SPAWN_FREQUENCY/2) * visibleSize.width);
		this->schedule(schedule_selector(GameScene::SpawnCoins), (PIPE_SPAWN_FREQUENCY *2) * visibleSize.width);
	}
	//lvl 8
	else if (newLvl == 10) {
		pipe.sec = 40;
		scoreLabel->setVisible(false);
		this->schedule(schedule_selector(GameScene::SpawnPipe), PIPE_SPAWN_FREQUENCY * visibleSize.width);
		this->schedule(schedule_selector(GameScene::Timer), 1);
	}

	//***********************************

	
	//Contact with listener
	//***********************************
    auto contactListener = EventListenerPhysicsContact::create( );
    contactListener->onContactBegin = CC_CALLBACK_1( GameScene::onContactBegin, this );
    Director::getInstance( )->getEventDispatcher( )->addEventListenerWithSceneGraphPriority( contactListener, this );
	//***********************************

    //Touch Listener
	//***********************************
    auto touchListener = EventListenerTouchOneByOne::create( );
    touchListener->setSwallowTouches( true );
    touchListener->onTouchBegan = CC_CALLBACK_2( GameScene::onTouchBegan, this );
    Director::getInstance( )->getEventDispatcher( )->addEventListenerWithSceneGraphPriority( touchListener, this );
	//***********************************


   

	//Timer Label
	//***********************************
	__String *timerScore = __String::createWithFormat("%i", pipe.sec);
	timerLabel = Label::createWithTTF(timerScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);
	timerLabel->setColor(Color3B::WHITE);
	timerLabel->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height * 0.75 + origin.y));
	timerLabel->setVisible(false);
	this->addChild(timerLabel, 1);



	//***********************************
	//Add a pause button
	//***********************************
    
    auto pause = MenuItemImage::create("PauseButton.png", "PauseButton1.png", CC_CALLBACK_1(GameScene::Pause, this));
    pause->setPosition(Point(visibleSize.width+origin.x, visibleSize.height+origin.y));
    pause->setScale(0.07);
    pause->setAnchorPoint(Vec2(1, 1));

	
	

	
    auto menu = Menu::create(pause,  NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
	//**********************************
	
    this->scheduleUpdate( );
	//MusicBool = true;
	Pipe(newLvl);
    return true;
}



void GameScene::SpawnPipe( float dt )
{
	pipe.SpawnPipe(this,newLvl);
	int z = 1;
	if (score > z) {
		pipe.DeleteSprites(this);
		z = score;
	}	
	
}
void GameScene::SpawnCoins(float dt) {
	pipe.CoinSpawn(this);
}
void GameScene::FreeObstacles(float dt) {
	pipe.Obstacles(this);
}
void GameScene::Timer(float dt) {
	timerLabel->setVisible(true);
		__String *timerScore = __String::createWithFormat("%i", pipe.sec);
		if (pipe.sec >=-2) {
			timerLabel->setString("0");
		}
		else {
			timerLabel->setString(timerScore->getCString());
		}
		pipe.sec = pipe.sec - 1;
	
}


bool GameScene::onContactBegin( cocos2d::PhysicsContact &contact )
{
    PhysicsBody *a = contact.getShapeA( )->getBody();
    PhysicsBody *b = contact.getShapeB( )->getBody();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//Die collision
    if ( ( BIRD_COLLISION_BITMASK == a->getCollisionBitmask( ) && OBSTACLE_COLLISION_BITMASK == b->getCollisionBitmask() ) || ( BIRD_COLLISION_BITMASK == b->getCollisionBitmask( ) && OBSTACLE_COLLISION_BITMASK == a->getCollisionBitmask() ) )
    {        
        auto scene = GameOverScene::createScene( score,newLvl,Bonus );
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Music/dead.wav");
        Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
		
    }
	//coins score
	else if ((BIRD_COLLISION_BITMASK == a->getCollisionBitmask() && COIN_COLLISION_BITMASK == b->getCollisionBitmask()) || (BIRD_COLLISION_BITMASK == b->getCollisionBitmask() && COIN_COLLISION_BITMASK == a->getCollisionBitmask())) {
		nullcoins = nullcoins + 1;
		coins = coins + 1;
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Music/coin.wav");

		__String *CoinsScore = __String::createWithFormat("%i", coins);
		coinLabel->setString(CoinsScore->getCString());

		__String *CoinsNullScore = __String::createWithFormat("%i", nullcoins);
		CoinsNullLabel->setString(CoinsNullScore->getCString());

		cocos2d::UserDefault::getInstance()->setIntegerForKey("Coins", coins);

		pipe.CoinDelete(this);
		MissionsEnded(nullcoins, newLvl);
	}
	//Score +1 collision
    else if ( ( BIRD_COLLISION_BITMASK == a->getCollisionBitmask( ) && POINT_COLLISION_BITMASK == b->getCollisionBitmask() ) || ( BIRD_COLLISION_BITMASK == b->getCollisionBitmask( ) && POINT_COLLISION_BITMASK == a->getCollisionBitmask() ) )
    {
		auto Fade = FadeOut::create(1.0f);
	
		score = score + pipe.bonus;
		pipe.bonus++;
		pipe.Bonus(this);
		pipe.DeletePipe(this);
		if (pipe.bonus > 1) {
			Bonus++;
		}
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Music/coin.wav");
		__String *tempScore = __String::createWithFormat("%i", score);

		scoreLabel->setString(tempScore->getCString());
	
		pipe.BonusLabel->runAction(Fade);
		if (pipe.bonus >= 3) {
			pipe.DeleteBonus(this);
		}
		z = 0;
		MissionsEnded(score, newLvl);
	}
    
	//Score -1 collision
	else if ((BIRD_COLLISION_BITMASK == a->getCollisionBitmask() && MINUS_POINT_COLLISION_BITMASK == b->getCollisionBitmask()) || (BIRD_COLLISION_BITMASK == b->getCollisionBitmask() && MINUS_POINT_COLLISION_BITMASK == a->getCollisionBitmask()))
	{
		
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Music/LostPoint.wav");
		//Lvl 5
		if (newLvl == 7) {
			score = 1;
			pipe.bonus = 1;
			if (z == 1) {
				score = 0;
			}
		//	__String *tempScore = __String::createWithFormat("%i", score);
		//	scoreLabel->setString(tempScore->getCString());
		}
		//lvl 4 && lvl 8
		if (newLvl == 6 || newLvl == 10) {
			score = 0;
		}
		//lvl 6
		if (newLvl == 8) {
			heroScale = heroScale + 0.1;
			hero->astroBoy->setScale(heroScale);
		}
		
			score--;
			pipe.bonus = 1;
			MinusPoint=MinusPoint+1;
			pipe.DeletePipe(this);
			pipe.DeleteBonus(this);
			__String *tempScore = __String::createWithFormat("%i", score);
			scoreLabel->setString(tempScore->getCString());
			z++;
		
		//scoreLabel->setString(tempScore->getCString());
		MissionsEnded(MinusPoint, newLvl);
	}
	//Die if score -1
	if (score == -1) {
		score = 0;
		auto scene = GameOverScene::createScene(score,newLvl,Bonus);

		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
    return true;
}


bool GameScene::onTouchBegan( cocos2d::Touch *touch, cocos2d::Event *event )
{
    hero->Fly( );
	hero->Animation( );
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Music/Flappy.wav");
    this->scheduleOnce( schedule_selector( GameScene::StopFlying ), BIRD_FLY_DURATION );
	
    return true;
}

void GameScene::StopFlying( float dt )
{
    hero->StopFlying( );
}

void GameScene::update( float dt )
{
    hero->Fall( );
}


void GameScene::Pause(cocos2d::Ref *sender) {
	auto scene = PauseScene::createScene();
	Director::getInstance()->pushScene(scene);
}
void GameScene::EndMission() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto scene = MissionsScene::createScene();
	auto sprite = Sprite::create("complete.jpg");
		 sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite);
	Director::getInstance()->replaceScene(TransitionFade::create(5, scene));
}

void GameScene::MissionsEnded(unsigned int score, unsigned int lvl) {
	
	if (lvl == 3) {
		if (score >= 20) {
			
			cocos2d::UserDefault::getInstance()->setBoolForKey("lvl1", true);
			EndMission();
			coins += 1;
			cocos2d::UserDefault::getInstance()->setIntegerForKey("Coins", coins);
		}
	}
	if (lvl == 4) {
		if (pipe.bonus == 10) {
			cocos2d::UserDefault::getInstance()->setBoolForKey("lvl2", true);
			EndMission();
			coins += 2;
			cocos2d::UserDefault::getInstance()->setIntegerForKey("Coins", coins);
		}
	}
	if (lvl == 5) {
		if (MinusPoint == 10) {
			cocos2d::UserDefault::getInstance()->setBoolForKey("lvl3", true);
			EndMission();
			coins += 3;
				cocos2d::UserDefault::getInstance()->setIntegerForKey("Coins", coins);
		}
	}
	if (lvl == 6) {
		if (pipe.sec == -1) {
			cocos2d::UserDefault::getInstance()->setBoolForKey("lvl4", true);
			EndMission();
			coins += 4;
				cocos2d::UserDefault::getInstance()->setIntegerForKey("Coins", coins);

		}
	}
	if (lvl == 7) {
		if (score >= 50) {
			timerLabel->setVisible(false);
			cocos2d::UserDefault::getInstance()->setBoolForKey("lvl5", true);
			EndMission();
			coins += 5;
				cocos2d::UserDefault::getInstance()->setIntegerForKey("Coins", coins);
		}
	}
	if (lvl == 8) {
		if (score >= 60) {
			cocos2d::UserDefault::getInstance()->setBoolForKey("lvl6", true);
			EndMission();
			coins += 6;
				cocos2d::UserDefault::getInstance()->setIntegerForKey("Coins", coins);
		}
	}
	if (lvl == 9) {
		if (nullcoins == 10) {

			cocos2d::UserDefault::getInstance()->setBoolForKey("lvl7", true);
			EndMission();
			coins += 7;
				cocos2d::UserDefault::getInstance()->setIntegerForKey("Coins", coins);
		}

	}
	if (lvl == 10) {
		if (pipe.sec == -1) {
			cocos2d::UserDefault::getInstance()->setBoolForKey("lvl8", true);
			EndMission();
			coins += 8;
				cocos2d::UserDefault::getInstance()->setIntegerForKey("Coins", coins);
		}
	
	}
	
}
