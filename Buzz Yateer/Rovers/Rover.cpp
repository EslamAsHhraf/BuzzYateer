#include"Rover.h"
int Rover::COUNT = 0;
Rover::Rover(int speed, bool status, bool underMaintenance, int NoOfCheckUps) :noOfMissions(0), Speed(speed), ID(++COUNT)
{
	setfree(status);
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

void Rover::setCheukDuration(int days)
{
	CheukDuration = days;
}

int Rover::getCheukDuration()
{
	return CheukDuration;
}

int Rover::getID()
{
	return ID;
}

void Rover::setfree(bool s)
{
	status = s;
}

bool Rover::getfree()
{
	return status;
}

void Rover::incrementCheckup()
{
	NoOfCheckUps++;
}

int Rover::getNoOfCheckUps()
{
	return NoOfCheckUps;
}

void Rover::setMaintenance(bool x)
{
	underMaintenance = x;
}

bool Rover::geMaintenance()
{
	return underMaintenance;
}