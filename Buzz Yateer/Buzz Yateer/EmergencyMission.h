#pragma once
#include "Mission.h"
class EmergencyMission:public Mission
{
public:
	EmergencyMission() {};
	EmergencyMission(int F ,int D ,int S ,int TL ,int id ,char Status);
	int calcPriority();
};

