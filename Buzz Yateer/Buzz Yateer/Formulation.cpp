#include"Formulation.h"
#include"Event.h"
#include"Mission.h"
#include"EmergencyMission.h"
#include"MountainousMission.h"
#include"PolarMission.h"
Formulation::Formulation() :missionType('0')
{
	Execute();
	setFormulatedMission(0);
}
Formulation::Formulation(char MissionType, int ED, int ID, int TLOC, int MDUR, int SIG) : missionType(MissionType)
{
	Execute();
	setFormulatedMission(ED, ID, TLOC, MDUR, SIG);
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
		FormulatedMission = new MountainousMission;
	}
	else if (missionType == 'P') {
		FormulatedMission = new PolarMission;
	}
	else if (missionType == 'E') {
		FormulatedMission = new EmergencyMission;
	}
}
