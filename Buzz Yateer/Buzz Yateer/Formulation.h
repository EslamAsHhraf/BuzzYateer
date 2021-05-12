#pragma once
#include"Event.h"
#include "Mission.h"
class Formulation:public Event {
	char missionType;
	Mission* FormulatedMission;
public:
	Formulation(char MissionType);
	void setmissionType(char x);
	Mission*& getFormulatedMission();
	void setFormulatedMission(int ED = 0, int ID = 0, int TLOC = 0, int MDUR = 0, int SIG = 0);
	void Execute();

};