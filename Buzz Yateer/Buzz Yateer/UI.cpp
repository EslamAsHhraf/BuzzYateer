#include "UI.h"
#include"../Events/Event.h"
#include"../Events/Formulation.h"
#include <iostream>
UI::UI(MarsStation* Master) :Master(Master)
{
}

void UI::Interactive_Mode()
{
	cout << "Current Day: " << Master->getDay() << endl;
	Pair<int, string>p = Master->PrintWaitingMission();
	cout << p.first << " Waiting Missions: " << p.second << endl;
	p = Master->PrintExecetion();
	cout << p.first << " In-Execution Missions/Rovers: " << p.second << endl;
	p = Master->Printavailable();
	cout << p.first << " Available Rovers: " << p.second << endl;
	p = Master->PrintCheukUp();
	cout << p.first << " In-Checkup Rovers: " << p.second << endl;
	p = Master->PrintCompleted();
	cout << p.first << " Completed Missions: " << p.second << endl;
	p = Master->PrintMaintenece();
	cout << p.first << " In-Maintenece Rovers: " << p.second << endl;
	if (Master->FailedMissionsPrint().size() != 0)
	{
		cout << "\a\a\a\aMission Failed Today : " << Master->FailedMissionsPrint() << endl;
		Master->resetFailedMission();
	}
	cout << "==========================================\n";
}

void UI::Mode_1()
{
	cin.get();
	Interactive_Mode();
}

void UI::Mode_2()
{
	Sleep(1000);
	Interactive_Mode();

}

void UI::Mode_3()
{
	cout << "Silent Mode" << endl;
	cout << "Simulation Starts..." << endl;
	cout << "Simulation ends, Output file created" << endl;
}

void UI::decide(int& x)
{
	if (x == 1)
		Mode_1();
	else if (x == 2)
		Mode_2();
	else if (x == 3) 
	{
		Mode_3();
		x = -1;
	}
}
