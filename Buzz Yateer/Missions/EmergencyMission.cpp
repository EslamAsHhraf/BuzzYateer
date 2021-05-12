#include "EmergencyMission.h"

EmergencyMission::EmergencyMission()
{
}

EmergencyMission::EmergencyMission(int F ,int D ,int S ,int TL ,int id )
	:Mission(F ,D ,S ,TL ,id)
{
	

}

int EmergencyMission::calcPriority()
{
	return 0;
}

int EmergencyMission::calcduration()
{
	return 1;
}
