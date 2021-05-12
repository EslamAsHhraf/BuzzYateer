#include "MarsStation.h"

MarsStation::MarsStation(string input,string output)
{
	UI_PTR = new UI(this);
	OpenInputFile(input);
	OpenOutputFile(output);
}

void MarsStation::setCheckUpData(int MCheckUp, int PCheckUp, int ECheckUp, int NMission2CheckUp)
{
	this->MCheckUp = MCheckUp;
	this->PCheckUp = PCheckUp;
	this->ECheckUp = ECheckUp;
	this->NMission2CheckUp = NMission2CheckUp;
}

void MarsStation::setAutoPromotion(int AutoP)
{
	this->AutoP = AutoP;
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

void MarsStation::AddFormulationEvent(char MissionType, int ED, int ID, int TLOC, int MDUR, int SIG)
{
	Formulation* F = new Formulation(MissionType);
	F->Execute();
	F->setFormulatedMission(ED, ID, TLOC, MDUR, SIG);
	events.enqueue(F);
	if (MissionType == 'M') {
		MM.insert(MM.getLength() + 1, dynamic_cast<MountainousMission*>(F->getFormulatedMission()));
	}
	else if (MissionType == 'P') {
		PM.enqueue(dynamic_cast<PolarMission*>(F->getFormulatedMission())); 
	}
	else if (MissionType == 'E') {
		EM.enqueue(dynamic_cast<EmergencyMission*>(F->getFormulatedMission()), 0);//tempporary
	}
}

void MarsStation::AddPromotionEvent(int ED ,int ID)
{
	Promotion *P = new Promotion(ED ,ID);
	events.enqueue(P);
}

void MarsStation::AddPolarRover(int speed)
{
	PR.enqueue(new PolarRover(speed), speed);
}

void MarsStation::AddEmergencyRover(int speed)
{
	ER.enqueue(new EmergencyRover(speed),speed);
}

void MarsStation::AddMountainousRover(int speed)
{
	MR.enqueue(new MountainousRover(speed), speed);
}

bool MarsStation::CancelMission(int ID)
{
	int n = MM.getLength();
	for (int i = 1; i <= n; i++)
	{
		if (MM.getEntry(i)->getID() == ID)
		{
			MM.remove(i);
			return 1;
		}
	}
	return 0;
}

void MarsStation::Promote(int ID)
{
	int N = MM.getLength();
	for (int i = 1; i <= N; i++)
	{
		if (MM.getEntry(i)->getID() == ID)
		{
			MountainousMission *temp = MM.getEntry(i);
			EM.enqueue(new EmergencyMission(temp->getFormulationDay() ,temp->getDuration() ,temp->getSignificance() ,temp->getTargetLocation() ,temp->getID()) ,0);
			MM.remove(i);
		}
	}
}

void MarsStation::AutoPromote(int AutoP)
{
	int N = MM.getLength();
	for (int currentDay = AutoP; currentDay < 100; currentDay++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (MM.getEntry(j)->getFormulationDay() + AutoP == currentDay)
			{
				Promote(MM.getEntry(j)->getID());
			}
		}
	}
}
MarsStation::~MarsStation()
{
}


