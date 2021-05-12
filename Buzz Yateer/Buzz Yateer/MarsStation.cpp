#include "MarsStation.h"

MarsStation::MarsStation(string input,string output):CountDays(0),Enum(0),Pnum(0),Mnum(0)
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
		Mnum++;
		MM.insert(MM.getLength() + 1, dynamic_cast<MountainousMission*>(F->getFormulatedMission()));
	}
	else if (MissionType == 'P') {
		Pnum++;
		PM.enqueue(dynamic_cast<PolarMission*>(F->getFormulatedMission())); 
	}
	else if (MissionType == 'E') {
		Enum++;
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

void MarsStation::AutoPromote()
{
//	int N = MM.getLength();
	int j = 1;
		while(j<= MM.getLength())
		{
			if (MM.getEntry(j)->getFormulationDay() + AutoP == CountDays)
			{
				MountainousMission *temp = MM.getEntry(j);
				EM.enqueue(new EmergencyMission(temp->getFormulationDay(), temp->getDuration(), temp->getSignificance(), temp->getTargetLocation(), temp->getID()), 0);
				MM.remove(j);
			}
			else
			{
				j++;
			}
		}
	
}

PolarRover * MarsStation::AddExPR()
{
	PolarRover* R;
	if (PR.dequeue(R))
	{
		R++;
		return R;
	}
	return nullptr;
}
EmergencyRover* MarsStation::AddExER()
{
	EmergencyRover* R;
	if (ER.dequeue(R))
	{
		R++;
		return R;
	}
	return nullptr;
}
MountainousRover* MarsStation::AddExMR()
{
	MountainousRover* R;
	if (MR.dequeue(R))
	{
		R++;
		return R;
	}
	return nullptr;
}
void MarsStation::Simulate()
{
	while (true)
	{
		CountDays++;
		// assign missions to rovers
		EmergencyMission* E;
		while (EM.peek(E) && E->getFormulationDay() <= CountDays)
		{
			double duration;
			if (!ER.isEmpty())
			{
				EM.dequeue(E);
				EmergencyRover * R=AddExER();
				duration = ceil(CountDays + E->getMDUR() +E->getTargetLocation()/ ((double)R->getSpeed()));
				E->setExPeriod(duration);
				Execution.enqueue(make_pair(E, R), -duration);
			}
			else if (!MR.isEmpty())
			{
				EM.dequeue(E);
				MountainousRover * R=AddExMR();
				duration = ceil(CountDays + E->getMDUR() + (E->getTargetLocation() / ((double)R->getSpeed())) );
				E->setExPeriod(duration);
				Execution.enqueue(make_pair(E, R), -duration);
			}
			else if (!PR.isEmpty())
			{
				EM.dequeue(E);
				PolarRover * R= AddExPR();
				duration =ceil( CountDays + E->getMDUR() + (E->getTargetLocation() / ((double)R->getSpeed())));
				E->setExPeriod(duration);
				Execution.enqueue(make_pair(E,R), -duration);
			}
		}
		PolarMission* p;
		while (PM.peek(p)&& p->getFormulationDay()== CountDays )
		{
			double duration;
			if (!PR.isEmpty())
			{
				PolarRover * R= AddExPR();
				duration = ceil(CountDays + p->getMDUR() + (p->getTargetLocation() / ((double)R->getSpeed())));
				p->setExPeriod(duration);
				Execution.enqueue(make_pair(p, R), -duration);
			}
		}
		MountainousMission* m;
		while (!MM.isEmpty() &&MM.getEntry(1)->getFormulationDay() == CountDays)
		{
			double duration;
			m = MM.getEntry(1);
			if (!MR.isEmpty())
			{
				MM.remove(1);
				MountainousRover * R = AddExMR();
				duration =ceil( CountDays + m->getMDUR() + (m->getTargetLocation() / ((double)R->getSpeed())));
				m->setExPeriod(duration);
				Execution.enqueue(make_pair(m, R), -duration);
		    }
			else if (!ER.isEmpty())
			{
				MM.remove(1);
				EmergencyRover * R = AddExER();
				duration = ceil(CountDays + m->getMDUR() + m->getTargetLocation() / ((double)R->getSpeed()));
				m->setExPeriod(duration);
				Execution.enqueue(make_pair(m, R), -duration);
			}
		}
		//simulate Execution
		pair<Mission*, Rover*> Ex;
		while (Execution.peek(Ex)&& Ex.first->getExPeriod()== CountDays)
		{
			 Execution.dequeue(Ex);
			 if (dynamic_cast<EmergencyMission*>(Ex.first))
			 {
				 CM.enqueue(dynamic_cast<EmergencyMission*>(Ex.first));
			 }
			 else if (dynamic_cast<MountainousMission*>(Ex.first))
			 {
				 CM.enqueue(dynamic_cast<MountainousMission*>(Ex.first));
			 }
			 else if (dynamic_cast<PolarMission*>(Ex.first))
			 {
				 CM.enqueue(dynamic_cast<PolarMission*>(Ex.first));
			 }
			 /////////////////////
			 if (dynamic_cast<EmergencyRover*>(Ex.second))
			 {
				 EmergencyRover*E = dynamic_cast<EmergencyRover*>(Ex.second);
				 if (E->getnoOfMissions() == NMission2CheckUp)
				 {
					 CheukUp.enqueue(E, -(CountDays + ECheckUp));
					 E->resetnoOfMissions();
				 }
				 else
				 {
					 ER.enqueue(E, E->getSpeed());
				 }
		     }
			 else if (dynamic_cast<MountainousRover*>(Ex.second))
			 {
				 MountainousRover*M= dynamic_cast<MountainousRover*>(Ex.second);
				 if (M->getnoOfMissions() == NMission2CheckUp)
				 {
					 CheukUp.enqueue(M, -(CountDays + MCheckUp));
					 M->resetnoOfMissions();
				 }
				 else
				 {
					 MR.enqueue(M, M->getSpeed());
				 }
			 }
			 else if (dynamic_cast<PolarRover*>(Ex.second))
			 {
				 PolarRover* p = dynamic_cast<PolarRover*>(Ex.second);
				 if (p->getnoOfMissions() == NMission2CheckUp)
				 {
					 CheukUp.enqueue(p, -(CountDays + PCheckUp));
					 p->resetnoOfMissions();
				 }
				 else
				 {
					 PR.enqueue(p, p->getSpeed());
				 }
			 }
		}
		//Auto promotion
		AutoPromote();
		//if all mission are complete
		if (CM.GetLength() == Mnum + Pnum + Enum)
		{
			break;

		}
	}
}
MarsStation::~MarsStation()
{
}
