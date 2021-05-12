#include "UI.h"
#include"../Events/Event.h"
#include"../Events/Formulation.h"
UI::UI(MarsStation* Master):Master(Master)
{
}

void UI::ReadInputFile(ifstream& InputFile)
{
	int NM, NP, NE, NOFM, MCD, PCD, ECD;
	InputFile >> NM >> NP >> NE >> NOFM >> MCD >> PCD >> ECD;
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
	int AutoP;
	InputFile >> AutoP;
	//For Promotion
	while (!InputFile.eof())
	{
		int NumberOfEvents = 0;
		InputFile >> NumberOfEvents;
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
				Master->CancelMission(ID);
			}
			else
			{

			}
		}
	}
}

void UI::PrintinOutputFile(ofstream& OutputFile)
{

}
