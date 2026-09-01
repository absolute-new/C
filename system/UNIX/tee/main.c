#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "file_handler.h"
#include "tee.h"

static int	parse_args(int ac, char *av[])
{
	if (ac < 2 || ac > 3)
	{
		fprintf(stderr, "Usage: %s [-a] <file>\n", av[0]);
		exit(1);
	}
	if (ac == 3 && strcmp(av[1], "-a") == 0)
	{
		return (2);
	}
	else if (ac == 3)
	{
		fprintf(stderr, "Usage: %s [-a] <file>\n", av[0]);
		exit(1);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int	mode;
	int	fd;

	mode = parse_args(ac, av);
	fd = file_open(av[ac - 1], mode);
	copy_data(fd);
	if (close(fd) == -1)
	{
		fprintf(stderr, "close error: %s\n", strerror(errno));
		return (1);
	}
	return (0);
}