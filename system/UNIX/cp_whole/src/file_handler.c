#include "file_handler.h"
#include <unistd.h>
#include <fcntl.h>	// open
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int	file_open(char const *filename, int mode)
{
	int	fd;

	if (mode == 1)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			fprintf(stderr, "cannot open file: %s\n", filename);
			exit(1);
		}
	}
	else if (mode == 2)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			fprintf(stderr, "cannot open file: %s\n", filename);
			exit(1);
		}
	}
	return (fd);
}

void	read_file(int input_fd, int output_fd)
{
	int	bytes_read;
	char	buffer[BUFF_SIZE];

	while (1)
	{
		bytes_read = read(input_fd, buffer, BUFF_SIZE);
		if (bytes_read == -1)
		{
			fprintf(stderr, "read error: %s\n", strerror(errno));
			exit(1);
		}
		if (bytes_read == 0)
			break ;
		write_file(output_fd, buffer, bytes_read);
	}
}

void	write_file(int fd, char const *buffer, int bytes_read)
{
	int	i;
	int	zero_count;
	int	bytes_written;

	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == 0)
		{
			zero_count = 0;
			while (i + zero_count < bytes_read && buffer[i + zero_count] == 0)
				zero_count++;
			if (lseek(fd, zero_count, SEEK_CUR) == -1)
			{
				fprintf(stderr, "lseek error: %s\n", strerror(errno));
				exit(1);
			}
			i += zero_count;
		}
		else
		{
			bytes_written = write(fd, &buffer[i], 1);
			if (bytes_written != 1)
			{
				fprintf(stderr, "write error: %s\n", strerror(errno));
				exit(1);
			}
			i++;
		}
	}
}