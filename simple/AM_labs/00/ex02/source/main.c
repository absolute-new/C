#include <stdio.h>
#include <limits.h>

static int	min(int a, int b)
{
	int mask;

	mask = (a < b) * -1;
	return ((a & mask) | (b & ~mask));
}

static int	max(int a, int b)
{
	int mask;

	mask = (a < b) * -1;
	return ((b & mask) | (a & ~mask));
}

int	main(void)
{
	int	count;
	int	sum;
	int	min_n;
	int	max_n;
	int	even;
	int	odd;
	int	ch;
	int	n;
	int	is_number;
	int	sign;

	is_number = 0;
	count = 0;
	sum = 0;
	n = 0;
	min_n = INT_MAX;
	max_n = INT_MIN;
	odd = 0;
	even = 0;
	sign = 1;
	while ((ch = getchar()) != EOF && ch != '\n')
	{		
		if (ch >= '0' && ch <= '9')
		{
			n = n * 10 + (ch - '0');
			is_number = 1;
		}
		else if (ch == '-')
			sign = -1;
		else if (ch == ' ' && is_number)
		{
			n = n * sign;
			count++;
			sum += n;
			odd += (n & 1);
			even += !(n & 1);
			min_n = min(min_n, n);
			max_n = max(max_n, n);
			n = 0;
			sign = 1;
			is_number = 0;
		}		
	}
	if (is_number)
	{
		n = n * sign;
		count++;
		sum += n;
		odd += (n & 1);
		even += !(n & 1);
		min_n = min(min_n, n);
		max_n = max(max_n, n);
	}
	if (!count)
		printf("Count:\t%d\nSum:\t%d\n", count, sum);
	else
		printf("Count:\t%d\nSum:\t%d\nMin:\t%d\nMax:\t%d\nEven:\t%d\nOdd:\t%d\n",
			count, sum, min_n, max_n, even, odd);
	return (0);
}