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
	events.push(new Event());
}

void MarsStation::AddPolarRover(int i)
{
	PR.push(new PolarRover());
}

void MarsStation::AddEmergencyRover(int i)
{
	ER.push(new EmergencyRover());
}

void MarsStation::AddMountainousRover(int i)
{
	MR.push(new MountainousRover());
}

void MarsStation::AddPolarMission(int i)
{
	PM.push(new PolarMission());
}

void MarsStation::AddEmergencyMission(int i)
{
	EM.push(new EmergencyMission());
}

void MarsStation::AddMountainousMission(int i)
{
	MM.push(new MountainousMission());
}

MarsStation::~MarsStation()
{
}


