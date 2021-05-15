#include "Promotion.h"
Promotion::Promotion(int ED, int id) :Event(ED)
{
	setId(id);
	Execute();
}

void Promotion::setId(int id)
{
	ID = id;
}

int Promotion::getID()
{
	return ID;
}

void Promotion::setMaster(MarsStation* MS)
{
	this->MS = MS;
}

void Promotion::Execute()
{
	MS->Promote(ID);
}
