#include"Rover.h"

Rover::Rover()
{
}

Rover::Rover(int s, int cd, int nom)
{
	setSpeed(s);
	setCheckupDuration(cd);
	setnoOfMissions(nom);
}

void Rover::setCheckupDuration(int cd)
{
	CheckupDuration = cd;
}

void Rover::setSpeed(int s)
{
	Speed = s;
}

void Rover::setnoOfMissions(int nom)
{
	noOfMissions = nom;
}

int Rover::getCheckupDuration()
{
	return CheckupDuration;
}

int Rover::getSpeed()
{
	return Speed;
}

int Rover::getnoOfMissions()
{
	return noOfMissions;
}
