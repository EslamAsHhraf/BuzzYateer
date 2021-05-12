#pragma once
#include"Event.h"
#include "Formulation.h"
#include "Promotion.h"
#include"PolarRover.h"
#include"EmergencyRover.h"
#include"MountainousRover.h"
#include"UI.h"
#include"PolarMission.h"
#include"MountainousMission.h"
#include"EmergencyMission.h"
#include"../DS/LinkedList.h"
#include"../DS/priority_queue.h"
#include"../DS/Queue.h"
#include<bits/stdc++.h>
using namespace std;
class UI;
class MarsStation
{
	ifstream InputFile;
	ofstream OutputFile;
	Queue<Event*>events;
	priority_Queue<PolarRover*>PR;
	priority_Queue<EmergencyRover*>ER;
	priority_Queue<MountainousRover*>MR;
	Queue<PolarMission*>PM;
	priority_Queue<EmergencyMission*>EM;
	LinkedList<MountainousMission*>MM;
	int MCheckUp;
	int PCheckUp;
	int ECheckUp;
	int NMission2CheckUp;
	int AutoP;
	UI* UI_PTR;
public:
	MarsStation(string input, string output);
	void setCheckUpData(int MCheckUp, int PCheckUp, int ECheckUp, int NMission2CheckUp);
	void setAutoPromotion(int AutoP);
	void OpenInputFile(string inputfile);
	void OpenOutputFile(string outputfile);
	void GetInput(ifstream& Inputfile);
	void GetOutput(ofstream& Outputfile);
	void AddFormulationEvent(char MissionType, int ED, int ID, int TLOC, int MDUR, int SIG);
	void AddPromotionEvent(int ED ,int ID);
	void AddPolarRover(int speed);
	void AddEmergencyRover(int speed);
	void AddMountainousRover(int speed);
	bool CancelMission(int ID);
	void Promote(int ID);
	void AutoPromote(int AutoP);
	~MarsStation();
};

