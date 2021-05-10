#include "EmergencyMission.h"

EmergencyMission::EmergencyMission()
{
	
}

EmergencyMission::EmergencyMission(int F ,int D ,int S ,int TL ,int id ,char Status)
	:Mission(F ,D ,S ,TL ,id ,Status)
{
	

}

int EmergencyMission::calcduration()
{
	return (p->getSpeed() / (double)getTargetLocation())+ getFormulationDay()+ getDuration();
}
