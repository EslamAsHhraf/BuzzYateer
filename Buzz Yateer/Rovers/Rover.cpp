#include"Rover.h"
#include<cmath>
int Rover::COUNT = 0;
Rover::Rover(int speed, bool status, bool underMaintenance, int NoOfCheckUps) :noOfMissions(0), Speed(speed), ID(++COUNT),
MaintenenceDuration(0), underMaintenance(0), NoOfCheckUps(0)
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

void Rover::resetnoOfCheckUps()
{
	NoOfCheckUps = 0;
}

void Rover::NoOfCheckUpsIncrement()
{
	NoOfCheckUps++;
}

void Rover::setMaintenenceDuration(int MaintenenceDuration)
{
	this->MaintenenceDuration = MaintenenceDuration;
}

int Rover::getMaintenenceDuration()
{
	return MaintenenceDuration;
}

int Rover::getSpeed()
{
	if (underMaintenance)
		return ceil((double)Speed / 2);
	else
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