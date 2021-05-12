#include"Formulation.h"
#include"Event.h"
#include"../Missions/Mission.h"
#include"../Missions/EmergencyMission.h"
#include"../Missions/MountainousMission.h"
#include"../Missions/PolarMission.h"
Formulation::Formulation(char MissionType) : missionType(MissionType), FormulatedMission(0)
{
}

void Formulation::setmissionType(char x)
{
	missionType = x;
}

Mission*& Formulation::getFormulatedMission()
{
	return FormulatedMission;
}

void Formulation::setFormulatedMission(int ED, int ID, int TLOC, int MDUR, int SIG)
{
	FormulatedMission->setFormulationDay(ED);
	FormulatedMission->setDuration(MDUR); //temporary 
	FormulatedMission->setSignificance(SIG);
	FormulatedMission->setTargetLocation(TLOC);
	FormulatedMission->setID(ID);
}

void Formulation::Execute()
{
	if (missionType == 'M') {
		FormulatedMission = new MountainousMission();
	}
	else if (missionType == 'P') {
		FormulatedMission = new PolarMission();
	}
	else if (missionType == 'E') {
		FormulatedMission = new EmergencyMission();
	}
}
