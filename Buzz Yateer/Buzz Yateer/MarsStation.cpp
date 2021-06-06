#include "MarsStation.h"
#include <string>
MarsStation::MarsStation(string input, string output) :CountDays(0), Enum(0), Pnum(0), Mnum(0), EventCount(0), InputFile(input), OutputFile(output)
, nOfCheckUp2Maintenence(0), nOfdays2LeaveMaintenence(0), Ap(0), NumMDE(0), NumPDE(0), NumEDE(0)
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

void MarsStation::Add2Maintenence(Rover* R)
{
	if (R->getNoOfCheckUps() < nOfCheckUp2Maintenence)
	{
		return;
	}
	if (dynamic_cast<EmergencyRover*>(R))
	{
		ER.enqueue(dynamic_cast<EmergencyRover*>(R), INT_MIN + CountDays + nOfdays2LeaveMaintenence);
	}
	else if (dynamic_cast<MountainousRover*>(R))
	{
		MR.enqueue(dynamic_cast<MountainousRover*>(R), INT_MIN + CountDays + nOfdays2LeaveMaintenence);
	}
	else
	{
		PR.enqueue(dynamic_cast<PolarRover*>(R), INT_MIN + CountDays + nOfdays2LeaveMaintenence);
	}
	Maintenence.enqueue(R, CountDays + nOfdays2LeaveMaintenence);
	R->setMaintenance(1);
	R->setMaintenenceDuration(CountDays + nOfdays2LeaveMaintenence);
	R->resetnoOfCheckUps();
}

void MarsStation::RemoveFromMaintenence(bool Force)
{
	Rover* R;
	while (Maintenence.peek(R) && (R->getMaintenenceDuration() <= CountDays || Force))
	{
		Maintenence.dequeue(R);
		R->setMaintenance(0);
	}
}

void MarsStation::setMaintenenceData(int nOfCheckUp2Maintenence, int nOfdays2LeaveMaintenence)
{
	this->nOfCheckUp2Maintenence = nOfCheckUp2Maintenence;
	this->nOfdays2LeaveMaintenence = nOfdays2LeaveMaintenence;
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
	OutputFile.open(outputfile);
}

void MarsStation::AddFormulationEvent(char MissionType, int ED, int ID, int TLOC, int MDUR, int SIG)
{
	Formulation* F = new Formulation(MissionType, ED);
	F->setFormulatedMission(ED, ID, TLOC, MDUR, SIG);
	events.enqueue(F);
}

void MarsStation::AddPromotionEvent(int ED, int ID)
{
	Promotion* P = new Promotion(ED, ID);
	events.enqueue(P);
}

void MarsStation::AddCanellationEvent(int ED, int ID)
{
	cancellation* C = new cancellation(ED, ID);
	events.enqueue(C);
}

void MarsStation::AddPolarRover(double speed)
{
	PR.enqueue(new PolarRover(speed), speed);
}

void MarsStation::AddEmergencyRover(double speed)
{
	ER.enqueue(new EmergencyRover(speed), speed);
}

void MarsStation::AddMountainousRover(double speed)
{
	MR.enqueue(new MountainousRover(speed), speed);
}

bool MarsStation::CancelMission(int ID)
{
	int i = 1;
	while(MM.getEntry(i))
	{
		if (MM.getEntry(i)->getID() == ID)
		{
			MM.remove(i);
			return 1;
		}
		i++;
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
	int i = 1;
	while (MM.getEntry(i))
	{
		if (MM.getEntry(i)->getID() == ID)
		{
			MountainousMission* temp = MM.getEntry(i);
			EmergencyMission* EMEr = new EmergencyMission(temp->getFormulationDay(), temp->getMDUR(), temp->getSignificance(), temp->getTargetLocation(), temp->getID());
			EMEr->setFormulationDay(CountDays);
			EM.enqueue(EMEr, EMEr->calcPriority());
			MM.remove(i);
			Mnum--;
			Enum++;
			break;
		}
		i++;
	}
}

void MarsStation::AutoPromote()
{
	int i = 1;
	while (MM.getEntry(i))
	{
		if (MM.getEntry(i)->getFormulationDay() + AutoP == CountDays)
		{
			MountainousMission* temp = MM.getEntry(i);
			EmergencyMission* EMEr = new EmergencyMission(temp->getFormulationDay(), temp->getMDUR(), temp->getSignificance(), temp->getTargetLocation(), temp->getID());
			EMEr->setFormulationDay(CountDays);
			Ap++;
			EM.enqueue(EMEr, EMEr->calcPriority());
			MM.remove(i);
			Mnum--;
			Enum++;
			i--;
		}
		i++;
	}
}


int MarsStation::CountRovers(int& Er, int& Mr, int& Pr)
{
	Er = (NE > 0) ? NE : 0;
	Mr = (NM > 0) ? NM : 0;
	Pr = (NP > 0) ? NP : 0;
	return Er + Mr + Pr;
}


void MarsStation::Simulate()
{
	while (!events.isEmpty() || !Execution.isEmpty() || !EM.isEmpty() || !PM.isEmpty() || !MM.isEmpty() || !CheukUp.isEmpty() || !Maintenence.isEmpty())
	{
		CountDays++;// Read Events
		if (CountDays == 8)
		{
			int xxxx = 1;
		}
		RemoveFromMaintenence();
		AutoPromote();//Auto promotion
		DailyEvent();//making mission , cancel or promote 
		//DailyEvent();//making mission , cancel or promote
		ExecutionSim();//simulate Execution
		CheukupSim();//Cheukup Simulate
		/////// assign missions to rovers
		assigEM();//assign Emergncy Missions
		assigPM();//assign Polar Missions
		assigMM();//assign Mountainous Missions
		failMission();// re-formulted Mission failed
		UI_PTR->decide();
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
	while (MM.getEntry(1))
	{
		MM.remove(1);
	}
	Rover* rfm;
	while (Maintenence.dequeue(rfm))
	{
		delete rfm;
	}
}
void MarsStation::ReadInputFile()
{
	UI_PTR->Start();
    int NOFM, MCD, PCD, ECD;
	InputFile >> NM >> NP >> NE >> MCD >> PCD >> ECD >> NOFM;
	setCheckUpData(MCD, PCD, ECD, NOFM);
    for(int i=0;i< NM;i++)
	{
		double MS;
		InputFile >> MS;
		if (MS > 0)
		{
			AddMountainousRover(MS);
		}
	}
	for (int i = 0; i < NP; i++)
	{
		double PS;
		InputFile >> PS;
		if (PS > 0)
		{
			AddPolarRover(PS);
		}
	}
	for (int i = 0; i < NE; i++)
	{
		double ES;
		InputFile >> ES;
		if (ES > 0)
		{
			AddEmergencyRover(ES);
		}
	}
	int AutoP, MaxPeriod, nOfCheckUp2Maintenence, nOfdays2LeaveMaintenence;
	InputFile >> AutoP >> MaxPeriod >> nOfCheckUp2Maintenence >> nOfdays2LeaveMaintenence;
	setMaxPeriod(MaxPeriod);
	setAutoPromotion(AutoP);
	setMaintenenceData(nOfCheckUp2Maintenence, nOfdays2LeaveMaintenence);
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
				AddFormulationEvent(MissionType, ED, ID, TLOC, MDUR, SIG);
			}
			else if (Event == 'X')
			{
				int ED, ID;
				InputFile >> ED >> ID;
				AddCancellation(ID, ED);
			}
			else if ((Event == 'P'))
			{
				int ED, ID;
				InputFile >> ED >> ID;
				AddPromotionEvent(ED, ID);
			}
		}
	}
}
void MarsStation::PrintinOutputFile()
{
	double SumWait = 0, SumExec = 0;
	int CD, ID, FD, WD, ED, Mm, Em, Pm, TotalMission=0, Er = 0, Mr = 0, Pr = 0, TotalRover;
	Pm = Mm = Em = 0;
	TotalMission =0;
	OutputFile << "CD" << "		" << "ID" << "		" << "FD" << "		" << "WD" << "		" << "ED" << " " << endl;
	Mission* entry;
					
	while (CM.dequeue(entry))
	{
		TotalMission++;
		if (dynamic_cast<EmergencyMission*>(entry)) {
			Em++;
		}
		else if (dynamic_cast<MountainousMission*>(entry)) {
			Mm++;
		}
		else if (dynamic_cast<PolarMission*>(entry)) {
			Pm++;
		}
		CD = entry->getCD();
		ID = entry->getID();
		FD = entry->getFormulationDay();
		ED = entry->getExPeriod();
		WD = entry->getWaitingDays();
		SumWait += WD;
		SumExec += ED;
		OutputFile << CD << "		" << ID << "		" << FD << "		" << WD << "		" << ED << "       " << endl;
	}
	TotalRover =CountRovers(Er, Mr, Pr);
	OutputFile << endl;
	OutputFile << ".....................\n";
	OutputFile << endl;
	OutputFile << ".....................\n";
	OutputFile << "Missions: " << TotalMission << "[" << "M: " << Mm << "," << "P: " << Pm << "," << "E: " << Em << "]" << endl;
	OutputFile << "Rovers: " << TotalRover << "[" << "M: " << Mr << "," << "P: " << Pr << "," << "E: " << Er << "]" << endl;
	OutputFile << "Avg Wait = " << SumWait / TotalMission << ", " << "Avg Exec = " << SumExec / TotalMission << "\n";
	OutputFile << "Auto-promoted: " << (Ap / (Mnum+Ap)) * 100<<"\n";
	OutputFile << "Missions can't done: " << NumMDE+ NumPDE+ NumEDE << "[" << "M: " << NumMDE << "," << "P: " << NumPDE << "," << "E: " << NumEDE << "]" << endl;
	OutputFile.close();
}
bool MarsStation::CanDoEM()
{
	return (NM>0)|| (NP>0)|| (NE>0);
}
bool MarsStation::CanDoMM()
{
	return (NM > 0) || (NE > 0);
}
bool MarsStation::CanDoPM()
{
	return  (NP > 0) ;
}
void MarsStation::IncreaseNumMDE()
{
	NumMDE++;
}
void MarsStation::IncreaseNumPDE()
{
	NumPDE++;
}
void MarsStation::IncreaseNumEDE()
{
	NumEDE++;
}
void MarsStation::setMaxPeriod(int MaxPeriod)
{
	this->MaxPeriod = MaxPeriod;
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
	Rover* R;
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
		if (E->getXFailed() && ER.isEmpty())
			return;
		int duration;
		if (!ER.isEmpty())
		{
			EM.dequeue(E);
			EmergencyRover* R;
			ER.dequeue(R);
			E->setAssignmentDay(CountDays);
			duration =(int) ceil(CountDays + E->getMDUR() + (2*E->getTargetLocation()) / (((double)R->getSpeed())*25));
			if (R->geMaintenance())
			{
				RemoveFromMaintenence(1);
			}
			E->setExPeriod(duration - CountDays);
			E->setCD(duration);
			Execution.enqueue(makepair((Mission*)(E), (Rover*)(R)), -duration);
			R->operator++();
		}
		else if (!MR.isEmpty())
		{
			EM.dequeue(E);
			MountainousRover* R;
			MR.dequeue(R);
			E->setAssignmentDay(CountDays);
			duration = (int)ceil(CountDays + E->getMDUR() + (2*E->getTargetLocation()) / (((double)R->getSpeed()) * 25));
			if (R->geMaintenance())
			{
				RemoveFromMaintenence(1);
			}
			E->setExPeriod(duration - CountDays);
			E->setCD(duration);
			Execution.enqueue(makepair((Mission*)(E), (Rover*)(R)), -duration);
			R->operator++();
		}
		else if (!PR.isEmpty())
		{
			EM.dequeue(E);
			PolarRover* R;
			PR.dequeue(R);
			E->setAssignmentDay(CountDays);
			duration = (int)ceil(CountDays + E->getMDUR() + ((2*E->getTargetLocation()) / (((double)R->getSpeed()) * 25)));
			if (R->geMaintenance())
			{
				RemoveFromMaintenence(1);
			}
			E->setExPeriod(duration - CountDays);
			E->setCD(duration);
			Execution.enqueue(makepair((Mission*)(E), (Rover*)(R)), -duration);
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
		int duration;
		if (!PR.isEmpty())
		{
			PolarRover* R;
			PR.dequeue(R);
			PM.dequeue(p);
			p->setAssignmentDay(CountDays);
			duration = (int)ceil(CountDays + p->getMDUR() + ((2*p->getTargetLocation()) / (((double)R->getSpeed()) * 25)));
			if (R->geMaintenance())
			{
				RemoveFromMaintenence(1);
			}
			p->setExPeriod(duration - CountDays);
			p->setCD(duration);
			R->operator++();
			Execution.enqueue(makepair((Mission*)(p), (Rover*)(R)), -duration);
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
		int duration;
		m = MM.getEntry(1);
		if (m->getXFailed() && MR.isEmpty())
			return;
		if (!MR.isEmpty())
		{
			MM.remove(1);
			MountainousRover* R;
			MR.dequeue(R);
			m->setAssignmentDay(CountDays);
			duration = (int)ceil(CountDays + m->getMDUR() + ((2*m->getTargetLocation()) / (((double)R->getSpeed()) * 25)));
			if (R->geMaintenance())
			{
				RemoveFromMaintenence(1);
			}
			m->setExPeriod(duration - CountDays);
			m->setCD(duration);
			Execution.enqueue(makepair((Mission*)(m), (Rover*)(R)), -duration);
			R->operator++();
		}
		else if (!ER.isEmpty())
		{
			MM.remove(1);
			EmergencyRover* R;
			ER.dequeue(R);
			m->setAssignmentDay(CountDays);
			duration = (int)ceil(CountDays + m->getMDUR() + (2*m->getTargetLocation()) / (((double)R->getSpeed()) * 25));
			if (R->geMaintenance())
			{
				RemoveFromMaintenence(1);
			}
			m->setExPeriod(duration - CountDays);
			m->setCD(duration);
			Execution.enqueue(makepair((Mission*)(m), (Rover*)(R)), -duration);
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
	while (Execution.peek(Ex) && Ex.first->getCD() <= CountDays)
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
		Add2Maintenence(Ex.second);
		if (dynamic_cast<EmergencyRover*>(Ex.second))
		{
			EmergencyRover* E = dynamic_cast<EmergencyRover*>(Ex.second);
			if (E->getnoOfMissions() == NMission2CheckUp)
			{
				CheukUp.enqueue(E, -(CountDays + ECheckUp));
				E->setCheukDuration(CountDays + ECheckUp);
				E->resetnoOfMissions();
				E->NoOfCheckUpsIncrement();
			}
			else
			{
				if (!E->geMaintenance())
					ER.enqueue(E, E->getSpeed());
			}
		}
		else if (dynamic_cast<MountainousRover*>(Ex.second))
		{
			MountainousRover* M = dynamic_cast<MountainousRover*>(Ex.second);
			if (M->getnoOfMissions() == NMission2CheckUp)
			{
				CheukUp.enqueue(M, -(CountDays + MCheckUp));
				M->setCheukDuration(CountDays + MCheckUp);
				M->resetnoOfMissions();
				M->NoOfCheckUpsIncrement();
			}
			else
			{
				if (!M->geMaintenance())
					MR.enqueue(M, M->getSpeed());
			}
		}
		else if (dynamic_cast<PolarRover*>(Ex.second))
		{
			PolarRover* p = dynamic_cast<PolarRover*>(Ex.second);
			if (p->getnoOfMissions() == NMission2CheckUp)
			{
				CheukUp.enqueue(p, -(CountDays + PCheckUp));
				p->setCheukDuration(CountDays + PCheckUp);
				p->resetnoOfMissions();
				p->NoOfCheckUpsIncrement();
			}
			else
			{
				if (!p->geMaintenance())
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
	string s3 = "{";
	int j = 1;
	while(MM.getEntry(j))
	{
		num++;
		s3 += (to_string(MM.getEntry(j)->getID()));
		s3.push_back(',');
		j++;
	}
	if (s3.size() != 1)
	{
		s3[s3.size() - 1] = '}';
	}
	else
	{
		s3 = "";
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
	Mission* E;
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

Pair<int, string> MarsStation::PrintMaintenece()
{
	priority_Queue<Rover*>Maintenencet = Maintenence;
	int num = 0;
	Rover* R;
	string s1 = "[";
	string s2 = "(";
	string s3 = "{";
	while (Maintenencet.dequeue(R))
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

void MarsStation::PrintCompletedInfo(int& CD, int& ID, int& FD, int& ED, int& WD, int& em, int& pm, int& mm, double& Ap)
{
	//pm = mm = em = 0;
	Mission* entry;

	CM.dequeue(entry);

	if (dynamic_cast<EmergencyMission*>(entry)) {
		em++;
	}
	else if (dynamic_cast<MountainousMission*>(entry)) {
		mm++;
	}
	else if (dynamic_cast<PolarMission*>(entry)) {
		pm++;
	}

	CD = entry->getCD();
	ID = entry->getID();
	FD = entry->getFormulationDay();
	ED = entry->getExPeriod();
	WD = entry->getWaitingDays();

}

int MarsStation::getDay()
{
	return CountDays;
}

int MarsStation::getCompletedLength()
{

	//return CM.GetLength();
	return CM.GetLength();
}

int MarsStation::Choose_Mode()
{
	return Mode;
}

void MarsStation::Set_Mode(int x)
{
	Mode = x;
}

string MarsStation::FailedMissionsPrint()
{
	return FailedMissions;
}

void MarsStation::resetFailedMission()
{
	FailedMissions = "";
}

void MarsStation::failMission()
{
	string s1 = "[";
	string s2 = "{";
	Pair<Mission*, Rover*> Ex;
	while (Execution.peek(Ex) && Ex.first->getCD() - Ex.first->getAssignmentDay() > MaxPeriod && CountDays == MaxPeriod + Ex.first->getAssignmentDay())
	{
		if (dynamic_cast<PolarMission*>(Ex.first) || (dynamic_cast<MountainousMission*>(Ex.first) && dynamic_cast<MountainousRover*>(Ex.second))
			|| (dynamic_cast<EmergencyMission*>(Ex.first) && dynamic_cast<EmergencyRover*>(Ex.second)))
		{
			return;
		}
		Execution.dequeue(Ex);
		Add2Maintenence(Ex.second);
		if (!Ex.second->geMaintenance())
		{
			if (dynamic_cast<MountainousRover*>(Ex.second)) {
				Ex.second->setCheukDuration(CountDays + MCheckUp);
				CheukUp.enqueue(Ex.second, -(CountDays + MCheckUp));
			}
			else if (dynamic_cast<PolarRover*>(Ex.second)) {
				Ex.second->setCheukDuration(CountDays + PCheckUp);
				CheukUp.enqueue(Ex.second, -(CountDays + PCheckUp));
			}
			else if (dynamic_cast<EmergencyRover*>(Ex.second)) {
				Ex.second->setCheukDuration(CountDays + ECheckUp);
				CheukUp.enqueue(Ex.second, -(CountDays + ECheckUp));
			}
			Ex.second->resetnoOfMissions();
		}
		Ex.first->setFormulationDay(CountDays);
		Ex.first->setXFailed(1);
		if (dynamic_cast<MountainousMission*>(Ex.first)) {
			MM.insert(MM.getLength() + 1, (dynamic_cast<MountainousMission*>(Ex.first)));
			s2 += to_string(Ex.first->getID());
			s2.push_back(',');
		}
		else if (dynamic_cast<EmergencyMission*>(Ex.first)) {
			EM.enqueue((dynamic_cast<EmergencyMission*>(Ex.first)), 0);
			s1 += to_string(Ex.first->getID());
			s1.push_back(',');
		}
		s1[s1.size() - 1] = ']';
		s2[s2.size() - 1] = '}';
		if (s1.size() <= 2)
			s1 = "";
		if (s2.size() <= 2)
			s2 = "";
		FailedMissions = s1 + s2;
	}

}
void MarsStation::roverMaintance(Rover* r)
{

	if (r->getnoOfMissions() >= 2 * NMission2CheckUp + 1) {
		r->setfree(0);
		r->setMaintenance(1);
	}

}
