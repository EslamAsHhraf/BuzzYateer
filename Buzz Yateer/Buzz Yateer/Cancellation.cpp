#include "Cancellation.h"

cancellation::cancellation()
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
