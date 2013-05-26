/* Functions for computing Kickstart checksum, inspired by similar 
 * stuff in EmuTOS. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <arpa/inet.h>

#include "sum.h"

#define VECNO 8
#define VECFIRST 0x18

struct kickcrc {
	uint32_t checksum;
	uint32_t romsize;
	uint16_t exv[VECNO];
};

uint32_t 
sum_addc(uint32_t a, uint32_t b)
{
	uint32_t c;

	c = a + b;

	if (c < a)
		c++;

	return c;
}

uint32_t
sum_compute(int fd, size_t romsize)
{
	size_t i;
	uint32_t longword_be, longword, sum;

	sum = 0;
	i = 0;

	if (lseek(fd, 0, SEEK_SET)) {
		fprintf(stderr, "error seeking to begnning of ROM\n");
	}

	while (i < romsize) {
		read(fd, &longword_be, sizeof(uint32_t));
		i += sizeof(uint32_t);
		longword = ntohl(longword_be);
		sum = sum_addc(sum, longword);	
	}

	return sum;
}

void
sum_write(int fd, size_t romsize)
{
	uint32_t csum;
	struct kickcrc footer;
	int i;

	footer.checksum = 0;
	footer.romsize = htonl(romsize);
	for (i = 0; i < VECNO; i++) {
		footer.exv[i] = htons(VECFIRST + i);	
	}

	lseek(fd, romsize - sizeof(struct kickcrc), SEEK_SET);
	write(fd, &footer, sizeof(footer));	

	/* Compute checksum and write the footer again. */
	csum = (0xffffffff - sum_compute(fd, romsize));
	footer.checksum = htonl(csum);
	lseek(fd, romsize - sizeof(struct kickcrc), SEEK_SET);
	write(fd, &footer, sizeof(footer));	
}

