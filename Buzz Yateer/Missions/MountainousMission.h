#pragma once
#include "Mission.h"
class MountainousMission:public Mission
{
public:
	MountainousMission();
	MountainousMission(int F, int D, int S, int TL, int id);
	~MountainousMission();
};

