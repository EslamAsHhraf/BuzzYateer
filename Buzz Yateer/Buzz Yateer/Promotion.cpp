#include "Promotion.h"
Promotion::Promotion(int ED ,int id)
{
	setEd(ED);
	setId(id);
	Execute();
}

void Promotion::setEd(int Ed)
{
	ED = Ed;
}

void Promotion::setId(int id)
{
	ID = id;
}

int Promotion::getEd()
{
	return ED;
}

int Promotion::getID()
{
	return ID;
}

void Promotion::Execute()
{
	MS->Promote(ID);
}
