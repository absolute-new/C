#include "tee.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void	copy_data(int fd)
{
	char	buffer[BUFF_SIZE];
	int		bytes_read;
	int		bytes_write;

	while (1)
	{
		bytes_read = read(0, buffer, BUFF_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
		{
			fprintf(stderr, "read error: %s\n", strerror(errno));
			exit(1);
		}
		bytes_write = write(1, buffer, bytes_read);
		if (bytes_write != bytes_read)
		{
			fprintf(stderr, "write to stdout error: %s\n", strerror(errno));
			exit(1);
		}
		bytes_write = write(fd, buffer, bytes_read);
		if (bytes_write != bytes_read)
		{
			fprintf(stderr, "write to file error: %s\n", strerror(errno));
			exit(1);
		}
	}
}