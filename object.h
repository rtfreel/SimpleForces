#ifndef OBJECT_H
#define OBJECT_H

#include "globals.h"

class Object {
public:

	//create empty object
	Object();

	//create new object with given mass
	Object(float mass = 1.0f);
	
	//apply force to the object
	void applyForce(Vector2D force);

	//updates object state
	void update();

	//draws object
	void draw();

	Vector2D vel, acc;
	float mass;
};

#endif