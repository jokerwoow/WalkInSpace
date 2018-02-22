#include "Hero.h"
#include "Definitions.h"
#include "MyBodyParser.h"
#include "cocos2d.h"
USING_NS_CC;

Hero::Hero( cocos2d::Layer *layer )
{
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );


	__String *hero = __String::create(cocos2d::UserDefault::getInstance()->getStringForKey("hero","hero1"));


	const char *newhero = hero->getCString();

	__String *npg = String::createWithFormat("%s" "%s""%s","hero/", newhero, ".png");
	//const char *superhero = npg->getCString();

	astroBoy = Sprite::create(npg->getCString());
	//astroBoy = Sprite::create("hero/1.png");
	astroBoy->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	astroBoy->setScale(1);
	MyBodyParser::getInstance()->parseJsonFile("heroTest.json");

	auto flappyBody = MyBodyParser::getInstance()->bodyFormJson(astroBoy,hero->getCString(), PhysicsMaterial(1.0f, 0.0f, 1.0f));
	flappyBody->setCollisionBitmask(BIRD_COLLISION_BITMASK);
	flappyBody->setContactTestBitmask(true);
	//flappyBody->setAngularDamping(0);
	flappyBody->setDynamic(false);
	astroBoy->setPhysicsBody(flappyBody);
	layer->addChild(astroBoy, 100);
    isFalling = true;
}

void Hero::Fall( )
{
    if ( true == isFalling )
    {
        astroBoy->setPositionX( visibleSize.width / 2 + origin.x );
        astroBoy->setPositionY( astroBoy->getPositionY() - ( BIRD_FALLING_SPEED * visibleSize.height ) );
    }
    else
    {
        astroBoy->setPositionX( visibleSize.width / 2 + origin.x );
        astroBoy->setPositionY( astroBoy->getPositionY() + ( (BIRD_FLYINGUP_SPEED * visibleSize.height)*2 ) );
    }
}
void Hero::Animation() {
	/*auto animation = Animation::create();
	animation->addSpriteFrameWithFile("hero/hero2.png");
	animation->addSpriteFrameWithFile("hero/hero3.png");
	animation->addSpriteFrameWithFile("hero/hero4.png");
	animation->addSpriteFrameWithFile("hero/hero1.png");
	animation->setDelayPerUnit(0.2f);

	Animate* animate = Animate::create(animation);
	astroBoy->runAction(animate);*/
}

