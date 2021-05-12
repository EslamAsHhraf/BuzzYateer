#pragma once

class Event
{
	int eventDay;
	char eventType;
	int ID;
	char missionType;
public:
	Event();
	Event(char typeOfEvent,int id,char typeOfmission=' ');
	void setID(int id);
	void setmissionType(int MT);
	void seteventDay(int d);
	int geteventDay();
	void setEventType(char  x);
	char getEventType();
	virtual void Execute() = 0;
	int getid();
	char getTypeOfmission();

	//void s();
};

