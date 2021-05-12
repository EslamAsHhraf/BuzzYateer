#include "Event.h"
#include "Formulation.h"
#include "cancellation.h"
#include "Promotion.h"
Event::Event()
{

}

Event::Event(char typeOfEvent, int id, char typeOfmission)
{
	setID(id);
	setEventType(typeOfEvent);
	setmissionType(typeOfmission);
}

void Event::setID(int id)
{
	ID = id;
}

void Event::setmissionType(int MT)
{
	missionType = MT;
}



void Event::seteventDay(int d)
{
	eventDay = d;
}

int Event::geteventDay()
{
	return eventDay;
}

void Event::setEventType(char x)
{
	eventType = x;
}

char Event::getEventType()
{
	return eventType;
}

void Event::Execute()
{
}

int Event::getid()
{
	return ID;
}

char Event::getTypeOfmission()
{
	return missionType;
}
// To be done 
/*void Event::s()
{
	Event* currentPointer;
	if (getEventType() == 'F') {
		currentPointer=new Formulation(missionType);
		currentPointer->Execute();
	}
	if (getEventType() == 'X') {
		currentPointer = new cancellation(ID);
		currentPointer->Execute();

	}
	if (getEventType() == 'P') {
		currentPointer = new Promotion(ID);
		currentPointer->Execute();

	}
}*/




