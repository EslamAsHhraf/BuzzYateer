#include "MountainousMission.h"

MountainousMission::MountainousMission(int F ,int D ,int S ,int TL ,int id ,char Status ,int AP)
	:Mission(F ,D ,S ,TL ,id, Status)
{
	autoP = AP;
}
