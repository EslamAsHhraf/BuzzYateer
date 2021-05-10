#pragma once
class Mission
{
private:
	int formulationDay ,duration;
	int significance ,targetLocation;
	int ID;
	char status;
public:
	Mission();
	Mission(int F ,int D ,int S ,int TL ,int id, char Status);
	virtual void setFormulationDay(int fDay);
	virtual void setDuration(int D);
	virtual void setSignificance(int S);
	virtual void setTargetLocation(int TL);
	virtual void setID(int id);
	virtual void setStatus(char status);
	virtual int getFormulationDay() const;
	virtual int getDuration() const;
	virtual int getSignificance() const;
	virtual int getTargetLocation() const;
	virtual int getID() const;
	virtual char getStatus() const;
};
