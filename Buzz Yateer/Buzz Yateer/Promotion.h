#pragma once
#include"Event.h"
class Promotion:public Event {
	int ID;
public:
	Promotion();
	Promotion(int id);
	void setId(int id);
	int  getID();
	void Execute();


};