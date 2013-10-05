/* MX29LV640 flash commands in word mode */

#define MX29LV640_RESET		0xF0

#define MX29LV640_CMD_OFF1	0x555
#define MX29LV640_CMD_OFF2	0x2AA
#define MX20LV640_CMD_OFF3	0x555

#define MX20LV640_CMD_DATA1	0xAA
#define MX20LV640_CMD_DATA2	0x55
#define MX20LV640_CMD_AS	0x90	/* enter automatic select mode */

#define MX20LV640_AS_VENDOR	0x0
#define MX20LV640_AS_DEVICE	0x1
#define MX20LV640_AS_SECURED	0x3
#define MX20LV640_AS_PROTECT	0x2	/* + sector address */

#define MX20LV640_CFI_OFF	0x55
#define MX20LV640_CFI_QUERY	0x98

