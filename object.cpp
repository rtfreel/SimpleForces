#include "object.h"

Object::Object() {
	this->pos = Vector2D();
	this->vel = Vector2D();
	this->acc = Vector2D();
}

Object::Object(float x, float y, float mass): mass(mass) {
	this->pos = Vector2D(x, y);
	this->vel = Vector2D();
	this->acc = Vector2D();
}

void Object::randomize() {
	this->pos = Vector2D::random(globals::HEIGHT);
	this->vel = Vector2D::random(defaults::MAX_VEL);
	this->acc = Vector2D::random(defaults::MAX_ACC);
	this->mass = defaults::MAX_MASS * ((float)rand() / (float)RAND_MAX);
}

void Object::applyForce(Vector2D force) {
	force.div(mass);
	this->acc.add(force);
}
void Object::increase() {
	mass *= defaults::SCALE;
}

bool Object::isWithin(Vector2D point) {
	return false;
}

void Object::update() {
	this->vel.add(this->acc);
	this->pos.add(this->vel);
	this->acc.mult(0);
}

void Object::draw(SDL_Renderer* renderer, bool info) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	//show object as a point
	SDL_RenderDrawPoint(renderer, pos.x, pos.y);
	if (info) {
		//show velocity vector
		SDL_RenderDrawLine(renderer, pos.x, pos.y, pos.x + (vel.x * defaults::SHOW_VEL), pos.y + (vel.y * defaults::SHOW_VEL));
	}
}