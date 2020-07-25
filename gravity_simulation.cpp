#include "gravity_simulation.h"
#include "circle.h"
#include "input.h"

GravitySimulation::GravitySimulation() {}

void GravitySimulation::loop() {
	SDL_Event event;
	Input input;

	while (true) {
		input.beginNewFrame();

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				input.keyDownEvent(event);
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				input.mouseDownEvent(event);
			}
			if (event.type == SDL_MOUSEBUTTONUP) {
				input.mouseUpEvent(event);
			}
			if (event.type == SDL_QUIT) {
				SDL_Quit();
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
			SDL_Quit();
			return;
		}
		if (input.wasKeyPressed(SDL_SCANCODE_Q) || input.isKeyHeld(SDL_SCANCODE_Q)) {
			this->G -= 0.02;
		}
		if (input.wasKeyPressed(SDL_SCANCODE_E) || input.isKeyHeld(SDL_SCANCODE_E)) {
			this->G += 0.02;
		}
		if (input.wasKeyPressed(SDL_SCANCODE_R)) {
			this->G = defaults::G_CONST;
		}
		if (input.wasMousePressed()) {
			this->createCircle();
		}else if (input.isMouseHeld()) {
			this->increase();
		}
		if (input.wasMouseReleased()) {
			this->circles.push_back(selected);
			this->selected = Circle();
		}
		this->update();
		this->draw();
	}
}

void GravitySimulation::createCircle() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	this->selected = Circle(x, y);
}

void GravitySimulation::increase() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (selected.isWithin(Vector2D(x, y))) {
		selected.increase();
	}
}

void GravitySimulation::update() {
	std::vector<Vector2D> collided;
	for (int i = 0; i < circles.size(); i++) {
		this->circles.at(i).update();
		for (int j = 0; j < circles.size(); j++) {
			if (i == j)
				continue;
			Vector2D force = Vector2D::connect(this->circles.at(i).pos, this->circles.at(j).pos);
			if (force.mag() < this->circles.at(i).radius + this->circles.at(j).radius) {
				bool colident = true;
				for (Vector2D col : collided) {
					if ((col.x == i && col.y == j) || (col.x == j && col.y == i)) {
						colident = false;
						break;
					}
				}
				if (colident) {
					this->circles.at(i).collide(&this->circles.at(j));
					collided.push_back(Vector2D(i, j));
				}
			}
			float forceMag = this->G * (this->circles.at(i).mass * this->circles.at(j).mass) / (force.mag() * force.mag());
			force.setMag(forceMag);
			this->circles.at(i).applyForce(force);
		}
	}
}

void GravitySimulation::draw() {
	this->clear();
	this->selected.draw(this->_renderer);
	for (int i = 0; i < circles.size(); i++) {
		this->circles.at(i).draw(this->_renderer);
	}
	this->render();
}