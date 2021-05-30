#include "UI.h"
#include"../Events/Event.h"
#include"../Events/Formulation.h"
UI::UI(MarsStation* Master):Master(Master)
{
}

void UI::ReadInputFile(ifstream& InputFile)
{
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
	int AutoP, MaxDistance, nOfCheckUp2Maintenence, nOfdays2LeaveMaintenence;
	InputFile >> AutoP >> MaxDistance >> nOfCheckUp2Maintenence >> nOfdays2LeaveMaintenence;
	Master->setMaxDistance(MaxDistance);
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
	OutputFile << "END\n";
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
	cout << "==========================================\n";
}
