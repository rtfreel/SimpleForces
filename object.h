#ifndef OBJECT_H
#define OBJECT_H

#include "globals.h"
#include <SDL.h>

class Object {
public:

	//create empty object
	Object();

	//create new object with given coordinates and mass
	Object(float x, float y, float mass = 1.0f);
	
	//set random parameters
	void randomize();

	//apply force to the object
	void applyForce(Vector2D force);

	//increases object's parameters
	virtual void increase();

	//updates object state
	virtual void update();

	//draws object
	virtual void draw(SDL_Renderer* renderer, bool info = false);

	//object's velocity, acceleration and position in space
	Vector2D vel, acc, pos;
	float mass;
};

#endif