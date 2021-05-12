#pragma once
class Rover {

	int Speed;
	int noOfMissions;
public:
	Rover(int speed);
	void operator ++();
	int getSpeed();
	int getnoOfMissions();

};	

