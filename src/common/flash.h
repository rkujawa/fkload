#ifndef _FLASH_H_
#define _FLASH_H_

void rv_flash_detect(void); /* XXX */
void rv_flash_bank_set(UBYTE banknum);
void rv_flash_reset(void);
void rv_flash_write(ULONG offset, ULONG value);
ULONG rv_flash_read(ULONG offset);

#endif /* _FLASH_H_ */
