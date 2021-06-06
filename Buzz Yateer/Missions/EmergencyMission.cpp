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
	return 4 * getSignificance() - 3 * getFormulationDay() + 0.1 * getTargetLocation() - getMDUR();
}

EmergencyMission::~EmergencyMission()
{
}
