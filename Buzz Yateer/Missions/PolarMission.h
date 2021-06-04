#pragma once
#include "Mission.h"
class PolarMission:public Mission
{
public:
	PolarMission();
	PolarMission(int F, int D, int S, int TL, int id);
	~PolarMission();
};