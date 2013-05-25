/* Create fake Kickstart image from fkload image built by vasm/vlink. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>

#define KICKSIZE 1024*512

struct kickcrc {
	uint32_t checksum;
	uint32_t romsize;
	uint16_t exv[8];
};

static void process_rom(int, int);
static uint32_t mksum(int);
static void pad(int, int, size_t, size_t);
static void copy(int, int);

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
		fprintf(stderr, "error opening rom file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	} 

	process_rom(ifd, ofd);

	close(ifd);
	close(ofd);
}

/* Create padded Kickstart image */
static void
process_rom(int ifd, int ofd)
{
	struct stat ifstat;

	if (fstat(ifd, &ifstat) == -1) {
		fprintf(stderr, "error stating input file\n");
	}

	copy(ifd, ofd);
	/* pad with zeroes */
	pad(ifd, ofd, ifstat.st_size, KICKSIZE);
	//mksum(ifd);

}

static void
pad(int ifd, int ofd, size_t romsize, size_t padtosize)
{
	int i;
	char c[1];

	c[0] = '\0';
    
	lseek(ofd, romsize, SEEK_SET);
    
	for (i = romsize; i < padtosize; i++) {
		write(ofd, c, 1);
	}
}

static void
copy(int ifd, int ofd)
{
	int n;
	char c[1];

	while ((n = read(ifd, c, 1)) > 0)
		write(ofd, c, n);	

}

/* Compute Kickstart checksum */
static uint32_t
mksum(int fd)
{
	/* compute checksum */
	return 0;	
}

