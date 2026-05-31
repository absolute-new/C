#include "binary_search.h"
#include <stdio.h>

int	binary_search(int ch, int *low, int *high)
{
	int	mid;

	mid = *low + (*high - *low) / 2;
	if (ch == '=')
		return (0);
	else if (ch == '>')
		*low = mid + 1;
	else if (ch == '<')
		*high = mid - 1;
	else
		return (1);
	if (*low > *high)
		return (1);
	return (0);
}
