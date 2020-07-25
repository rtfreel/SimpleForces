#include "circle.h"

Circle::Circle() {}

Circle::Circle(float x, float y, float mass) : Object(x, y, mass), radius(mass * 2) {}

void Circle::increase() {
	this->mass *= 1.1f;
	this->radius = 2 * this->mass;
}

void Circle::update() {
    if (radius == 0) {
        radius = mass * 2;
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