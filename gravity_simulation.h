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

	void addCircle();

	Circle selected;
	std::vector<Circle> circles;
};

#endif