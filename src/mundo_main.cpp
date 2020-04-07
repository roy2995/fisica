#include "mundo_main.h"

void world::instansgravity(vect_2 v)
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

	float ax = gravity.getX();
	float ay = gravity.getY();

	//poara cuando hay objetos
	for (int i = 0; i < (int)bodies.size(); i++) {
		//posicion del cuerpo 
		float px = bodies[i]->getpos().getX();//almacenamos la posicion del cuerpo en x
		float py = bodies[i]->getpos().getY();//almacenamos la posicion del cuerpo en y
		//velocidad del cuerpo
		float vx = bodies[i]->getvel().getX();//almacenamos la velocidad del objeto en x
		float vy = bodies[i]->getvel().getY();//almacenamos la velocidad del objeto en y

		bodies[i]->intanspos(vect_2(px + vx * dt, py + vy * dt));
		bodies[i]->intansvel(vect_2(ax * dt + vx * dt, ay * dt + vy));

	}
}
