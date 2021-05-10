#pragma once
#include "Mission.h"

class MountainousMission:public Mission
{
	int autoP;
public:
	MountainousMission() {};
	MountainousMission(int F ,int D ,int S ,int TL ,int id ,char Status , int AP);
};

