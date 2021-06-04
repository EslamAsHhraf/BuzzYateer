#include "Promotion.h"
Promotion::Promotion(int ED, int id) :Event(ED)
{
	setId(id);
	//Execute();
}

void Promotion::setId(int id)
{
	ID = id;
}

int Promotion::getID()
{
	return ID;
}

void Promotion::Execute(MarsStation* Master)
{
	Master->Promote(ID);
}

Promotion::~Promotion()
{
}
