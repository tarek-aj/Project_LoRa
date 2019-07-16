/*** Don't worry, the normal Arduino setup() and loop() are below this block! ***/
#include "arduino.h"
/* LMU uninitialised data */
StartOfUninitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have no initial values here e.g. uint32 LMU_var; */
EndOfUninitialised_LMURam_Variables

/* LMU uninitialised data */
StartOfInitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have an initial value here e.g. uint32 LMU_var_init = 1; */
EndOfInitialised_LMURam_Variables

/* If you do not care where variables end up, declare them here! */




/*** Core 0 ***/
void setup() {
  // put your setup code for core 0 here, to run once:

	SerialASC.begin(9600);

}

void loop() {
  // put your main code for core 0 here, to run repeatedly:

	delay(5); /* Make it look like this core is doing something useful! */

	/* If ASC is free lock it */
	while(Htx_LockResource(&SerialASC.PortInUse) == Htx_RESOURCE_BUSY) { ; }

	SerialASC.print("Hello from Core 0\n\r");

	Htx_UnlockResource(&SerialASC.PortInUse);

}


/*** Core 1 ***/

/* CPU1 Uninitialised Data */
StartOfUninitialised_CPU1_Variables
/* Put your CPU1 fast access variables that have no initial values here e.g. uint32 CPU1_var; */
EndOfUninitialised_CPU1_Variables

/* CPU1 Initialised Data */
StartOfInitialised_CPU1_Variables
/* Put your CPU1 fast access variables that have an initial value here e.g. uint32 CPU1_var_init = 1; */
EndOfInitialised_CPU1_Variables


void setup1() {
  // put your setup code for core 1 here, to run once:


}

void loop1() {
  // put your main code for core 1 here, to run repeatedly:

	delay(21); /* Make it look like this core is doing something useful! */

	while(Htx_LockResource(&SerialASC.PortInUse) == Htx_RESOURCE_BUSY) { ; }

	SerialASC.print("Hello from Core 1\n\r");

	Htx_UnlockResource(&SerialASC.PortInUse);

}


/*** Core 2 ***/

/* CPU2 Uninitialised Data */
StartOfUninitialised_CPU2_Variables
/* Put your CPU2 fast access variables that have no initial values here e.g. uint32 CPU2_var; */
EndOfUninitialised_CPU2_Variables

/* CPU2 Initialised Data */
StartOfInitialised_CPU2_Variables
/* Put your CPU2 fast access variables that have an initial value here e.g. uint32 CPU2_var_init = 1; */
EndOfInitialised_CPU2_Variables


void setup2() {
  // put your setup code for core 2 here, to run once:


}

void loop2() {
  // put your main code for core 2 here, to run repeatedly:

	delay(25); /* Make it look like this core is doing something useful! */

	while(Htx_LockResource(&SerialASC.PortInUse) == Htx_RESOURCE_BUSY) { ; }

	SerialASC.print("Hello from Core 2\n\r");

	Htx_UnlockResource(&SerialASC.PortInUse);

}




