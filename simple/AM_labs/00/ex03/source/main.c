#include <stdio.h>
#include "binary_search.h"

int	main(void)
{
	int	mid;
	int	ch;
	int	low;
	int	high;
	int	invalid;

	low = 1;
	high = 100;
	invalid = 0;
	printf("Make up a number form 1 to 100\n");
	while (low <= high && !invalid)
	{
		mid = low + (high - low) / 2;
		printf("My guess: %d\n", mid);
		printf("Your answer (<, >, =): ");
		while ((ch = getchar()) == '\n' || ch == ' ');
		if (ch == '=')
		{
			printf("Number is guessed!\n");
			break ;
		}
		invalid = binary_search(ch, &low, &high);
		if (invalid)
			printf("Error: contradictory user answers.\n");
	}
	return (0);
}
