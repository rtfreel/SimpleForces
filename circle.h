#ifndef CIRCLE_H
#define CIRCLE_H

#include "object.h"

class Circle : public Object {
public: 

	//create empty circle
	Circle();

	//create circle in particular location
	Circle(float x, float y, float mass = 1.0f);

	//increases parameters of the circle
	virtual void increase();

	//check if point is within the object
	virtual bool isWithin(Vector2D point);

	//updates object state
	virtual void update();

	//draws object
	virtual void draw(SDL_Renderer* renderer, bool info = false);

	float radius = 0;
};

#endif
