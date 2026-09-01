#include "file_handler.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	file_open(char const *filename, int mode)
{
	int	fd;

	if (mode == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		fprintf(stderr, "cannot open file %s: ", filename);
		exit(1);
	}
	return (fd);
}