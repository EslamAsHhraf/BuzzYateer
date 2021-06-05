#include"Formulation.h"
#include"Event.h"
#include"../Missions/Mission.h"
#include"../Missions/EmergencyMission.h"
#include"../Missions/MountainousMission.h"
#include"../Missions/PolarMission.h"

Formulation::Formulation(char MissionType, int ED) : missionType(MissionType), Event(ED)
{
	FormulatedMission = new Mission();
}

void Formulation::setmissionType(char x)
{
	missionType = x;
}

Mission*& Formulation::getFormulatedMission()
{
	return FormulatedMission;
}

char Formulation::getmissiontype()
{
	return missionType;
}

void Formulation::setFormulatedMission(int ED, int ID, int TLOC, int MDUR, int SIG)
{
	FormulatedMission->setFormulationDay(ED);
	FormulatedMission->setMDUR(MDUR); //temporary 
	FormulatedMission->setSignificance(SIG);
	FormulatedMission->setTargetLocation(TLOC);
	FormulatedMission->setID(ID);
}

void Formulation::Execute(MarsStation* Master)
{
	Mission* M = FormulatedMission;
	if (missionType == 'M')
	{
		if (Master->CanDoMM())
		{
			FormulatedMission = new MountainousMission(*(MountainousMission*)M);
			Master->Add2MM(dynamic_cast<MountainousMission*>(FormulatedMission));
		}
		else
		{
			Master->IncreaseNumMDE();
		}
	}
	else if (missionType == 'P')
	{
		if (Master->CanDoPM())
		{
			FormulatedMission = new PolarMission(*(PolarMission*)M);
			Master->Add2PM(dynamic_cast<PolarMission*>(FormulatedMission));
		}
		else
		{
			Master->IncreaseNumPDE();
		}
	}
	else if (missionType == 'E')
	{
		if (Master->CanDoEM())
		{
			FormulatedMission = new EmergencyMission(*(EmergencyMission*)(M));
			Master->Add2EM(dynamic_cast<EmergencyMission*>(FormulatedMission));
		}
		else
		{
			Master->IncreaseNumEDE();
		}
	}
	delete M;
}

Formulation::~Formulation()
{
}
