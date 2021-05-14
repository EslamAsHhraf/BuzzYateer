#include "MarsStation.h"

MarsStation::MarsStation(string input, string output) :CountDays(0), Enum(0), Pnum(0), Mnum(0), EventCount(0)
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
	Formulation* F = new Formulation(MissionType, ED);
	F->Execute();
	F->setFormulatedMission(ED, ID, TLOC, MDUR, SIG);
	events.enqueue(F);
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

void MarsStation::AddCancellation(int ID, int ED)
{
	cancellation* c = new cancellation(ID, ED);
	events.enqueue(c);
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
		for (int j = 1; j <= MM.getLength(); j++)
		{
			if (MM.getEntry(j)->getFormulationDay() + AutoP == CountDays)
			{
				MountainousMission* temp = MM.getEntry(j);
				EM.enqueue(new EmergencyMission(temp->getFormulationDay(), temp->getDuration(), temp->getSignificance(), temp->getTargetLocation(), temp->getID()), 0);
				MM.remove(j);
				j--;
			}
		}
}


void MarsStation::Simulate()
{
	while (!events.isEmpty() || !Execution.isEmpty() || !EM.isEmpty() || !PM.isEmpty() || !MM.isEmpty())
	{
		CountDays++;
		// Read Events 
		Event* Ev;
		while(events.peek(Ev) && Ev->getEventDay() == CountDays)
		{
			events.dequeue(Ev);
			if (dynamic_cast<Formulation*>(Ev))
			{
				Formulation* F = dynamic_cast<Formulation*>(Ev);
				if (F->getmissiontype() == 'M') {
					Mnum++;
					MM.insert(MM.getLength() + 1, dynamic_cast<MountainousMission*>(F->getFormulatedMission()));
				}
				else if (F->getmissiontype() == 'P') {
					Pnum++;
					PM.enqueue(dynamic_cast<PolarMission*>(F->getFormulatedMission()));
				}
				else if (F->getmissiontype() == 'E') {
					Enum++;
					EmergencyMission* EMER = dynamic_cast<EmergencyMission*>(F->getFormulatedMission());
					EM.enqueue(EMER, EMER->calcPriority());
				}
			}
			else if (dynamic_cast<cancellation*>(Ev))
			{
				cancellation* C = dynamic_cast<cancellation*>(Ev);
				int ID = C->getID();
				CancelMission(ID);
			}
			else if (dynamic_cast<Promotion*>(Ev))
			{
				Promotion* C = dynamic_cast<Promotion*>(Ev);
				int ID = C->getID();
				Promote(ID);
			}
		}
		/////// assign missions to rovers
		assigEM();//assign Emergncy Missions
		assigPM();//assign Polar Missions
		assigMM();//assign Mountainous Missions
		failMission();// re-formulted Mission failed
		ExecutionSim();//simulate Execution
		AutoPromote();//Auto promotion
		CheukupSim();//Cheukup Simulate
	}
}
void MarsStation::setMaxDistance(int MaxDistance)
{
	this->MaxDistance = MaxDistance;
}

void MarsStation::CheukupSim()
{
	Rover*R;
	while (CheukUp.peek(R) && R->getCheukDuration() == CountDays)
	{
		if (dynamic_cast<MountainousRover*>(R)) {
			MR.enqueue(dynamic_cast<MountainousRover*>(R), R->getSpeed());
		}
		else if (dynamic_cast<PolarRover*>(R)) {
			PR.enqueue(dynamic_cast<PolarRover*>(R), R->getSpeed());
		}
		else if (dynamic_cast<EmergencyRover*>(R)) {
			ER.enqueue(dynamic_cast<EmergencyRover*>(R), R->getSpeed());
		}
	}
}

void MarsStation::assigEM()
{
	EmergencyMission* E;
	while (EM.peek(E) && E->getFormulationDay() <= CountDays)
	{
		double duration;
		if (!ER.isEmpty())
		{
			EM.dequeue(E);
			EmergencyRover * R;
			ER.dequeue(R);
			duration = ceil(CountDays + E->getMDUR() + E->getTargetLocation() / ((double)R->getSpeed()));
			E->setExPeriod(duration);
			if (E->getTargetLocation() > MaxDistance)
			{
				Execution.enqueue(makepair((Mission*)(E), (Rover*)(R)), INT_MAX + E->getTargetLocation() - MaxDistance);
			}
			else
			{
				Execution.enqueue(makepair((Mission*)(E), (Rover*)(R)), -duration);
			}

			R->operator++();
		}
		else if (!MR.isEmpty())
		{
			EM.dequeue(E);
			MountainousRover * R;
			MR.dequeue(R);
			duration = ceil(CountDays + E->getMDUR() + (E->getTargetLocation() / ((double)R->getSpeed())));
			E->setExPeriod(duration);
			if (E->getTargetLocation() > MaxDistance)
			{
				Execution.enqueue(makepair((Mission*)(E), (Rover*)(R)), INT_MAX + E->getTargetLocation() - MaxDistance);
			}
			else
			{
				Execution.enqueue(makepair((Mission*)(E), (Rover*)(R)), -duration);
			}

			R->operator++();
		}
		else if (!PR.isEmpty())
		{
			EM.dequeue(E);
			PolarRover * R;
			PR.dequeue(R);
			duration = ceil(CountDays + E->getMDUR() + (E->getTargetLocation() / ((double)R->getSpeed())));
			E->setExPeriod(duration);
			if (E->getTargetLocation() > MaxDistance)
			{
				Execution.enqueue(makepair((Mission*)(E), (Rover*)(R)), INT_MAX + E->getTargetLocation() - MaxDistance);
			}
			else
			{
				Execution.enqueue(makepair((Mission*)(E), (Rover*)(R)), -duration);
			}

			R->operator++();
		}
		else
		{
			break;
		}
	}
}

void MarsStation::assigPM()
{
	PolarMission* p;
	while (PM.peek(p) && p->getFormulationDay() <= CountDays)
	{
		double duration;
		if (!PR.isEmpty())
		{
			PolarRover * R;
			PR.dequeue(R);
			duration = ceil(CountDays + p->getMDUR() + (p->getTargetLocation() / ((double)R->getSpeed())));
			p->setExPeriod(duration);
			if (p->getTargetLocation() > MaxDistance)
			{
				Execution.enqueue(makepair((Mission*)(p), (Rover*)(R)), INT_MAX + p->getTargetLocation() - MaxDistance);
			}
			else
			{
				Execution.enqueue(makepair((Mission*)(p), (Rover*)(R)), -duration);
			}

			R->operator++();
		}
		else
		{
			break;
		}
	}
}

void MarsStation::assigMM()
{
	MountainousMission* m;
	while (!MM.isEmpty() && MM.getEntry(1)->getFormulationDay() <= CountDays)
	{
		double duration;
		m = MM.getEntry(1);
		if (!MR.isEmpty())
		{
			MM.remove(1);
			MountainousRover * R;
			MR.dequeue(R);
			duration = ceil(CountDays + m->getMDUR() + (m->getTargetLocation() / ((double)R->getSpeed())));
			m->setExPeriod(duration);
			if (m->getTargetLocation() > MaxDistance)
			{
				Execution.enqueue(makepair((Mission*)(m), (Rover*)(R)), INT_MAX + m->getTargetLocation() - MaxDistance);
			}
			else
			{
				Execution.enqueue(makepair((Mission*)(m), (Rover*)(R)), -duration);
			}

			R->operator++();
		}
		else if (!ER.isEmpty())
		{
			MM.remove(1);
			EmergencyRover * R;
			ER.dequeue(R);
			duration = ceil(CountDays + m->getMDUR() + m->getTargetLocation() / ((double)R->getSpeed()));
			m->setExPeriod(duration);
			if (m->getTargetLocation() > MaxDistance)
			{
				Execution.enqueue(makepair((Mission*)(m), (Rover*)(R)), INT_MAX + m->getTargetLocation() - MaxDistance);
			}
			else
			{
				Execution.enqueue(makepair((Mission*)(m), (Rover*)(R)), -duration);
			}
			R->operator++();
		}
		else
		{
			break;
		}
	}
}

void MarsStation::ExecutionSim()
{
	Pair<Mission*, Rover*> Ex;
	while (Execution.peek(Ex) && Ex.first->getExPeriod() <= CountDays)
	{
		Execution.dequeue(Ex);
		// re-formulated Missions 
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
		// re-formulated Rovers
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
			MountainousRover*M = dynamic_cast<MountainousRover*>(Ex.second);
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
}

void MarsStation::failMission()
{
	Pair<Mission*, Rover*> Ex;
	while (Execution.peek(Ex) && Ex.first->getTargetLocation() > MaxDistance)
	{
		Execution.dequeue(Ex);
		if (dynamic_cast<MountainousRover*>(Ex.second)) {
			CheukUp.enqueue(Ex.second, -(CountDays + MCheckUp));
		}
		else if (dynamic_cast<PolarRover*>(Ex.second)) {
			CheukUp.enqueue(Ex.second, -(CountDays + PCheckUp));
		}
		else if (dynamic_cast<EmergencyRover*>(Ex.second)) {
			CheukUp.enqueue(Ex.second, -(CountDays + ECheckUp));
		}

		Ex.first->setFormulationDay(CountDays);
		if (dynamic_cast<MountainousMission*>(Ex.first)) {
			MM.insert(MM.getLength() + 1, (dynamic_cast<MountainousMission*>(Ex.first)));
		}
		else if (dynamic_cast<PolarMission*>(Ex.first)) {
			PM.enqueue((dynamic_cast<PolarMission*>(Ex.first)));
		}
		else if (dynamic_cast<EmergencyMission*>(Ex.first)) {
			EM.enqueue((dynamic_cast<EmergencyMission*>(Ex.first)), 0);
		}
	}

}
void MarsStation::roverMaintance(Rover* r)
{

	if (r->getnoOfMissions() >= 2 * NMission2CheckUp + 1) {
		r->setfree(0);
		r->setMaintenance(1);
	}

}
MarsStation::~MarsStation()
{
}
