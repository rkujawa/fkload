#include "hardware.h"
#include "mx29lv640.h"
#include "config.h"

void rv_flash_detect(void) 
{
	rv_flash_bank_set(0);
	rv_flash_reset();

	/* ... */
}

void rv_flash_bank_set(UBYTE banknum) 
{
	ULONG *banksel;

	banksel = RV_BANK_SEL;

#ifdef DEBUG
	printf("DEBUG: changing flash bank to %d\n", banknum);
#endif /* DEBUG */

	*banksel = banknum;
}

void rv_flash_reset(void) 
{
#ifdef DEBUG
	printf("DEBUG: resetting the flash\n");
#endif /* DEBUG */
	rv_flash_write(0, MX29LV640_RESET);
}

void rv_flash_write(ULONG offset, ULONG value) 
{
	ULONG *addr;
	addr = RV_BANK_WINDOW + offset;
#ifdef DEBUG_RW
	printf("DEBUG_RW: write %x to %x\n", value, addr);	
#endif /* DEBUG_RW */
	*addr = value;
}

ULONG rv_flash_read(ULONG offset) 
{
	ULONG rv;
	ULONG *addr;

	addr = RV_BANK_WINDOW + offset;
	rv = *addr;
#ifdef DEBUG_RW
	printf("DEBUG_RW: read %x from %x\n", rv, addr);	
#endif /* DEBUG_RW */

	return rv;
}

