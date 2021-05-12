#pragma once
class Mission
{
private:
	int formulationDay, duration;
	int significance, targetLocation;
	int ID;
	int MDUR;
	double ExPeriod;
public:
	Mission();
	Mission(int F, int D, int S, int TL, int id);
	void setFormulationDay(int fDay);
	void setDuration(int D);
	void setSignificance(int S);
	void setTargetLocation(int TL);
	void setID(int id);
	int getFormulationDay() const;
	int getDuration() const;
	int getSignificance() const;
	int getTargetLocation() const;
	int getID() const;
	void setMDUR(int MDUR);
	int getMDUR();
	void setExPeriod(double period);
	double getExPeriod();
	virtual ~Mission();
};