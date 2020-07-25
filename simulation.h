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
	virtual void update();

	//draw objects
	virtual void draw();

	//clear render
	void clear();

	//render last updates
	void render();

	//main loop
	virtual void loop();

protected:
	//true, if simulation is running at the moment
	bool _running = false;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

#endif