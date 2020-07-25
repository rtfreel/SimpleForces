#include "gravity_simulation.h"
#include "circle.h"

GravitySimulation::GravitySimulation() {}

void GravitySimulation::loop() {
	SDL_Event event;

	while (true) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				SDL_Quit();
				break;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				this->addCircle();
			}
		}
		this->update();
		this->draw();
	}
}

void GravitySimulation::update() {
	for (int i = 0; i < circles.size(); i++) {
		this->circles.at(i).update();
		for (int j = 0; j < circles.size(); j++) {
			if (i == j)
				continue;
			Vector2D force = Vector2D::connect(this->circles.at(i).pos, this->circles.at(j).pos);
			float forceMag = defaults::G_CONST * (this->circles.at(i).mass * this->circles.at(j).mass) / (force.mag() * force.mag());
			force.setMag(forceMag);
			this->circles.at(i).applyForce(force);
		}
	}
}

void GravitySimulation::addCircle() {
	this->selected = Circle();
	this->selected.mass = 1;
	int x, y;
	SDL_GetMouseState(&x, &y);
	this->selected.pos.x = (float)x;
	this->selected.pos.y = (float)y;
	this->circles.push_back(selected);
}

void GravitySimulation::draw() {
	this->clear();
	this->selected.draw(this->_renderer);
	for (int i = 0; i < circles.size(); i++) {
		this->circles.at(i).draw(this->_renderer);
	}
	this->render();
}