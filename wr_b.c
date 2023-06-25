/* wrt_b.c: This program will write chunk of data 
 * to any block of block device
 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>

#define	WRITE_BYTES	512

int main (int argc, char *argv[])	{
	int fd1, fd2;
	ssize_t nb_write;
	char data[WRITE_BYTES];

/* opening device */
	fd1 = open (argv[1], O_RDWR);
	if (fd1 == -1)	{
		perror("open1");
		exit (1);
	}

	fd2 = open (argv[2], O_RDONLY);
	if (fd2 == -1)	{
		perror ("open2");
		exit (1);
	}

/* readiing device */
	ssize_t	nb_read;
	nb_read = read (fd2, data, WRITE_BYTES);
	if (nb_read == -1)	{
		perror ("read");
		exit (1);
	} 		

/* seeking cursor to start of the file */
	off_t pos;
	pos = lseek (fd1, (off_t) 0, SEEK_SET);
	if (pos == (off_t) -1)	{
		perror ("lseek");
		exit (1);
	}

/* writing to block device */
	nb_write = write (fd1, data, WRITE_BYTES);

	if (nb_write == -1)	{
		perror ("write");
		exit (1);
	}

	close (fd1);
	close (fd2);
}
