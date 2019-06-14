#include "vehicle.h"
#include "iostream"
using namespace std;
Vehicle::Vehicle() :x(0), y(0) {};
void  Vehicle::LoadMap(const char* a)
{
	if (strcmp(a, "left") == 0)
	{
		y--;
	}
	if (strcmp(a, "right") == 0)
	{
		y++;
	}
	if (strcmp(a, "up") == 0)
	{
		x--;
	}
	if (strcmp(a, "down") == 0)
	{
		x++;
	}
};
void Vehicle::show()
{
	cout << "<" << x << "," << y << ">" << endl;
};
