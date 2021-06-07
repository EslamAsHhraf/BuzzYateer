#pragma once
#include "../Buzz Yateer/MarsStation.h"
class MarsStation;
#include"Event.h"
#include "../Missions/Mission.h"
class Formulation:public Event {
	char missionType;
	Mission* FormulatedMission;
public:
	Formulation(char MissionType,int ED);
	void setmissionType(char x);
	Mission*& getFormulatedMission();
	char getmissiontype();
	void setFormulatedMission(int ED = 0, int ID = 0, int TLOC = 0, int MDUR = 0, int SIG = 0);
	void Execute(MarsStation* Master);//excute event
	~Formulation();
};