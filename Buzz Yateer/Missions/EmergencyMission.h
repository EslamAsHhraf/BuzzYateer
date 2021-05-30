#pragma once
#include "Mission.h"
#include "../Rovers/EmergencyRover.h"
class EmergencyMission:public Mission
{
public: 
	EmergencyMission();
	EmergencyMission(int F, int D, int S, int TL, int id);
	int calcPriority();
	//from assignment day
	int calcduration();
};

