#pragma once
#include "../Buzz Yateer/MarsStation.h"
#include"Event.h"
class MarsStation;
class cancellation:public Event {
	int ID;
public:
	cancellation();
	cancellation(int id, int ED);
	void setId(int id);
	int  getID();
	void Execute(MarsStation* Master);


};