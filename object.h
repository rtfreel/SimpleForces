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

	//increase object's parameters
	virtual void increase();

	//update object state
	virtual void update();

	//draw object
	virtual void draw(SDL_Renderer* renderer, bool info = false);

	//check if point is within the object
	virtual bool isWithin(Vector2D point);

	//object's velocity, acceleration and position in space
	Vector2D vel, acc, pos;
	float mass;
};

#endif