#include "simulation.h"
#include "globals.h"
#include "circle.h"
#include <SDL.h>
#include <iostream>

Simulation::Simulation() {
	//init everything from SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	//create window and renderer by global constants
	SDL_CreateWindowAndRenderer(globals::WIDTH, globals::HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI, &this->_window, &this->_renderer);
}

void Simulation::start() {
	this->_running = true;
	
	//start simulation main loop
	this->loop();
}

void Simulation::clear() {
	//set background color
	SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 0);

	SDL_RenderClear(this->_renderer);
}

void Simulation::render() {
	SDL_RenderPresent(this->_renderer);
}

void Simulation::update() {}

void Simulation::draw() {}

void Simulation::loop() {
	SDL_Event event;

	Object object = Object();
	object.randomize();
	Vector2D force = Vector2D::random(defaults::MAX_ACC);

	while (true) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				SDL_Quit();
				break;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				object.applyForce(force);
			}
		}
		object.update();
		this->clear();
		object.draw(this->_renderer);
		this->render();
	}
}