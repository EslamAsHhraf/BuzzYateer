#pragma once
#include "../Buzz Yateer/MarsStation.h"
#include"../Events/Event.h"
class MarsStation;
class Promotion:public Event {
	int ID;
	MarsStation *MS;
public:
	Promotion(int ED ,int id);
	void setId(int id);
	int  getID();
	void Execute();


};