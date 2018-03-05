#include "Pipe.h"
#include "Definitions.h"

USING_NS_CC;

Pipe::Pipe()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}

void Pipe::SpawnPipe(cocos2d::Layer *layer,unsigned int yep)
{
	auto random = CCRANDOM_0_1();

	if (random < LOWER_SCREEN_PIPE_THRESHOLD)
	{
		random = LOWER_SCREEN_PIPE_THRESHOLD;
		run = GO_UP;
	}
	else if (random > UPPER_SCREEN_PIPE_THRESHOLD)
	{
		random = UPPER_SCREEN_PIPE_THRESHOLD;
		run = GO_DOWN;
	}


	//Sprites
	//***********************************
	auto topBall = Sprite::create("Pipe&Ball/Ball.png");
	topBall->setTag(6);
	topBall->setScale(2);
	auto topPipePosition = (random * visibleSize.height) + (topBall->getContentSize().height / 2);
	topBall->setPosition(Point(visibleSize.width + topBall->getContentSize().width + origin.x, topPipePosition));
	layer->addChild(topBall);
	
	auto botBall = Sprite::create("Pipe&Ball/Ball.png");
	botBall->setTag(7);
	botBall->setScale(2);
	botBall->setPosition(Point(topBall->getPositionX(), topPipePosition - (Sprite::create("Pipe&Ball/Ball.png")->getContentSize().height * PIPE_GAP) - topBall->getContentSize().height));
	layer->addChild(botBall);

	auto Pipe = Sprite::create("Pipe&Ball/pipe.png");
	Pipe->setTag(8);
	Pipe->setAnchorPoint(Vec2(0.5, 1));
	Pipe->setScale(1);
	Pipe->setPosition(Point(visibleSize.width + topBall->getContentSize().width + origin.x, topPipePosition));
	layer->addChild(Pipe);
	//***********************************


	//Sprites physics body
	//***********************************
	auto topBallBody = PhysicsBody::createCircle(topBall->getContentSize().width / 2);
	topBallBody->setDynamic(false);
	topBallBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	topBallBody->setContactTestBitmask(true);
	topBall->setPhysicsBody(topBallBody);
	
	auto botBallBody = PhysicsBody::createCircle(botBall->getContentSize().width / 2);
	botBallBody->setDynamic(false);
	botBallBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	botBallBody->setContactTestBitmask(true);
	botBall->setPhysicsBody(botBallBody);
	//***********************************
	

	//Sprites runAction
	//***********************************
	auto pipe = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	auto pipeDown = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Vec2(0, run));//
	auto PipeSpawn = Spawn::create(pipe, pipeDown, NULL);//

	auto topPipeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	auto topPipeDown = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Vec2(0, run));//
	auto topPipeSpawn = Spawn::create(topPipeAction, topPipeDown, NULL);//

	auto bottomPipeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	auto botPipeDown = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Vec2(0,run));//
	auto bottomPipeSpawn = Spawn::create(bottomPipeAction, botPipeDown, NULL);//

	
	//***********************************



	//Point pipe node
	//***********************************
	auto pointNode = Node::create();
	auto pointBody = PhysicsBody::createBox(Size(1, Sprite::create("Pipe&Ball/Ball.png")->getContentSize().height* PIPE_GAP));
	pointBody->setDynamic(false);
	pointBody->setCollisionBitmask(POINT_COLLISION_BITMASK);
	pointBody->setContactTestBitmask(true);
	pointNode->setPhysicsBody(pointBody);
	pointNode->setPosition(Point(topBall->getPositionX(), topBall->getPositionY() - (topBall->getContentSize().height / 2) - ((Sprite::create("Pipe&Ball/Ball.png")->getContentSize().height * PIPE_GAP) / 2)));
	pointNode->setTag(1);
	layer->addChild(pointNode);
	//***********************************


	//Top node -1
	//***********************************
	auto topPointNode = Node::create();
	auto topPointBody = PhysicsBody::createBox(Size(1, Sprite::create("Pipe&Ball/Ball.png")->getContentSize().height * 53));
	topPointBody->setDynamic(false);
	topPointBody->setCollisionBitmask(MINUS_POINT_COLLISION_BITMASK);
	topPointBody->setContactTestBitmask(true);
	topPointNode->setPhysicsBody(topPointBody);
	topPointNode->setPosition(Point(topBall->getPositionX(), topBall->getPositionY() + (topBall->getContentSize().height /2) + ((Sprite::create("Pipe&Ball/Ball.png")->getContentSize().height *MINUS_PIPE_GAP ) /2)));
	topPointNode->setTag(2);
	layer->addChild(topPointNode);
	//***********************************


	//Bot node -1
	//***********************************
	auto botPointNode = Node::create();
	auto botPointBody = PhysicsBody::createBox(Size(1, Sprite::create("Ball.png")->getContentSize().height * MINUS_PIPE_GAP));
	botPointBody->setDynamic(false);
	botPointBody->setCollisionBitmask(MINUS_POINT_COLLISION_BITMASK);
	botPointBody->setContactTestBitmask(true);
	botPointNode->setPhysicsBody(botPointBody);
	botPointNode->setPosition(Point(botBall->getPositionX(), botBall->getPositionY() - (botBall->getContentSize().height / 2) - ((Sprite::create("Pipe&Ball/Ball.png")->getContentSize().height * MINUS_PIPE_GAP) / 2)));
	botPointNode->setTag(3);
	layer->addChild(botPointNode);
	//***********************************


	//Nodes runAction
	//***********************************
	auto botPointNodeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	auto botPointNodeDown = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Vec2(0, run));
	auto botPointNodeSpawn = Spawn::create(botPointNodeAction, botPointNodeDown, NULL);

	

	auto topPointNodeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	auto topPointNodeDown = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Vec2(0, run));
	auto topPointNodeSpawn = Spawn::create(topPointNodeAction, topPointNodeDown, NULL);

	

	auto pointNodeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	auto pointNodeDown = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Vec2(0, run));
	auto pointNodeSpawn = Spawn::create(pointNodeAction, pointNodeDown, NULL);

	
	//***********************************


	//insane lvl
	if (yep == 2 || yep ==8 || yep==10) {
		Pipe->runAction(PipeSpawn);
		topBall->runAction(topPipeSpawn);
		botBall->runAction(bottomPipeSpawn);
		botPointNode->runAction(botPointNodeSpawn);
		topPointNode->runAction(topPointNodeSpawn);
		pointNode->runAction(pointNodeSpawn);
	}
	else {
		Pipe->runAction(pipe);
		topBall->runAction(topPipeAction);
		botBall->runAction(bottomPipeAction);
		botPointNode->runAction(botPointNodeAction);
		topPointNode->runAction(topPointNodeAction);
		pointNode->runAction(pointNodeAction);
	}
}
void Pipe::DeletePipe(cocos2d::Layer *layer) {
	layer->removeChildByTag(1);//pointNode
	layer->removeChildByTag(2);//topPointNode
	layer->removeChildByTag(3);//BotPointNode
	layer->removeChildByTag(4);//topBallNode
	layer->removeChildByTag(5);//botBallNode


}
void Pipe::DeleteSprites(cocos2d::Layer *layer) {

	layer->removeChildByTag(6);//topBall
	layer->removeChildByTag(7);//botBall
	layer->removeChildByTag(8);//Pipe
	layer->removeChildByTag(11);//center ball
	
}
void Pipe::CoinDelete(cocos2d::Layer *layer) {
	layer->removeChildByTag(12);//coin
}
void Pipe::Bonus(cocos2d::Layer *layer) {

	__String *bonusScore = __String::createWithFormat("%i" "%c", bonus, 'x');

	BonusLabel = Label::createWithTTF(bonusScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE);
	BonusLabel->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	BonusLabel->setTag(9);
	layer->addChild(BonusLabel);
}

void Pipe::DeleteBonus(cocos2d::Layer *layer) {
	layer->removeChildByTag(9);
	layer->removeChildByTag(10);
}
void Pipe::Obstacles(cocos2d::Layer *layer) {
	auto random = CCRANDOM_0_1();
	auto secRand = CCRANDOM_0_1();
	if (random < LOWER_SCREEN_PIPE_THRESHOLD)
	{
		random = LOWER_SCREEN_PIPE_THRESHOLD;
		//run = GO_UP;
	}
	else if (random > UPPER_SCREEN_PIPE_THRESHOLD)
	{
		random = UPPER_SCREEN_PIPE_THRESHOLD;
		//run = GO_DOWN;
	}
	auto topBalll = Sprite::create("Pipe&Ball/Ball.png");
	topBalll->setTag(6);
	topBalll->setScale(2);
	//auto topPipePosition = (random * visibleSize.height) + (topBalll->getContentSize().height / 2);
	//topBalll->setPosition(Point(visibleSize.width + topBalll->getContentSize().width + origin.x, topPipePosition));
	topBalll->setPosition(Point(visibleSize.width + topBalll->getContentSize().width+origin.x, (random*0.9)*visibleSize.height + (topBalll->getContentSize().height / 2)));
	layer->addChild(topBalll);

	auto centerBall = Sprite::create("Pipe&Ball/Ball.png");
	centerBall->setTag(11);
	centerBall->setScale(2);
	centerBall->setPosition(Point(visibleSize.width+(random*250)+ centerBall->getContentSize().width + origin.x,(random*1.15)*visibleSize.height  + (centerBall->getContentSize().height / 2)));
	layer->addChild(centerBall);

	auto botBalll = Sprite::create("Pipe&Ball/Ball.png");
	//botBalll->setTag(7);
	botBalll->setScale(2);
	//botBall->setPosition(Point(topBall->getPositionX(), topPipePosition - (Sprite::create("Pipe&Ball/Ball.png")->getContentSize().height * PIPE_GAP) - topBall->getContentSize().height));
	botBalll->setPosition(Point(visibleSize.width+(random*400)-200 + botBalll->getContentSize().width + origin.x, (random*1.29)*visibleSize.height + (botBalll->getContentSize().height / 2)));
	layer->addChild(botBalll);

	
	//Sprites physics body
	//***********************************
	auto topBalllBody = PhysicsBody::createCircle(topBalll->getContentSize().width / 2);
	topBalllBody->setDynamic(false);
	topBalllBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	topBalllBody->setContactTestBitmask(true);
	topBalll->setPhysicsBody(topBalllBody);

	auto botBalllBody = PhysicsBody::createCircle(botBalll->getContentSize().width / 2);
	botBalllBody->setDynamic(false);
	botBalllBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	botBalllBody->setContactTestBitmask(true);
	botBalll->setPhysicsBody(botBalllBody);

	auto centerBallBody = PhysicsBody::createCircle(centerBall->getContentSize().width / 2);
	centerBallBody->setDynamic(false);
	centerBallBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	centerBallBody->setContactTestBitmask(true);
	centerBall->setPhysicsBody(centerBallBody);

	
	//***********************************

	auto topPipeeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	

	auto bottomPipeeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	

	auto centerPipeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));

	

	auto callback = CallFunc::create([=]() { DeleteSprites(layer); });

	//***********************************
	topBalll->runAction(Sequence::create(topPipeeAction,callback, nullptr));
	botBalll->runAction(Sequence::create(bottomPipeeAction,callback, nullptr));
	centerBall->runAction(Sequence::create(centerPipeAction,callback, nullptr));
	
}
void Pipe::CoinSpawn(cocos2d::Layer *layer) {
	auto random = CCRANDOM_0_1();
	auto coin = Sprite::create("Coin.png");
	coin->setTag(12);
	coin->setScale(0.1);
	coin->setPosition(Point(visibleSize.width + coin->getContentSize().width + origin.x, random*visibleSize.height + (coin->getContentSize().height / 2)));
	layer->addChild(coin);

	auto coinBody = PhysicsBody::createCircle(coin->getContentSize().width / 2);
	coinBody->setDynamic(false);
	coinBody->setCollisionBitmask(COIN_COLLISION_BITMASK);
	coinBody->setContactTestBitmask(true);

	coin->setPhysicsBody(coinBody);

	auto coinAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));

	coin->runAction(Sequence::create(coinAction, CallFunc::create([=]() { CoinDelete(layer); }), nullptr));
}