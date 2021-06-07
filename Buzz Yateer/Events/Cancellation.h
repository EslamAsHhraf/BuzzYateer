#pragma once
#include "../Buzz Yateer/MarsStation.h"
#include"Event.h"
class MarsStation;
class cancellation :public Event {
	int ID;
public:
	cancellation();
	cancellation(int id, int ED);
	void setId(int id);					//set Id of Mission to be Canceled
	int  getID();						//get Id of Mission to be Canceled
	void Execute(MarsStation* Master);	//excute event
	~cancellation();
};