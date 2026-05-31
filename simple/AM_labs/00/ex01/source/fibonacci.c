#include "fibonacci.h"
#include <stdlib.h>

int	fibonacci(int n)
{
	int	i;
	int	*dp;
	int	result;

	if (n <= 1)
		return (n);
	dp = (int *)malloc((n + 1) * sizeof(int));
	if (!dp)
		return (-1);
	dp[0] = 0;
	dp[1] = 1;
	i = 2;
	while (i <= n)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		++i;
	}
	result = dp[n];
	free(dp);
	return (result);
}
