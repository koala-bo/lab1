
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
#define min(a, b) (((a) < (b)) ? (a) : (b));

void FB_Regulator(struct FB_Regulator* inst)
{
	float var1 = inst->e * inst->k_p;
	var1 = min(inst->max_abs_value, var1);
	float var2 = inst->e * inst->k_i * inst->dt;
	var2 += inst->iyOld;
	inst->integrator.in = var2;
	FB_Integrator(&inst->integrator);
	var2 = inst->integrator.out;
	
	float sum = var1 + var2;
	inst->u =  min(inst->max_abs_value, sum);
	inst->iyOld = inst->u - sum;
}
