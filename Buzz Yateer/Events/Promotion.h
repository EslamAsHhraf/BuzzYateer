#pragma once
#include "../Buzz Yateer/MarsStation.h"
class MarsStation;
#include"Event.h"
class Promotion :public Event {
	int ID;
public:
	Promotion(int ED, int id);
	void setId(int id);					//set Id of Mission to be Canceled
	int  getID();						//get Id of Mission to be Canceled
	void Execute(MarsStation* Master);	//excute event
	~Promotion();
};