#include <stdio.h>
#include <stdlib.h>

#include <exec/types.h>
#include <exec/execbase.h>
#include <workbench/startup.h>

#include <proto/dos.h>
#include <proto/exec.h>

#include "config.h"
#include "hardware.h"

#define EXIT_SYNTAX_ERROR	10
#define EXIT_HARDWARE_ERROR	20 

/* -- function prototypes -- */

void reboot(void);

/* -- global variables -- */

static const STRPTR version = "\0$VER: rvtflash  0.1 (31.05.2013)\0";
static const STRPTR id = "\0$Id: a70db116c8f1631ca421860040a92b507b08e77f $\0";

int
main(int argc, char *argv[])
{
	/* add template arguments */
	/* init template */

	/*if (!arg_switch_isempty(MOREMEM_ARG)) {*/
	/*if (!arg_toggle_isempty(INSTCACHE_ARG)) {*/

	return 0;
}

/* reboot the machine */
void
reboot(void)
{
	/* think about opening graphics.library, 
	   then LoadView(); 2x WaitTOF(); to work around V39 bug */

	/* for now let's just call Exec's ColdReboot()... */
	ColdReboot();
}

