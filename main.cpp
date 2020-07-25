#include <iostream>
#include <chrono>
#include "simulation.h"

int main(int argc, char* args[]) {
	//set random seed based on current time
	srand(std::chrono::system_clock::now().time_since_epoch().count());

	//create and start gravity simulation object
	Simulation simulation = Simulation();
	simulation.start();
	return 0;
}