#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <SDL.h>

class Simulation {
public:
	//prepare window, renderer and necessary variables
	Simulation();

	//start simulation with given parameters
	void start();

	//update scene
	void update();

	//draw objects
	void draw();

	//clear render
	void clear();

	//render last updates
	void render();

	//main loop
	void loop();

private:
	//true, if simulation is running at the moment
	bool _running = false;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

#endif