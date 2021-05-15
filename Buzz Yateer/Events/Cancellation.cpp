#include "Cancellation.h"

cancellation::cancellation() :ID(0), Event(0)
{
}

cancellation::cancellation(int id,int ED): Event(ED)
{
	setId(id);
}

void cancellation::setId(int id)
{
	ID = id;
}

int cancellation::getID()
{
	return ID;
}

void cancellation::Execute(MarsStation* Master)
{
	Master->CancelMission(ID);
}
