#pragma once
class Mission
{
private:
	int formulationDay, duration, completionDay, waitingDays;
	int significance, targetLocation;
	int ID;
	int MDUR;
	int assignmentDay;
	double ExPeriod;
public:
	Mission();
	Mission(int F, int D, int S, int TL, int id);
	void setFormulationDay(int fDay);
	void setDuration(int D);
	void setSignificance(int S);
	void setTargetLocation(int TL);
	void setID(int id);
	void setCD(int cd);
	void setWaitingDays(int wd);
	void setAssignmentDay(int ad);
	int getFormulationDay() const;
	int getDuration() const;
	int getSignificance() const;
	int getTargetLocation() const;
	int getID() const;
	int getCD() const;
	int getAssignmentDay();
	int getWaitingDays();
	void setMDUR(int MDUR);
	int getMDUR();
	void setExPeriod(double period);
	double getExPeriod();
	virtual ~Mission();
};