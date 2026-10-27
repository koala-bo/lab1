
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	if (!Enable) return;
	fb_controller.e = Speed - fb_motor.w;
	FB_Regulator(&fb_controller);
	fb_motor.u = fb_controller.u;
	FB_Motor(&fb_motor);
	
	fb_motor2.u = Speed * fb_motor2.ke;
	FB_Motor(&fb_motor2);
	
	counter++;
	Speed = 50.0f * ((counter / 50) % 2);
}
