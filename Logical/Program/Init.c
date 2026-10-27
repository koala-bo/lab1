
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	counter = 0;
	
	fb_motor.dt = 0.01f;
	fb_motor.Tm = 0.5f;
	fb_motor.ke = 0.1f;
	fb_motor.w = 0.0f;
	fb_motor.phi = 0.0f;
	fb_motor.Integrator.out = 0.0f;
	
	fb_motor2.dt = 0.01f;
	fb_motor2.Tm = 0.5f;
	fb_motor2.ke = 0.1f;
	fb_motor2.w = 0.0f;
	fb_motor2.phi = 0.0f;
	fb_motor2.Integrator.out = 0.0f;
	
	float Tj = 0.15f;
	fb_controller.dt = 0.01f;
	fb_controller.iyOld = 0.0f;
	fb_controller.max_abs_value = 200.0f;
	fb_controller.k_p = fb_motor.ke * fb_motor.Tm / Tj;
	fb_controller.k_i = fb_motor.ke / Tj;
	fb_controller.integrator.out = 0.0f;
	
	Speed = 0.0f;
	Enable = 1;	
}
