#include "MarsStation.h"
#include <string>
MarsStation::MarsStation(string input, string output) :CountDays(0), Enum(0), Pnum(0), Mnum(0), EventCount(0), InputFile(input), OutputFile(output)
{
	UI_PTR = new UI(this);
	//OpenInputFile(input);
	//OpenOutputFile(output);
}


void MarsStation::setCheckUpData(int MCheckUp, int PCheckUp, int ECheckUp, int NMission2CheckUp)
{
	this->MCheckUp = MCheckUp;
	this->PCheckUp = PCheckUp;
	this->ECheckUp = ECheckUp;
	this->NMission2CheckUp = NMission2CheckUp;
}

void MarsStation::Add2MM(MountainousMission* M)
{
	MM.insert(MM.getLength() + 1, M);
	Mnum++;
}

void MarsStation::Add2PM(PolarMission* P)
{
	PM.enqueue(P);
	Pnum++;
}

void MarsStation::Add2EM(EmergencyMission* E)
{
	EM.enqueue(E, E->calcPriority());
	Enum++;
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

void MarsStation::GetInput()
{
	UI_PTR->ReadInputFile(InputFile);
}

void MarsStation::GetOutput()
{
	UI_PTR->PrintinOutputFile(OutputFile);
}

void MarsStation::AddFormulationEvent(char MissionType, int ED, int ID, int TLOC, int MDUR, int SIG)
{
	Formulation* F = new Formulation(MissionType, ED);
	F->setFormulatedMission(ED, ID, TLOC, MDUR, SIG);
	events.enqueue(F);
}

void MarsStation::AddPromotionEvent(int ED ,int ID)
{
	Promotion *P = new Promotion(ED ,ID);
	events.enqueue(P);
}

void MarsStation::AddCanellationEvent(int ED, int ID)
{
	cancellation* C = new cancellation(ED, ID);
	events.enqueue(C);
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
		CountDays++;// Read Events
		DailyEvent();//making mission , cancel or promote 
		CheukupSim();//Cheukup Simulate
		/////// assign missions to rovers
		ExecutionSim();//simulate Execution
		assigEM();//assign Emergncy Missions
		assigPM();//assign Polar Missions
		assigMM();//assign Mountainous Missions
		failMission();// re-formulted Mission failed
		AutoPromote();//Auto promotion
		UI_PTR->Interactive_Mode();
	}
}
MarsStation::~MarsStation()
{
	delete UI_PTR;
	Event* E;
	while (events.dequeue(E))
	{
		delete E;
	}
	PolarRover* P;
	while (PR.dequeue(P))
	{
		delete P;
	}
	MountainousRover* M;
	while (MR.dequeue(M))
	{
		delete M;
	}
	EmergencyRover* Er;
	while (ER.dequeue(Er))
	{
		delete Er;
	}
	Mission* cm;
	while (CM.dequeue(cm))
	{
		delete cm;
	}
	Rover* r;
	while (CheukUp.dequeue(r))
	{
		delete r;
	}
	Pair<Mission*, Rover*>p;
	while (Execution.dequeue(p))
	{
		delete p.first;
		delete p.second;
	}
	PolarMission* pm;
	while (PM.dequeue(pm))
	{
		delete pm;
	}
	EmergencyMission* em;
	while (EM.dequeue(em))
	{
		delete em;
	}
	MountainousMission* mm;
	for (int i = 1; i <= MM.getLength(); i++)
	{
		delete MM.getEntry(i);
	}
}
void MarsStation::setMaxDistance(int MaxDistance)
{
	this->MaxDistance = MaxDistance;
}

void MarsStation::DailyEvent()
{
	Event* Ev;
	while (events.peek(Ev) && Ev->getEventDay() == CountDays)
	{
		events.dequeue(Ev);
		Ev->Execute(this);
	}
}

void MarsStation::CheukupSim()
{
	Rover*R;
	while (CheukUp.peek(R) && R->getCheukDuration() == CountDays)
	{
		CheukUp.dequeue(R);
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
			PM.dequeue(p);
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
				E->setCheukDuration(CountDays + ECheckUp);
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
				M->setCheukDuration(CountDays + ECheckUp);
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
				p->setCheukDuration(CountDays + ECheckUp);
				p->resetnoOfMissions();
			}
			else
			{
				PR.enqueue(p, p->getSpeed());
			}
		}
	}
}

Pair<int, string> MarsStation::PrintWaitingMission()
{
	Queue<PolarMission*> PMt = PM;
	priority_Queue<EmergencyMission*> EMt = EM;
	int num = 0;
	string s1;
	EmergencyMission* E;
	if (!EMt.isEmpty())
	{
		s1 = "[";
	}
	while (EMt.dequeue(E))
	{
		num++;
		s1 += (to_string(E->getID()));
		s1.push_back(',');
		if (EMt.isEmpty())
		{
			s1[s1.size() - 1] = ']';
		}
	}
	string s2;
	PolarMission* P;
	if (!PMt.isEmpty())
	{
		s2 = "(";
	}
	while (PMt.dequeue(P))
	{
		num++;
		s2 += (to_string(P->getID()));
		s2.push_back(',');
		if (PMt.isEmpty())
		{
			s2[s2.size() - 1] = ')';
		}
	}
	string s3;
	if (MM.getLength())
	{
		s3 = "{";
	}

	for (int i = 1; i <= MM.getLength(); i++)
	{
		num++;
		s3 += (to_string(MM.getEntry(i)->getID()));
		s3.push_back(',');
		if (MM.getLength())
		{
			s3[s3.size() - 1] = '}';
		}
	}
	return makepair(num, s1 + " " + s2 + " " + s3);
	return Pair<int, string>();
}


Pair<int, string> MarsStation::PrintExecetion()
{
	priority_Queue<Pair<Mission*, Rover*>> Executiont = Execution;
	int num = 0;
	string s1 = "[";
	string s2 = "(";
	string s3 = "{";
	Pair<Mission*, Rover*>E;
	while (Executiont.dequeue(E))
	{
		num++;
		if (dynamic_cast<EmergencyMission*>(E.first))
		{
			s1 += (to_string(E.first->getID()) + "/" + to_string(E.second->getID()));
			s1.push_back(',');
		}
		else if (dynamic_cast<MountainousMission*>(E.first))
		{
			s3 += (to_string(E.first->getID()) + "/" + to_string(E.second->getID()));
			s3.push_back(',');
		}
		else
		{
			s2 += (to_string(E.first->getID()) + "/" + to_string(E.second->getID()));
			s2.push_back(',');
		}
	}
	s1[s1.size() - 1] = ']';
	s2[s2.size() - 1] = ')';
	s3[s3.size() - 1] = '}';
	if (s1.size() <= 2)
	{
		s1 = "";
	}
	if (s2.size() <= 2)
	{
		s2 = "";
	}
	if (s3.size() <= 2)
	{
		s3 = "";
	}
	return makepair(num, s1 + " " + s2 + " " + s3);
}

Pair<int, string> MarsStation::Printavailable()
{
	priority_Queue<PolarRover*> PRt = PR;
	priority_Queue<EmergencyRover*> ERt = ER;
	priority_Queue<MountainousRover*> MRt = MR;
	string s1 = "[";
	string s2 = "(";
	string s3 = "{";
	int num = 0;
	EmergencyRover* E;
	while (ERt.dequeue(E))
	{
		num++;
		s1 += (to_string(E->getID()));
		s1.push_back(',');
	}
	s1[s1.size() - 1] = ']';
	PolarRover* P;
	while (PRt.dequeue(P))
	{
		num++;
		s2 += (to_string(P->getID()));
		s2.push_back(',');
	}
	s2[s2.size() - 1] = ')';

	MountainousRover* M;
	while (MRt.dequeue(M))
	{
		num++;
		s3 += (to_string(M->getID()));
		s3.push_back(',');
	}
	s3[s3.size() - 1] = '}';
	if (s1.size() <= 2)
	{
		s1 = "";
	}
	if (s2.size() <= 2)
	{
		s2 = "";
	}
	if (s3.size() <= 2)
	{
		s3 = "";
	}
	return Pair<int, string>(num, s1 + " " + s2 + " " + s3);
}

Pair<int, string> MarsStation::PrintCompleted()
{
	Queue<Mission*> CMt = CM;
	int num = 0;
	string s1 = "[";
	string s2 = "(";
	string s3 = "{";
	Mission*E;
	while (CMt.dequeue(E))
	{
		num++;
		if (dynamic_cast<EmergencyMission*>(E))
		{
			s1 += (to_string(E->getID()));
			s1.push_back(',');
		}
		else if (dynamic_cast<MountainousMission*>(E))
		{
			s3 += (to_string(E->getID()));
			s3.push_back(',');
		}
		else
		{
			s2 += (to_string(E->getID()));
			s2.push_back(',');
		}
	}
	s1[s1.size() - 1] = ']';
	s2[s2.size() - 1] = ')';
	s3[s3.size() - 1] = '}';
	if (s1.size() <= 2)
	{
		s1 = "";
	}
	if (s2.size() <= 2)
	{
		s2 = "";
	}
	if (s3.size() <= 2)
	{
		s3 = "";
	}
	return makepair(num, s1 + " " + s2 + " " + s3);
}

Pair<int, string> MarsStation::PrintCheukUp()
{
	priority_Queue<Rover*> CheukUpt = CheukUp;
	int num = 0;
	Rover* R;
	string s1 = "[", s2 = "(", s3 = "{";
	while (CheukUpt.dequeue(R))
	{
		num++;
		if (dynamic_cast<EmergencyRover*>(R))
		{
			s1 += to_string(R->getID());
			s1.push_back(',');

		}
		else if (dynamic_cast<PolarRover*>(R))
		{
			s2 += to_string(R->getID());
			s2.push_back(',');
		}
		else if (dynamic_cast<MountainousRover*>(R))
		{
			s3 += to_string(R->getID());
			s3.push_back(',');
		}
	}
	s1[s1.size() - 1] = ']';
	s2[s2.size() - 1] = ')';
	s3[s3.size() - 1] = '}';
	if (s1.size() <= 2)
	{
		s1 = "";
	}
	if (s2.size() <= 2)
	{
		s2 = "";
	}
	if (s3.size() <= 2)
	{
		s3 = "";
	}
	return makepair<int, string>(num, s1 + " " + s2 + " " + s3);
}

int MarsStation::getDay()
{
	return CountDays;
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
