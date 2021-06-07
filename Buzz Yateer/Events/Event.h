#pragma once
class MarsStation;
class Event
{
	int ED;                                         //Execution Day
public:
	Event(int ED);
	Event();
	virtual void Execute(MarsStation* Master) = 0;	//excute event
	int getEventDay();								//get event day
	virtual ~Event();
};