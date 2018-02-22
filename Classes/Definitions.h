#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#define DISPLAY_TIME_SPLASH_SCENE 2 //Splash scene duration time 
#define TRANSITION_TIME 0.5 //Transition to new scene time
#define PIPE_SPAWN_FREQUENCY 0.002 //pipe spawn time

#define PIPE_GAP 15 // point pipe gap
#define MINUS_PIPE_GAP 50 // -1 point size 
#define UPPER_SCREEN_PIPE_THRESHOLD 0.65   //randomize pipes
#define LOWER_SCREEN_PIPE_THRESHOLD 0.35   //randomize pipes

#define PIPE_MOVEMENT_SPEED 0.005       //Pipe movement speed 

#define BIRD_COLLISION_BITMASK 1		 //Collision hero 
#define OBSTACLE_COLLISION_BITMASK 2	 //Collision physics world and ballons
#define POINT_COLLISION_BITMASK 3		 //Collision +1 point
#define MINUS_POINT_COLLISION_BITMASK 4  //Collision -1 point
#define COIN_COLLISION_BITMASK 5
#define BIRD_FLYINGUP_SPEED 0.0035	 //Herous fly
#define BIRD_FALLING_SPEED 0.0045	 //Herous fly
#define BIRD_FLYING_SPEED 0.0036	 //Herous fly
#define BIRD_FLY_DURATION 0.25       //Herous fly

#define SCORE_FONT_SIZE 0.1  //GameOver score size 

#define FIRST_COLUMN 4	  //Missions layout COLUMN 1
#define SECOND_COLUMN 2  //Missions layout COLUMN 2
#define THIRD_COLUMN 1.33 //Missions layout COLUMN 3


#define FIRST_ROW 1.5
#define SECOND_ROW 2
#define GO_UP 500		//insane lvl running pipes
#define GO_DOWN -500	//insane lvl running pipes

#endif // __DEFINITIONS_H__
