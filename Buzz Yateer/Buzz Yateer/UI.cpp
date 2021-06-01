#include "UI.h"
#include"../Events/Event.h"
#include"../Events/Formulation.h"
#include <iostream>
UI::UI(MarsStation* Master) :Master(Master)
{
}

void UI::ReadInputFile(ifstream& InputFile)
{
	int Mode;
	InputFile >> Mode;
	Master->Set_Mode(Mode);
	int NM, NP, NE, NOFM, MCD, PCD, ECD;
	InputFile >> NM >> NP >> NE >> MCD >> PCD >> ECD >> NOFM;
	Master->setCheckUpData(MCD, PCD, ECD, NOFM);
	while (NM--)
	{
		int MS;
		InputFile >> MS;
		Master->AddMountainousRover(MS);
	}
	while (NP--)
	{
		int PS;
		InputFile >> PS;
		Master->AddPolarRover(PS);
	}
	while (NE--)
	{
		int ES;
		InputFile >> ES;
		Master->AddEmergencyRover(ES);
	}
	int AutoP, MaxPeriod, nOfCheckUp2Maintenence, nOfdays2LeaveMaintenence;
	InputFile >> AutoP >> MaxPeriod >> nOfCheckUp2Maintenence >> nOfdays2LeaveMaintenence;
	Master->setMaxPeriod(MaxPeriod);
	Master->setAutoPromotion(AutoP);
	Master->setMaintenenceData(nOfCheckUp2Maintenence, nOfdays2LeaveMaintenence);
	int NumberOfEvents = 0;
	InputFile >> NumberOfEvents;
	//For Promotion
	while (!InputFile.eof())
	{

		while (NumberOfEvents--)
		{
			char Event;
			InputFile >> Event;
			if (Event == 'F')
			{
				char MissionType;
				int ED, ID, TLOC, MDUR, SIG;
				InputFile >> MissionType >> ED >> ID >> TLOC >> MDUR >> SIG;
				Master->AddFormulationEvent(MissionType, ED, ID, TLOC, MDUR, SIG);
			}
			else if (Event == 'X')
			{
				int ED, ID;
				InputFile >> ED >> ID;
				Master->AddCancellation(ID, ED);
			}
			else if ((Event == 'P'))
			{
				int ED, ID;
				InputFile >> ED >> ID;
				Master->AddPromotionEvent(ED, ID);
			}
		}
	}
}

void UI::PrintinOutputFile(ofstream& OutputFile)
{
	double Ap = 0;
	double SumWait = 0, SumExec = 0;
	int CD, ID, FD, WD, ED, Mm, Em, Pm, TotalMission, Er = 0, Mr = 0, Pr = 0, TotalRover;
	Pm = Mm = Em = 0;
	TotalMission = Master->getCompletedLength();
	OutputFile << "CD" << " " << "ID" << " " << "FD" << " " << "WD" << " " << "ED" << " " << endl;
	for (int i = 0; i < TotalMission; i++)
	{
		Master->PrintCompletedInfo(CD, ID, FD, ED, WD, Em, Pm, Mm, Ap);
		SumWait += WD;
		SumExec += ED;
		OutputFile << CD << "  " << ID << "  " << FD << "  " << WD << "  " << ED << " " << endl;

	}
	TotalRover = Master->CountRovers(Er, Mr, Pr);
	OutputFile << endl;
	OutputFile << ".....................\n";
	OutputFile << endl;
	OutputFile << ".....................\n";
	OutputFile << "Missions: " << TotalMission << "[" << "M: " << Mm << "," << "P: " << Pm << "," << "E: " << Em << "]" << endl;
	OutputFile << "Rovers: " << TotalRover << "[" << "M: " << Mr << "," << "P: " << Pr << "," << "E: " << Er << "]" << endl;
	OutputFile << "Avg Wait = " << SumWait / TotalMission << ", " << "Avg Exec = " << SumExec / TotalMission << "\n";
	OutputFile << "Auto-promoted: " << (Ap / TotalMission) * 100;

	OutputFile.close();
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
		cout << "Mission Failed Today : " << Master->FailedMissionsPrint() << endl;
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
	if (x == 2)
		Mode_2();
	if (x == 3) {
		Mode_3();
		x = -1;
	}
}
