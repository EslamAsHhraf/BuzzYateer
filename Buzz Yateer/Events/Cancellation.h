#pragma once
#include"Event.h"
class cancellation:public Event {
	int ID;
public:
	cancellation();
	cancellation(int id, int ED);
	void setId(int id);
	int  getID();
	void Execute();


};