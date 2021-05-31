#include "Mission.h"

Mission::Mission() :formulationDay(0), duration(0), significance(0), targetLocation(0), ID(0), MDUR(0), completionDay(0), assignmentDay(0), XFailed(0)
{
}

Mission::Mission(int F, int D, int S, int TL, int id) : XFailed(0)
{
	setPromoted(false);
	setFormulationDay(F);
	setSignificance(S);
	setTargetLocation(TL);
	setMDUR(D);
	setID(id);
}

void Mission::setXFailed(bool XF)
{
	XFailed = XF;
}

bool Mission::getXFailed()
{
	return XFailed;
}

void Mission::setFormulationDay(int fDay)
{
	formulationDay = fDay;
}

void Mission::setDuration(int D)
{
	duration = D;
}

void Mission::setSignificance(int S)
{
	significance = S;
}

void Mission::setTargetLocation(int TL)
{
	targetLocation = TL;
}

void Mission::setID(int id)
{
	ID = id;
}

void Mission::setPromoted(bool P)
{
	Promoted = P;
}

bool Mission::getPromoted()
{
	return Promoted;
}

void Mission::setCD(int cd)
{
	completionDay = cd;
}

void Mission::setWaitingDays(int wd)
{
	waitingDays = wd;
}

void Mission::setAssignmentDay(int ad)
{
	assignmentDay = ad;
}

int Mission::getFormulationDay() const
{
	return formulationDay;
}

int Mission::getDuration() const
{
	return duration;
}

int Mission::getSignificance() const
{
	return significance;
}

int Mission::getTargetLocation() const
{
	return targetLocation;
}

int Mission::getID() const
{
	return ID;
}

int Mission::getCD() const
{
	return completionDay;
}

int Mission::getAssignmentDay()
{
	return assignmentDay;
}

int Mission::getWaitingDays()
{
	return getAssignmentDay() - getFormulationDay();
}

void Mission::setMDUR(int MDUR)
{
	this->MDUR = MDUR;
}

int Mission::getMDUR()
{
	return MDUR;
}

void Mission::setExPeriod(double period)
{
	ExPeriod = period;
}

double Mission::getExPeriod()
{
	return ExPeriod;
}

Mission::~Mission()
{
	//Empty
}