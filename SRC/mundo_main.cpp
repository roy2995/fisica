#include "mundo_main.h"

void world::instansgravity(const vect_2& v)
{
	gravity = v;
}

void world::addbody(cuerpo* b)
{
	bodies.push_back(b); // va agragando elementos al vector body
}

void world::step(float dt)
{
	if ((int)bodies.size() == 0) {
		std::cout << "no hay ningun cuerpo en el mundo." << std::endl;
		system("pause");
	}
	//integrador de force
	for (int i = 0; i < (int)bodies.size(); i++) {
		bodies[i]->velocity += dt * (gravity + bodies[i]->invmass * bodies[i]->force);

	}
	//poara cuando hay objetos
	for (int i = 0; i < (int)bodies.size(); i++) {

		bodies[i]->position += dt * bodies[i]->velocity;
		bodies[i]->force = vect_2(0.0f, 0.0f);

	}
}
