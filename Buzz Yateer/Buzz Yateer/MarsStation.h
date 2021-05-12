#pragma once
#include"../Events/Event.h"
#include "../Events/Formulation.h"
#include "../Events/Promotion.h"
#include"../Rovers/PolarRover.h"
#include"../Rovers/EmergencyRover.h"
#include"../Rovers/MountainousRover.h"
#include"UI.h"

#include"../Missions/PolarMission.h"
#include"../Missions/MountainousMission.h"
#include"../Missions/EmergencyMission.h"
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
	priority_Queue<Mission*>ExM;
	priority_Queue<Rover*>ExR;
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
	void AddExPM();
	void AddExEM();
	void AddExMM();
	void AddExPR(int days);
	void AddExER(int days);
	void AddExMR(int days);

	~MarsStation();
};

