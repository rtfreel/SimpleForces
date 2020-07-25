#include "simulation.h"
#include "globals.h"
#include <SDL.h>

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
	SDL_RenderClear(this->_renderer);
}

void Simulation::render() {
	SDL_RenderPresent(this->_renderer);
}

void Simulation::draw() {}

void Simulation::loop() {
	SDL_Event event;
	while (true) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				SDL_Quit();
				break;
			}
		}
		this->clear();
		this->render();
	}
}