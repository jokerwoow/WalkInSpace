#ifndef __HERO_H__
#define __HERO_H__

#include "cocos2d.h"
class Hero
{
public:
    Hero( cocos2d::Layer *layer );
    
    void Fall( );
    void Fly( ) { isFalling = false; };
    void StopFlying( ) { isFalling = true; }
	void Animation();
	cocos2d::Sprite *astroBoy;
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    

    bool isFalling;
    
};

#endif 
