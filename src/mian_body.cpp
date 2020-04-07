#include "mian_body.h"

void cuerpo::massvalue(float m)
{
	mass = m;
}

void cuerpo::intansvel(vect_2 v)
{
	velocity = v;
}

void cuerpo::intanspos(vect_2 v)
{
	position = v;
}

float cuerpo::getmass()
{
	return mass;
}

float cuerpo::intansinvmass()
{
	return invmass;
}

vect_2 cuerpo::getvel()
{
	return velocity;
}

vect_2 cuerpo::getpos()
{
	return position;
}

void cuerpo::debuginfo()
{
	std::cout << "m: " << mass << std::endl;
	std::cout << "s: ", position.debug();
	std::cout << "v: ", velocity.debug();
}

void cuerpo::addforce(vect_2 v)
{
}
