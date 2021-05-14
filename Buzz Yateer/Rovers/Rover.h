#pragma once
class Rover {

	int Speed;
	int noOfMissions;
	bool underMaintenance;
	int NoOfCheckUps;
	bool status;
	int CheukDuration;
public:
	Rover(int speed, bool status = 1, bool underMaintenance = 0, int NoOfCheckUps = 0);
	void operator ++();
	void resetnoOfMissions();
	int getSpeed();
	int getnoOfMissions();
	void setfree(bool s = 1);
	bool getfree();
	void incrementCheckup();
	int getNoOfCheckUps();
	void setMaintenance(bool x);
	bool geMaintenance();
	virtual ~Rover();
	void setCheukDuration(int days);
	int getCheukDuration();
};	

