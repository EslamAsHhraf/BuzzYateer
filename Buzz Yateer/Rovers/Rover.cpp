#include"Rover.h"

Rover::Rover(int speed) :noOfMissions(0), Speed(speed)
{
}

void Rover::operator++()
{
	noOfMissions++;
}

void Rover::resetnoOfMissions()
{
	noOfMissions = 0;
}

int Rover::getSpeed()
{
	return Speed;
}

int Rover::getnoOfMissions()
{
	return noOfMissions;
}

Rover::~Rover()
{
}
