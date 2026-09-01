#include "file_handler.h"
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int		file_open(char const *filename)
{
	int	fd;

	fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR
			| S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fd == -1)
	{
		fprintf(stderr, "cannot open file: %s %s\n", filename, strerror(errno));
		exit(1);
	}
	return (fd);
}

void	do_read(int fd, char *arg, char type)
{
	size_t	len;
	ssize_t	num_read;
	char	*buf;

	len = get_offset(&arg[1]);
	buf = malloc(len);
	if (buf == NULL)
	{
		fprintf(stderr, "malloc error\n");
		exit(1);
	}
	num_read = read(fd, buf, len);
	if (num_read == -1)
	{
		fprintf(stderr, "read error: %s\n", strerror(errno));
		free(buf);
		exit(1);
	}
	if (num_read == 0)
		printf("%s: end file\n", arg);
	else
	{
		printf("%s: ", arg);
		for (int j = 0; j < num_read; ++j)
		{
			if (type == 'r')
				printf("%c", isprint((unsigned char)buf[j]) ? buf[j] : '?');
			else
				printf("%02x ", (unsigned char)buf[j]);
		}
		printf("\n");
	}
	free(buf);
}

void	do_write(int fd, char *arg)
{
	ssize_t	num_writen;

	num_writen = write(fd, &arg[1], strlen(&arg[1]));
	if (num_writen == -1)
	{
		fprintf(stderr, "write error: %s\n", strerror(errno));
		exit(1);
	}
	printf("%s: wrote %ld bytes\n", arg, (long)num_writen);
}

void	do_seek(int fd, char *arg)
{
	long	offset;

	offset = get_offset(&arg[1]);
	if (lseek(fd, offset, SEEK_SET) == -1)
	{
		fprintf(stderr, "lseek error: %s\n", strerror(errno));
		exit(1);
	}
	printf("%s: seek succeeded\n", arg);
}

long	get_offset(char *str)
{
	return (atol(str));
}
