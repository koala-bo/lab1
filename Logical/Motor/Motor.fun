
{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FB_Integrator (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		in : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR_OUTPUT
		out : {REDUND_UNREPLICABLE} REAL := 0.0;
	END_VAR
	VAR CONSTANT
		dt : REAL := 0.1;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Motor (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		u : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR_OUTPUT
		w : REAL;
		phi : REAL;
	END_VAR
	VAR
		Integrator : FB_Integrator;
		Tm : REAL;
		ke : REAL;
	END_VAR
	VAR CONSTANT
		dt : REAL := 0.1;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Regulator (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		e : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR_OUTPUT
		u : REAL;
	END_VAR
	VAR
		k_p : REAL;
		k_i : REAL;
		integrator : FB_Integrator;
		iyOld : REAL;
		max_abs_value : REAL;
	END_VAR
	VAR CONSTANT
		dt : REAL := 0.1;
	END_VAR
END_FUNCTION_BLOCK
