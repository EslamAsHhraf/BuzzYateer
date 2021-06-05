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
	int MCheckUp;// num days needed for Mountainous rovers 
	int PCheckUp;// num days needed for polar rovers
	int ECheckUp;// num days needed for Emergency rovers
	int NMission2CheckUp;
	int AutoP;// num days needed to make auto prmote  
	double Ap;//num missions which  prmote
	UI* UI_PTR;
	int CountDays;// count of days
	int Mnum;//num of Mountainous missions 
	int Enum;//num of emergency missions
	int Pnum;//num of polar missions
	int EventCount;
	int MaxPeriod;
	int nOfCheckUp2Maintenence;
	int nOfdays2LeaveMaintenence;
	string FailedMissions;
	int NM;//num of Mountainous rovers 
    int	NP; //num of polar rovers 
	int NE;//num of emergency rovers
	int NumMDE;//num of Mountainous mision can't done
	int	NumPDE; //num of polar mission can't done
	int NumEDE;//num of emergency mission can't done
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
	void Promote(int ID);// prmote Mountainous mission 
	void AutoPromote();// auto prmote Mountainous missions
	int CountRovers(int& Er, int& Mr, int& Pr);
	void failMission();
	void roverMaintance(Rover* r);
	void Simulate();// simulte all function needed every day
	void setMaxPeriod(int MaxPeriod);
	void DailyEvent();
	void CheukupSim();//check if the Cheukup done 
	void assigEM();// assign Emergency missions
	void assigPM();// assign Polar missions
	void assigMM();// assign Mountainous missions
	void ExecutionSim();// check if the Execution done 
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
	void ReadInputFile();
	void PrintinOutputFile();
	bool CanDoEM();//if can do Emergency missions or not 
	bool CanDoMM();//if can do Mountainous missions or not 
	bool CanDoPM();//if can do Polar missions or not 
	void IncreaseNumMDE();
	void IncreaseNumPDE();
	void IncreaseNumEDE();
	~MarsStation();
};

