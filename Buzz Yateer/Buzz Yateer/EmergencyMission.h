#pragma once
#include "Mission.h"
#include"EmergencyRover.h"
class EmergencyMission:public Mission
{
	
 EmergencyRover * p;
public:
	EmergencyMission() ;
	EmergencyMission(int F ,int D ,int S ,int TL ,int id ,char Status);
	int calcPriority();
	//from assignment day
	int calcduration();
};

