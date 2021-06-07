#pragma once
class Rover {

	double Speed;
	int noOfMissions;
	bool underMaintenance;
	int NoOfCheckUps;
	bool status;
	int CheukDuration;
	int ID;
	static int COUNT;
	int MaintenenceDuration;
public:
	Rover(double speed, bool status = 1, bool underMaintenance = 0, int NoOfCheckUps = 0);
	void operator ++();//increase num mission is done by rover
	void resetnoOfMissions();// num mission is done by rover = 0 
	void resetnoOfCheckUps();//num CheckUp of rover = 0
	void NoOfCheckUpsIncrement();//increase num CheckUp of rover
	void setMaintenenceDuration(int MaintenenceDuration);
	int getMaintenenceDuration();
	double getSpeed();
	int getnoOfMissions();
	void setfree(bool s = 1);
	bool getfree();
	int getNoOfCheckUps();
	void setMaintenance(bool x);
	bool geMaintenance();
	void setCheukDuration(int days);// set days are nedded in check up
	int getCheukDuration();
	int getID();
	virtual ~Rover();
};	
