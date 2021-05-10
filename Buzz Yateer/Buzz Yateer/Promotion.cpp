#include "Promotion.h"

Promotion::Promotion()
{
}

Promotion::Promotion(int id)
{
	setId(id);
}

void Promotion::setId(int id)
{
	ID = id;
}

int Promotion::getID()
{
	return ID;
}

void Promotion::Execute()
{
}
