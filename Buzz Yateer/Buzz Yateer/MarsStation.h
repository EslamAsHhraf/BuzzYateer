#pragma once
#include "../Events/Event.h"
#include "../Events/Formulation.h"
#include "../Events/Promotion.h"
#include"../Events/Cancellation.h"
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
#include <bits/stdc++.h>
using namespace std;
class Event;
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
	priority_Queue<Rover*>Maintenence;
	int Mode;
	int MCheckUp;
	int PCheckUp;
	int ECheckUp;
	int NMission2CheckUp;
	int AutoP;
	double Ap;
	UI* UI_PTR;
	int CountDays;
	int Mnum;
	int Enum;
	int Pnum;
	int EventCount;
	int MaxPeriod;
	double Num_MM;
	int nOfCheckUp2Maintenence;
	int nOfdays2LeaveMaintenence;
	string FailedMissions;
public:
	MarsStation(string input, string output);
	void setCheckUpData(int MCheckUp, int PCheckUp, int ECheckUp, int NMission2CheckUp);
	void Add2Maintenence(Rover* R);
	void RemoveFromMaintenence(bool Force = 0);
	void setMaintenenceData(int nOfCheckUp2Maintenence, int nOfdays2LeaveMaintenence);
	void Add2MM(MountainousMission* M);
	void Add2PM(PolarMission* P);
	void Add2EM(EmergencyMission* E);
	void setAutoPromotion(int AutoP);
	void OpenInputFile(string inputfile);
	void OpenOutputFile(string outputfile);
	void AddFormulationEvent(char MissionType, int ED, int ID, int TLOC, int MDUR, int SIG);
	void AddPromotionEvent(int ED ,int ID);
	void AddCanellationEvent(int ED, int ID);
	void AddPolarRover(double speed);
	void AddEmergencyRover(double speed);
	void AddMountainousRover(double speed);
	bool CancelMission(int ID);
	void AddCancellation(int ID, int ED);
	void Promote(int ID);
	void AutoPromote();
	int CountRovers(int& Er, int& Mr, int& Pr);
	void failMission();
	void roverMaintance(Rover* r);
	void Simulate();
	void setMaxPeriod(int MaxPeriod);
	void DailyEvent();
	void CheukupSim();
	void assigEM();
	void assigPM();
	void assigMM();
	void ExecutionSim();
	Pair<int, string> PrintWaitingMission();
	Pair<int, string> PrintExecetion();
	Pair<int, string>Printavailable();
	Pair<int, string> PrintCompleted();
	Pair<int, string> PrintCheukUp();
	Pair<int, string> PrintMaintenece();
	void PrintCompletedInfo(int& CD, int& ID, int& FD, int& ED, int& WD, int& em, int& pm, int& mm, double&Ap);
	int getDay();
	int getCompletedLength();
	int Choose_Mode();
	void Set_Mode(int x);
	string FailedMissionsPrint();
	void resetFailedMission();
	~MarsStation();
	void ReadInputFile();
	void PrintinOutputFile();

};

