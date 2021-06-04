#pragma once
class Mission
{
private:
	int formulationDay, completionDay, waitingDays;
	int significance, targetLocation;
	int ID;
	int MDUR;
	int assignmentDay;
	int ExPeriod;
	bool XFailed;
public:
	Mission();
	Mission(int F, int D, int S, int TL, int id);
	void setXFailed(bool XF);
	bool getXFailed();
	void setFormulationDay(int fDay);
	void setSignificance(int S);
	void setTargetLocation(int TL);
	void setID(int id);
	void setCD(int cd);
	void setWaitingDays(int wd);
	void setAssignmentDay(int ad);
	int getFormulationDay() const;
	int getSignificance() const;
	int getTargetLocation() const;
	int getID() const;
	int getCD() const;
	int getAssignmentDay();
	int getWaitingDays();
	void setMDUR(int MDUR);
	int getMDUR();
	void setExPeriod(int period);
	int getExPeriod();
	virtual ~Mission();
};