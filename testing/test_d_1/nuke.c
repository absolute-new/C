#include <stdlib.h>
#include <stdbool.h>
#include "nuke.h"

static bool	parse_args(int ac, char *av[], const char **filename,
		uint32_t *radius)
{
	int	tmp_rad;

	if (ac != 3)
	{
		fprintf(stderr, "Usage: %s <file> <radius>\n", av[0]);
		return (false);
	}
	*filename = av[1];
	tmp_rad = atoi(av[2]);
	if (tmp_rad <= 0)
	{
		fprintf(stderr, "Radius must be a positive!\n");
		return (false);
	}
	*radius = tmp_rad;
	return (true);
}

static void	print_result(t_coords point, uint16_t destroyed)
{
	printf("Optimal point: (%d, %d)\n", point.x, point.y);
	printf("Targets destroyed: %d\n", destroyed);
}

static bool	run_nuke(const char *filename, uint32_t radius)
{
	FILE		*file;
	t_coords	coords[MAX_COORDS];
	uint16_t	count;
	uint16_t	destroyed;
	t_coords	best_point;

	file = open_file(filename);
	if (!file)
		return (false);
	count = read_file(file, coords);
	if (!count)
		return (false);
	best_point = optimal_point(count, coords, radius, &destroyed);
	print_result(best_point, destroyed);
	return (true);
}

int	main(int ac, char *av[])
{
	const char	*filename;
	uint32_t	radius;

	if (!parse_args(ac, av, &filename, &radius))
		return (1);
	if (!run_nuke(filename, radius))
		return (1);
	return (0);
}
