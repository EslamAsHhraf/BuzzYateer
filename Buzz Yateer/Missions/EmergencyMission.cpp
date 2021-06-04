#include "EmergencyMission.h"

EmergencyMission::EmergencyMission()
{
}

EmergencyMission::EmergencyMission(int F, int D, int S, int TL, int id)
	:Mission(F ,D ,S ,TL ,id)
{
	

}

int EmergencyMission::calcPriority()
{
	return 4 * getSignificance() - 3 * getFormulationDay() + 2 * getTargetLocation() - getMDUR();
}

int EmergencyMission::calcduration()
{
	return 1;
}

EmergencyMission::~EmergencyMission()
{
}
