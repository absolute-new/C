#include "file_handler.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define SOURCE	1
#define DEST	2

static void	parse_args(int ac, char *av[])
{
	if (ac != 3)
	{
		fprintf(stderr, "Usage: %s <source> <destination>\n", av[0]);
		exit(1);
	}

}

int	main(int ac, char *av[])
{
	int	input_fd;
	int	output_fd;

	parse_args(ac, av);
	input_fd = file_open(av[1], SOURCE);
	output_fd = file_open(av[2], DEST);
	read_file(input_fd, output_fd);
	if (close(input_fd) == -1)
	{
		fprintf(stderr, "close error: %s\n", strerror(errno));
		return (1);
	}
	if (close(output_fd) == -1)
	{
		fprintf(stderr, "close error: %s\n", strerror(errno));
		return (1);
	}


	return (0);
}