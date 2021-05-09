#include "MarsStation.h"

MarsStation::MarsStation(string input,string output)
{
	UI_PTR = new UI(this);
	OpenInputFile(input);
	OpenOutputFile(output);
}

void MarsStation::OpenInputFile(string inputfile)
{
	InputFile.open(inputfile);
}

void MarsStation::OpenOutputFile(string outputfile)
{
	InputFile.open(outputfile);
}

void MarsStation::GetInput(ifstream& Inputfile)
{
	UI_PTR->ReadInputFile(InputFile);
}

void MarsStation::GetOutput(ofstream& Outputfile)
{
	UI_PTR->PrintinOutputFile(OutputFile);
}

void MarsStation::AddEvent(int i)
{
	events.enqueue(new Event());
}

void MarsStation::AddPolarRover(int i)
{
	PR.enqueue(new PolarRover(),0);
}

void MarsStation::AddEmergencyRover(int i)
{
	ER.enqueue(new EmergencyRover(),0);
}

void MarsStation::AddMountainousRover(int i)
{
	MR.enqueue(new MountainousRover(),0);
}

void MarsStation::AddPolarMission(int i)
{
	PM.enqueue(new PolarMission());
}

void MarsStation::AddEmergencyMission(int i)
{
	EM.enqueue(new EmergencyMission(),0);
}

void MarsStation::AddMountainousMission(int i)
{
	MM.enqueue(new MountainousMission());
}

MarsStation::~MarsStation()
{
}


