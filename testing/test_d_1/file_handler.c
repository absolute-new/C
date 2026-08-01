#include "nuke.h"

FILE	*open_file(const char *filename)
{
	FILE	*file;

	file = fopen(filename, "r");
	if (!file)
		fprintf(stderr, "Cannot open file: %s\n", filename);
	return (file);
}

uint16_t	read_file(FILE *file, t_coords *coords)
{
	uint16_t	count;
	short		tmp_x;
	short		tmp_y;

	count = 0;
	while (fscanf(file, "%hd,%hd", &tmp_x, &tmp_y) == 2)
	{
		if (tmp_x >= 0 && tmp_x <= 99
			&& tmp_y >= 0 && tmp_y <= 99)
		{
			coords[count].x = tmp_x;
			coords[count].y = tmp_y;
			count++;
		}
		if (count >= MAX_COORDS)
			break ;
	}
	fclose(file);
	return (count);
}
