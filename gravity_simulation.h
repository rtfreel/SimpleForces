#ifndef GRAVITY_SIMULATION_H
#define GRAVITY_SIMULATION_H

#include "simulation.h"
#include "circle.h"

class GravitySimulation : public Simulation {
public:
	GravitySimulation();
	
	void draw();

	void update();

	void loop();

	void createCircle();

	void increase();

	Circle selected;
	std::vector<Circle> circles;
	float G = defaults::G_CONST;

	int frame;
};

#endif