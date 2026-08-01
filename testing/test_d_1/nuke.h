#ifndef NUKE_H
# define NUKE_H

# include <stdint.h>
# include <stdio.h>

# define MAX_COORDS	1000

typedef struct s_coords
{
	uint8_t	x;
	uint8_t	y;
}	t_coords;

FILE		*open_file(const char *filename);
uint16_t	read_file(FILE *file, t_coords *coords);
t_coords	optimal_point(const uint16_t count, const t_coords *coords,
				uint32_t radius, uint16_t *destroy);

#endif
