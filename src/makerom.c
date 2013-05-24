/* Create fake Kickstart image from fkload image built by vasm/vlink. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>

#include <sys/stat.h>

#define KICKSIZE 1024*256

struct kickcrc {
	uint32_t checksum;
	uint32_t romsize;
	uint16_t exv[8];
};

static uint32_t mksum(int);
static void pad(int, int);

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

	if ((ofd = open(argv[2], O_RDWR|O_CREAT)) == -1) {
		fprintf(stderr, "error opening rom file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	} 

	pad(ifd, ofd);
	//mksum(ifd);
}

/* Create padded Kickstart image */
static void
pad(int ifd, int ofd)
{
	struct stat ifstat;

	if (fstat(ifd, &ifstat) == -1) {
		fprintf(stderr, "error stating input file\n");
	}

	/* pad with zeroes */

}

/* Compute Kickstart checksum */
static uint32_t
mksum(int fd)
{
	/* compute checksum */
	return 0;	
}

