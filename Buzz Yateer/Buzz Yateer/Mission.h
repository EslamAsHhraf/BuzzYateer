#pragma once
class Mission
{
private:
	int formulationDay ,duration;
	int significance ,targetLocation;
	int ID;
public:
	Mission();
	Mission(int F ,int D ,int S ,int TL ,int id);
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
	virtual ~Mission();
};
