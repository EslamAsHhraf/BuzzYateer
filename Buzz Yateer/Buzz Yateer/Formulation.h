#pragma once
#include"Event.h"
class Formulation:public Event {
	char missionType;
	Mission* p;
public:
	Formulation();
	Formulation(char type);
	void setmissionType(char x);
	char getmissionType();
	void Execute();

};