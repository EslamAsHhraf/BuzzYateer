#include "UI.h"
#include"Event.h"
#include"Formulation.h"
UI::UI(MarsStation* Master):Master(Master)
{
}

void UI::ReadInputFile(ifstream& InputFile)
{
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
