#pragma once
#include"Event.h"
#include"PolarRover.h"
#include"EmergencyRover.h"
#include"MountainousRover.h"
#include"UI.h"
#include"PolarMission.h"
#include"MountainousMission.h"
#include"EmergencyMission.h"
#include<bits/stdc++.h>
using namespace std;
class UI;
class MarsStation
{
	ifstream InputFile;
	ofstream OutputFile;
	queue<Event*>events;
	priority_queue<PolarRover*>PR;
	priority_queue<EmergencyRover*>ER;
	priority_queue<MountainousRover*>MR;
	queue<PolarMission*>PM;
	priority_queue<EmergencyMission*>EM;
	queue<MountainousMission*>MM; 
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

