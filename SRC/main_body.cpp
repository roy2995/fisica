#include "main_body.h"

void cuerpo::debuginfo()
{
	std::cout << "m: " << mass << std::endl;
	std::cout << "s: ", position.debug();
	std::cout << "v: ", velocity.debug();
}

void cuerpo::addforce(const vect_2& v)
{
	force += v;

}