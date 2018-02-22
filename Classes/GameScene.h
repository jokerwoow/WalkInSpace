#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Pipe.h"
#include "Hero.h"
#include "LvlDifficult.h"
class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene(unsigned int lvl);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
private:
    void SetPhysicsWorld( cocos2d::PhysicsWorld *world ) { sceneWorld = world; };
    
    void SpawnPipe( float dt );
    
	void deleted( float a);
	void Pause(Ref *sender);
    bool onContactBegin( cocos2d::PhysicsContact &contact );
    
    bool onTouchBegan( cocos2d::Touch *touch, cocos2d::Event *event );
	unsigned int score;
	unsigned int Bonus=0;
	unsigned int MinusPoint = 0;

	void Timer(float dt);
    void StopFlying( float dt );
	void FreeObstacles(float dt);
    void update( float dt );
	void MissionsEnded(unsigned int score,unsigned int lvl);

	void SpawnCoins(float dt);
    cocos2d::PhysicsWorld *sceneWorld;
	void EndMission();
    Pipe pipe;
    Hero *hero;
	unsigned int coins;
	unsigned int nullcoins=0;
	float heroScale = 1;
	int z = 0;
	//char *xz;
    cocos2d::Label *scoreLabel;
	cocos2d::Label *timerLabel;
	cocos2d::Label *coinLabel;
	cocos2d::Label *CoinsNullLabel;

    
};

#endif // __GAME_SCENE_H__
