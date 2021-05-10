#pragma once
class Rover {

	int Speed;
	int CheckupDuration;
	int noOfMissions;
public:
	Rover();
	Rover(int s,int cd,int nom);
	virtual void setCheckupDuration(int cd);
	virtual void setSpeed(int s);
	virtual void setnoOfMissions(int nom);
	virtual int getCheckupDuration();
	virtual int getSpeed();
	virtual int getnoOfMissions();

};	

