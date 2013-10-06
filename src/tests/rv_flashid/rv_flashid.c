#include <stdio.h>
#include <stdlib.h>

#include <exec/types.h>
#include <exec/execbase.h>

#include <proto/dos.h>
#include <proto/exec.h>

#include "config.h"

#include "hardware.h"
#include "flash.h"

int
main(int argc, char *argv[])
{
	rv_flash_detect();
	return 0;
}

