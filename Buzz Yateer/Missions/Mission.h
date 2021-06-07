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
	void setFormulationDay(int fDay);// set FormulationDay
	void setSignificance(int S);// set Significance
	void setTargetLocation(int TL);//set TargetLocation
	void setID(int id);
	void setCD(int cd);
	void setWaitingDays(int wd);//set WaitingDays
	void setAssignmentDay(int ad); //set AssignmentDay
	int getFormulationDay() const;//get FormulationDay
	int getSignificance() const;//get Significance
	int getTargetLocation() const;//get TargetLocation
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