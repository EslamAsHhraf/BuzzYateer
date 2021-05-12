#include"Rover.h"

Rover::Rover(int speed) :noOfMissions(0), Speed(speed)
{
}

void Rover::operator++()
{
	noOfMissions++;
}

int Rover::getSpeed()
{
	return Speed;
}

int Rover::getnoOfMissions()
{
	return noOfMissions;
}
