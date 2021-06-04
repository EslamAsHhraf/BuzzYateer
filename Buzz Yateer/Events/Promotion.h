#pragma once
#include "../Buzz Yateer/MarsStation.h"
class MarsStation;
#include"Event.h"
class Promotion:public Event {
	int ID;
public:
	Promotion(int ED ,int id);
	void setId(int id);
	int  getID();
	void Execute(MarsStation* Master);
	~Promotion();
};