
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Motor.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Motor(struct FB_Motor* inst)
{
	inst->Integrator.in = (inst->u / inst->ke - inst->w) / inst->Tm;
	FB_Integrator(&inst->Integrator);
	inst->w = inst->Integrator.out;
	inst->phi += inst->w * inst->dt;
}
