#include "math_proces.h"

using namespace std;

void vect_2::setvalue(float _x, float _y)
{
	x = _x;
	y = _y;

}

float vect_2::longd()
{
	return sqrt(x * x + y * y);
}

float vect_2::longdsquare()
{
	return x * x + y * y;
}

void vect_2::debug()
{
	std::cout << "elvector es (" << x << ", " << y << ")" << std::endl;
}

float vect_2::getX()
{
	return x;
}

float vect_2::getY()
{
	return y;
}

void vect_2::operator+=(vect_2 v)
{
	x += v.x;
	y += v.y;
}

void vect_2::operator-=(vect_2 v)
{
	x -= v.x;
	y -= v.y;
}

float vect_2::op_punto(vect_2 a, vect_2 b)
{
	return a.x * b.x + a.y * b.y;
}

float vect_2::op_cruz(vect_2 a, vect_2 b)
{
	return a.x * b.y - a.y * b.x;;
}
