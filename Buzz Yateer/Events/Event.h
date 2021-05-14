#pragma once
class Event
{
	int ED;
public:
	Event(int ED);
	Event();
	virtual void Execute() = 0;
	int getEventDay();
};

