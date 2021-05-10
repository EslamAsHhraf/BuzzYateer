#include "Mission.h"

Mission::Mission(int F ,int D ,int S ,int TL ,int id, char Status = 'W')
{
	setDuration(D);
	setFormulationDay(F);
	setSignificance(S);
	setTargetLocation(TL);
	setID(id);
	setStatus(Status);
}

void Mission::setFormulationDay(int fDay)
{
	formulationDay = fDay;
}

void Mission::setDuration(int D)
{
	duration = D;
}

void Mission::setSignificance(int S)
{
	significance = S;
}

void Mission::setTargetLocation(int TL)
{
	targetLocation = TL;
}

void Mission::setID(int id)
{
	ID = id;
}

void Mission::setStatus(char Status)
{
	status = Status;
}


int Mission::getFormulationDay() const
{
	return formulationDay;
}

int Mission::getDuration() const
{
	return duration;
}

int Mission::getSignificance() const
{
	return significance;
}

int Mission::getTargetLocation() const
{
	return targetLocation;
}

int Mission::getID() const
{
	return ID;
}

char Mission::getStatus() const
{
	return status;
}

