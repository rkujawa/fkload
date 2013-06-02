/* Create fake Kickstart image from fkload image built by vasm/vlink. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>

#include "sum.h"

#define KICKSIZE 1024*512


static void makerom_process(int, int);
static void makerom_pad(int, int, size_t, size_t);
static void makerom_copy(int, int);

int
main(int argc, char *argv[])
{
	int ifd, ofd;

	if (argc != 3) {
		fprintf(stderr, "usage: %s image rom\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((ifd = open(argv[1], O_RDONLY)) == -1) {
		fprintf(stderr, "error opening image file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	} 

	if ((ofd = open(argv[2], O_RDWR|O_CREAT|O_TRUNC)) == -1) {
		fprintf(stderr, "error opening rom file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	} 

	makerom_process(ifd, ofd);

	fchmod(ofd, S_IRUSR|S_IWUSR|S_IROTH|S_IRGRP);

	close(ifd);
	close(ofd);
}

/* Create Kickstart from image opened in ifd, write to ofd. */
static void
makerom_process(int ifd, int ofd)
{
	struct stat ifstat;

	if (fstat(ifd, &ifstat) == -1) {
		fprintf(stderr, "error stating input file\n");
	}

	makerom_copy(ifd, ofd);
	makerom_pad(ifd, ofd, ifstat.st_size, KICKSIZE);
	sum_write(ofd, KICKSIZE);

	printf("makerom: %lld out of %d kB used\n", 
	    ifstat.st_size/1024, KICKSIZE/1024);

}

/* Pad with zeroes. */
static void
makerom_pad(int ifd, int ofd, size_t romsize, size_t makerom_padtosize)
{
	int i;
	char c[1];

	c[0] = '\0';
    
	lseek(ofd, romsize, SEEK_SET);
    
	for (i = romsize; i < makerom_padtosize; i++) {
		write(ofd, c, 1);
	}
}

static void
makerom_copy(int ifd, int ofd)
{
	int n;
	char c[1];

	while ((n = read(ifd, c, 1)) > 0)
		write(ofd, c, n);	

}


