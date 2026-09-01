#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE	1024

static int	open_in_file(char const *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "cannot open file %s: %s\n", filename, strerror(errno));
		exit(1);
	}
	return (fd);
}

static int	open_out_file(char const *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		fprintf(stderr, "cannot open file %s: %s\n", filename, strerror(errno));
		exit(1);
	}
	return (fd);
}

static void	read_file(int in_fd, int out_fd)
{
	char	buffer[BUFF_SIZE];
	int		bytes_read;
	int		bytes_write;

	while (1)
	{
		bytes_read = read(in_fd, buffer, BUFF_SIZE);
		if (bytes_read == -1)
		{
			fprintf(stderr, "read error: %s\n", strerror(errno));
			close(in_fd);
			close(out_fd);
			exit(1);
		}
		if (bytes_read == 0)
			break ;
		bytes_write = write(out_fd, buffer, bytes_read);
		if (bytes_read != bytes_write)
		{
			fprintf(stderr, "write error: %s\n", strerror(errno));
			close(in_fd);
			close(out_fd);
			exit(1);
		}
	}
}

static void	close_files(int in_fd, int out_fd)
{
	if (close(in_fd) == -1)
	{
		fprintf(stderr, "close error: %s\n", strerror(errno));
		exit(1);
	}
	if (close(out_fd) == -1)
	{
		fprintf(stderr, "close error: %s\n", strerror(errno));
		exit(1);
	}
}

int	main(int ac, char *av[])
{
	int	in_fd;
	int	out_fd;

	if (ac != 3)
	{
		fprintf(stderr, "Usage: %s <old-file> <new-file>\n", av[0]);
		return (1);
	}
	in_fd = open_in_file(av[1]);
	out_fd = open_out_file(av[2]);
	read_file(in_fd, out_fd);
	close_files(in_fd, out_fd);
	printf("File copied successfully!\n");
	return (0);
}
