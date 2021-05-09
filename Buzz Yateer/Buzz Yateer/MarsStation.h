#pragma once
#include"Event.h"
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
	Queue<MountainousMission*>MM; 
	UI* UI_PTR;
public:
	MarsStation(string input, string output);
	void OpenInputFile(string inputfile);
	void OpenOutputFile(string outputfile);
	void GetInput(ifstream& Inputfile);
	void GetOutput(ofstream& Outputfile);
	void AddEvent(int i);
	void AddPolarRover(int i);
	void AddEmergencyRover(int i);
	void AddMountainousRover(int i);
	void AddPolarMission(int i);
	void AddEmergencyMission(int i);
	void AddMountainousMission(int i);
	~MarsStation();
};

