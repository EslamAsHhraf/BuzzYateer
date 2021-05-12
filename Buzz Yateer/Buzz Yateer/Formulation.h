#pragma once
#include"Event.h"
#include "Mission.h"
class Formulation:public Event {
	char missionType;
	Mission* FormulatedMission;
public:
	Formulation();
	Formulation(char MissionType, int ED, int ID, int TLOC, int MDUR, int SIG);
	void setmissionType(char x);
	Mission*& getFormulatedMission();
	void setFormulatedMission(int ED = 0, int ID = 0, int TLOC = 0, int MDUR = 0, int SIG = 0);
	void Execute();

};