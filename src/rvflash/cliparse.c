/*
* AmigaOS ReadArgs-style argument parsing is an inconsistent shit.
* Pile of shit. Period.
*
* Try to work this around by providing a saner API.
*/

#include <stdio.h>
#include <stdlib.h>

#include <exec/types.h>
#include <exec/execbase.h>
#include <workbench/startup.h>

#include <proto/dos.h>
#include <proto/exec.h>

#include "config.h"
#include "cliparse.h"

#define MAX_TEMPLATE_LEN	256

struct arg_def {
	CONST_STRPTR name;
	UBYTE opttype;
}

static LONG *arg_array;		/* arguments passed on the command line */
static struct RDArgs *arg_res;
static STRPTR arg_template;	/* should be const? */
static UBYTE arg_num;		/* how many arugments are there? */

static struct arg_def

static UBYTE
arg_find_no_by_name(CONST_STRPTR name) 
{
	
}

BOOL
arg_switch_isempty(UBYTE argNo)
{
	if ( ((LONG) argArray[argNo] != 0))
		return 0;

	return 1;
}

BOOL
arg_toggle_val(UBYTE argNo)
{
#define TOGGLE_EMPTY	-2
#define TOGGLE_FALSE	0x0
#define TOGGLE_TRUE	0xFFFFFFFF
	if ((LONG) argArray[argNo] == TOGGLE_TRUE)
		return 1;
	else if ((LONG) argArray[argNo] == TOGGLE_FALSE)
		return 0;
#ifdef DEBUG
	else
		/* I wonder if we'll observe one of these, duh. */
		printf("DEBUG: toggle neither TRUE nor FALSE, this should not happen!\n");
#endif /* DEBUG */

	return 0;
}

BOOL
arg_key_isempty(UBYTE argNo)
{
	if ((LONG) argArray[argNo] == 0)
		return 1;
	else
		return 0;
}

BOOL
arg_toggle_isempty(UBYTE argNo)
{
	if ((LONG) argArray[argNo] != TOGGLE_EMPTY)
		return 0;	
	else
		return 1;
}

void
arg_template_add(STRPTR optname, UBYTE opttype)
{
	/* add FOO/X, to template */
}

BOOL
arg_init()
{

	argArray = AllocVec(argNum*sizeof(LONG), MEMF_ANY|MEMF_CLEAR);

	/* for all BOOLs initialize argArray to TOGGLE_EMPTY */
	/* argArray[argNo] = TOGGLE_EMPTY; */

	rares = ReadArgs(argTemplate, argArray, NULL);
}

void
arg_cleanup()
{
	FreeArgs(rares);
	FreeVec(argArray);
}

