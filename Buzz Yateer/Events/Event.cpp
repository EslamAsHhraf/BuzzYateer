#include "Event.h"
Event::Event(int ED) :ED(ED)
{
}

Event::Event() : ED(0)
{
}

int Event::getEventDay()
{
	return ED;
}
