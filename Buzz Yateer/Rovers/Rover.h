#pragma once
class Rover {

	double Speed;
	int noOfMissions;
	bool underMaintenance;
	int NoOfCheckUps;
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
	void setMaintenenceDuration(int MaintenenceDuration); //set Maintenence Duration of Rovers
	int getMaintenenceDuration();//get Maintenence Duration of Rovers
	double getSpeed(); //get speed
	int getnoOfMissions(); //get Number of Missions The Rover Executed
	int getNoOfCheckUps(); //get Number of Checkups the rovers underwent
	void setMaintenance(bool x);
	bool geMaintenance(); //Check if used
	void setCheukDuration(int days);//set days nedded in check up
	int getCheukDuration(); //get days nedded in check up
	int getID(); //get Rover ID
	virtual ~Rover();
};