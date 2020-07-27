#include "circle.h"

Circle::Circle() {}

Circle::Circle(float x, float y, float mass) : Object(x, y, mass), radius(mass * 2) {}

void Circle::collide(Circle* circle) {

    //new velocities directions calculation:
    //
    //calculations for this circle
    //vector from center to collision point
    Vector2D toCol = Vector2D::connect(this->pos, circle->pos);
    toCol.setMag(this->radius);
    //magnitude of projection of velocity on the vector from center to collisison
    float projectionMag = ((this->vel.x * toCol.x) + (this->vel.y * toCol.y)) / toCol.mag();
    toCol.setMag(projectionMag);
    //vector directed as new circle's velocity
    Vector2D newThisVel = Vector2D(this->vel.x - (2 * toCol.x), this->vel.y - (2 * toCol.y));
    //
    //calculations for another circle
    //vector from center to collision point
    toCol = Vector2D::connect(circle->pos, this->pos);
    toCol.setMag(circle->radius);
    //magnitude of projection of velocity on the vector from center to collisison
    projectionMag = ((circle->vel.x * toCol.x) + (circle->vel.y * toCol.y)) / toCol.mag();
    toCol.setMag(projectionMag);
    //vector directed as new circle's velocity
    Vector2D newCircleVel = Vector2D(circle->vel.x - (2 * toCol.x), circle->vel.y - (2 * toCol.y));

    //new velocities magnitudes calculation (based on conservation of energy and momentum):
    //
    //calculations for another circle
    float newCircleVelMag = ((2 * this->mass * this->vel.mag()) + (abs(circle->mass - this->mass) * circle->vel.mag())) / (this->mass + circle->mass);
    newCircleVel.setMag(newCircleVelMag);
    //calculations for this circle
    float newThisVelMag = newCircleVelMag + this->vel.mag() - circle->vel.mag();
    newThisVel.setMag(newThisVelMag);

    //applying new velosities:
    this->vel = newThisVel;
    circle->vel = newCircleVel;

    printf("First:\t x = %f,\t y = %f,\t mag = %f;\n", this->vel.x, this->vel.y, this->vel.mag());
    printf("Second:\t x = %f,\t y = %f,\t mag = %f;\n", circle->vel.x, circle->vel.y, circle->vel.mag());
}

void Circle::increase() {
	this->mass += globals::INCREASE;
	this->radius = pow(this->mass, 0.5f);
}

bool Circle::isWithin(Vector2D point) {
    if (Vector2D::connect(this->pos, point).mag() <= radius) {
        return true;
    }
    return false;
}

void Circle::update() {
    if (radius == 0) {
        radius = pow(this->mass, 0.5f);
    }
	Object::update();
}

void Circle::draw(SDL_Renderer* renderer, bool info) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

    int32_t x = (this->radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - (this->radius * 2));

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, this->pos.x + x, this->pos.y - y);
        SDL_RenderDrawPoint(renderer, this->pos.x + x, this->pos.y + y);
        SDL_RenderDrawPoint(renderer, this->pos.x - x, this->pos.y - y);
        SDL_RenderDrawPoint(renderer, this->pos.x - x, this->pos.y + y);
        SDL_RenderDrawPoint(renderer, this->pos.x + y, this->pos.y - x);
        SDL_RenderDrawPoint(renderer, this->pos.x + y, this->pos.y + x);
        SDL_RenderDrawPoint(renderer, this->pos.x - y, this->pos.y - x);
        SDL_RenderDrawPoint(renderer, this->pos.x - y, this->pos.y + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - (this->radius * 2));
        }
    }

	if (info) {
		//show velocity vector
		SDL_RenderDrawLine(renderer, pos.x, pos.y, pos.x + (vel.x * defaults::SHOW_VEL), pos.y + (vel.y * defaults::SHOW_VEL));
	}
}