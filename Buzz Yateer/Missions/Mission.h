#pragma once
class Mission
{
private:
	int formulationDay, completionDay, waitingDays;
	int significance, targetLocation;
	int ID;
	int MDUR;						 //Mission Duration [Days taken in Mars]
	int assignmentDay;				 //Assignment Day
	int ExPeriod;					 //Execution Period
	bool XFailed;					 //Mission Failure Status
public:
	Mission();
	Mission(int F, int D, int S, int TL, int id);
	void setXFailed(bool XF);		 //set Mission Failure Status [failed or not]
	void setFormulationDay(int fDay);//set FormulationDay
	void setSignificance(int S);	 //set Significance
	void setTargetLocation(int TL);	 //set TargetLocation
	void setID(int id);				 //set ID
	void setCD(int cd);				 //set Completion Day
	void setWaitingDays(int wd);     //set WaitingDays
	void setAssignmentDay(int ad);	 //set AssignmentDay
	void setExPeriod(int period);	 //set Execution Period
	bool getXFailed();				 //get Mission Failure Status [failed or not]
	int getFormulationDay() const;	 //get FormulationDay
	int getSignificance() const;	 //get Significance
	int getTargetLocation() const;	 //get TargetLocation
	int getID() const;				 //get ID
	int getCD() const;				 //get Completion Day
	int getAssignmentDay();			 //get AssignmentDay
	int getWaitingDays();			 //get WaitingDays
	void setMDUR(int MDUR);			 //set Mission Duration [Days taken in Mars]
	int getMDUR();					 //get Mission Duration [Days taken in Mars]
	int getExPeriod();				 //get Execution Period
	virtual ~Mission();
};