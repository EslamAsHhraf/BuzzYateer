#include "Cancellation.h"

cancellation::cancellation() :ID(0)
{
}

cancellation::cancellation(int id)
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

void cancellation::Execute()
{

}
