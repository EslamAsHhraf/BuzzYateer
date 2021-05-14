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
#include"../DS/Pair.h"
#include"../Events/Cancellation.h"
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
	Queue<Mission*>CM;
	priority_Queue<Rover*>CheukUp;
	priority_Queue<Pair<Mission*, Rover*>>Execution;
	int MCheckUp;
	int PCheckUp;
	int ECheckUp;
	int NMission2CheckUp;
	int AutoP;
	UI* UI_PTR;
	int CountDays;
	int Mnum;
	int Enum;
	int Pnum;
	int EventCount;
	int MaxDistance;
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
	void AddCancellation(int ID, int ED);
	void Promote(int ID);
	void AutoPromote();
	void failMission();
	void roverMaintance(Rover* r);
	void Simulate();
	~MarsStation();
	void setMaxDistance(int MaxDistance);
	void CheukupSim();
	void assigEM();
	void assigPM();
	void assigMM();
	void ExecutionSim();
};

