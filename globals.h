#ifndef GLOBALS_H
#define GLOBALS_H

#include <math.h>
#include <random>

namespace globals {
	//window size
	const int WIDTH = 1600;
	const int HEIGHT = 800;
}

namespace defaults {
	//max default speed and mass
	const float MAX_VEL = 0.02;
	const float MAX_ACC = 0.01;
	const float MAX_MASS = 50;

	//gravity constant
	const float G_CONST = 0;
}

struct Vector2D {
	float x, y;
	Vector2D() : x(0), y(0) {}
	Vector2D(float x, float y) : x(x), y(y) {}

	//create vector from two points
	static Vector2D connect(Vector2D startPoint, Vector2D endPoint) {
		return Vector2D(endPoint.x - startPoint.x,
			endPoint.y - startPoint.y);
	}

	//create random vector within given magnitude
	static Vector2D random(float mag = 1.0f) {
		//random vector, where: 0 <= (x & y) <= 1
		Vector2D vector = Vector2D((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX);
		//set random magnitude between 0 and mag
		vector.setMag((mag * 2 * (float)rand() / (float)RAND_MAX) - mag);
		return vector;
	}

	//multiply vector by a scalar
	void mult(float scalar) {
		x *= scalar;
		y *= scalar;
	}

	//multiply vector by a vector
	void mult(Vector2D vector) {
		x *= vector.x;
		y *= vector.y;
	}

	//add vector to vector
	void add(Vector2D vector) {
		x += vector.x;
		y += vector.y;
	}

	//set particular magnitude to the vector
	void setMag(float mag) {
		float multiplier = mag / sqrtf((x * x) + (y * y));
		x *= multiplier;
		y *= multiplier;
	}

	//return magnitude
	float mag() {
		return sqrtf((x * x) + (y * y));
	}
};

#endif