#pragma once
#include "../Buzz Yateer/MarsStation.h"
#include"../Events/Event.h"
class MarsStation;
class Promotion:public Event {
	int ID;
	int ED;
	MarsStation *MS;
public:
	Promotion(int ED ,int id);
	void setEd(int Ed);
	void setId(int id);
	int getEd();
	int  getID();
	void Execute();


};