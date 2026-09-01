#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "file_handler.h"

static void	parse_args(int fd, int ac, char *av[])
{
	int	ap;

	ap = 2;
	while (ap < ac)
	{
		switch (av[ap][0])
		{
		case 'r':
		case 'R':
			do_read(fd, av[ap], av[ap][0]);
			break;
		case 'w':
			do_write(fd, av[ap]);
			break;
		case 's':
			do_seek(fd, av[ap]);
			break;
		default:
			fprintf(stderr, "Argument must start with [rRws]: %s\n", av[ap]);
			exit(1);
		}
		ap++;
	}
}

int	main(int ac, char *av[])
{
	int	fd;

	if (ac < 3)
	{
		fprintf(stderr, "Usage %s: <file> {r<length>|\
			R<length>|w<string>|s<offset>}...\n", av[0]);
		return (1);
	}
	fd = file_open(av[1]);
	parse_args(fd, ac, av);
	if (close(fd) == -1)
	{
		fprintf(stderr, "close error: %s\n", strerror(errno));
		return (1);
	}
	return (0);
}
