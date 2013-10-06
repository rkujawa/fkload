#include <stdio.h>

#include <exec/types.h>

#include "hardware.h"
#include "mx29lv640.h"
#include "config.h"
#include "flash.h"

static ULONG
rv_mk_dword_same(USHORT val)
{
	ULONG dword;
	dword = val | (val << RV_2NDROM_SHIFT);

	return dword;
}

void 
rv_flash_detect(void) 
{
	ULONG vendorid, deviceid;

	rv_flash_bank_set(0);
	rv_flash_reset();

	rv_flash_write(MX29LV640_CMD_OFF1, rv_mk_dword_same(MX29LV640_CMD_DATA1));
	rv_flash_write(MX29LV640_CMD_OFF2, rv_mk_dword_same(MX29LV640_CMD_DATA2));
	rv_flash_write(MX29LV640_CMD_OFF3, rv_mk_dword_same(MX29LV640_CMD_AS));

	vendorid = rv_flash_read(MX29LV640_AS_VENDOR);
	deviceid = rv_flash_read(MX29LV640_AS_DEVICE);

	/* XXX */
	printf("Vendor ID: %x, Device id: %x\n", vendorid, deviceid);

	rv_flash_reset();
}

void 
rv_flash_bank_set(UBYTE banknum) 
{
	ULONG *banksel;

	banksel = RV_BANK_SEL;

#ifdef DEBUG
	printf("DEBUG: changing flash bank to %d\n", banknum);
#endif /* DEBUG */

	*banksel = banknum;
}

void 
rv_flash_reset(void) 
{
#ifdef DEBUG
	printf("DEBUG: resetting the flash\n");
#endif /* DEBUG */
	rv_flash_write(0, rv_mk_dword_same(MX29LV640_RESET));
}

void 
rv_flash_write(ULONG offset, ULONG value) 
{
	ULONG *addr;
	addr = RV_BANK_WINDOW + offset; /* XXX: for now */
#ifdef DEBUG_RW
	printf("DEBUG_RW: write %x to %x\n", value, addr);	
#endif /* DEBUG_RW */
	*addr = value;
}

ULONG 
rv_flash_read(ULONG offset) 
{
	ULONG rv;
	ULONG *addr;

	addr = RV_BANK_WINDOW + offset; /* XXX: for now */
	rv = *addr;
#ifdef DEBUG_RW
	printf("DEBUG_RW: read %x from %x\n", rv, addr);	
#endif /* DEBUG_RW */

	return rv;
}

