#pragma once
#include "../Buzz Yateer/MarsStation.h"
class MarsStation;
#include"Event.h"
#include "../Missions/Mission.h"
class Formulation :public Event {
	char missionType;
	Mission* FormulatedMission;
public:
	Formulation(char MissionType, int ED);
	void setmissionType(char x);		//set Type of Mission to be Formulated
	Mission*& getFormulatedMission();   //get Formulated Mission
	char getmissiontype();				//get Type of Mission to be Formulated
	void setFormulatedMission(int ED = 0, int ID = 0, int TLOC = 0, int MDUR = 0, int SIG = 0); //set Parameters of Mission
	void Execute(MarsStation* Master);	//execute event
	~Formulation();
};