#include"Formulation.h"
#include"Event.h"
#include"Mission.h"

#include"EmergencyMission.h"
#include"MountainousMission.h"
#include"PolarMission.h"
void Formulation::setmissionType(char x)
{
	missionType = x;
}

char Formulation::getmissionType()
{
	return missionType;
}

void Formulation::Execute()
{
	if (getmissionType() == 'M') {
		p = new MountainousMission;
	}
	if (getmissionType() == 'P') {
		p = new PolarMission;
	}
	if (getmissionType() == 'E') {
		p = new EmergencyMission;
	}
}
