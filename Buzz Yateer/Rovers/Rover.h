#pragma once
class Rover {

	int Speed;
	int noOfMissions;
public:
	Rover(int speed);
	void operator ++();
	void resetnoOfMissions();
	int getSpeed();
	int getnoOfMissions();
	virtual ~Rover();
};	

