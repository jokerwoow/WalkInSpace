#ifndef __PIPE_H__
#define __PIPE_H__

#include "cocos2d.h"

class Pipe
{
public:
    Pipe();
    
    void SpawnPipe( cocos2d::Layer *layer ,unsigned int yep);
	void DeletePipe( cocos2d::Layer *layer );
	void DeleteSprites(cocos2d::Layer *layer);
	void Bonus(cocos2d::Layer *layer);
	void DeleteBonus(cocos2d::Layer *layer);
	void CoinDelete(cocos2d::Layer *layer);
	void CoinSpawn(cocos2d::Layer *layer);
	void Obstacles(cocos2d::Layer *layer);
	unsigned int bonus = 1;
	unsigned int sec;
	int run;
	cocos2d::Label *BonusLabel;
	cocos2d::Label *timerLabel;
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
	
};

#endif // __PIPE_H__
