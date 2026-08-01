#include "nuke.h"

static uint16_t	count_hits(uint16_t count, const t_coords *coords, uint8_t cx,
		uint8_t cy, uint64_t radius_sq)
{
	uint16_t	i;
	uint16_t	hits;
	int16_t		dx;
	int16_t		dy;
	uint64_t	dist_sq;

	i = 0;
	hits = 0;
	while (i < count)
	{
		dx = cx - coords[i].x;
		dy = cy - coords[i].y;
		dist_sq = dx * dx + dy * dy;
		if (dist_sq <= radius_sq)
			hits++;
		i++;
	}
	return (hits);
}

t_coords	optimal_point(uint16_t count, const t_coords *coords,
		uint32_t radius, uint16_t *destroy)
{
	t_coords	best_point;
	uint16_t	best_count;
	uint16_t	i;
	uint16_t	hits;
	uint64_t	radius_sq;

	best_point = coords[0];
	best_count = 0;
	i = 0;
	radius_sq = radius * radius;
	while (i < count)
	{
		hits = count_hits(count, coords, coords[i].x, coords[i].y, radius_sq);
		if (hits > best_count)
		{
			best_count = hits;
			best_point = coords[i];
		}
		i++;
	}
	*destroy = best_count;
	return (best_point);
}
