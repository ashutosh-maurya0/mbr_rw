/* rd_b.c: This program will read the first sector of any secondary storage devices */

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

#define	BLOCK_SIZE 1000000	

int main (int argc, char *argv[])	{
	int fd1;
	int ret;

/* opening device for reading */
	fd1 = open (argv[1], O_RDONLY);
	if (fd1 == -1)
		perror("open:");

	ret = lseek (fd1, (off_t) 0, SEEK_SET);
	if (ret == (off_t) -1)
		perror("lseek:");

/* reading first sector of device */
	ssize_t	bytes_rd;
	char buf[BLOCK_SIZE];

	bytes_rd = read (fd1, buf, BLOCK_SIZE);
	if (bytes_rd == -1)
		perror("read:");


/* closing both files */

	close(fd1);

/* writing data[] to file */
	for ( int l = 0; l < BLOCK_SIZE; l++)	{
		printf("%x	", buf[l]);
	}
	printf("\n\n");
}
