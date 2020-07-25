#ifndef GLOBALS_H
#define GLOBALS_H

#include <math.h>

namespace globals {
	//window size
	const int WIDTH = 1600;
	const int HEIGHT = 800;
}

namespace defaults {
	//gravity constant
	const float g_const = 0;
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