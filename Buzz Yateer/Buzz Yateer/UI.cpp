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
		int i;
		InputFile >> i;
		Master->AddEvent(i);
	}
}

void UI::PrintinOutputFile(ofstream& OutputFile)
{

}
