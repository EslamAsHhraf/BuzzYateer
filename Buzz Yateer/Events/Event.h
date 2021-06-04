#pragma once
class MarsStation;
class Event
{
	int ED;
public:
	Event(int ED);
	Event();
	virtual void Execute(MarsStation* Master) = 0;
	int getEventDay();
	virtual ~Event();
};

