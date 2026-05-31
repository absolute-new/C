#include <stdio.h>

int	main(void)
{
	int	ch;
	int	word;
	int	count;

	count = 0;
	word = 0;
	while ((ch = getchar()) != EOF)
	{
		if ((ch >= 'A' && ch <= 'Z')
			|| (ch >= 'a' && ch <= 'z')
			|| (ch >= '0' && ch <= '9'))
		{
			if (!word)
			{
				count++;
				word = 1;
			}
		}
		else
			word = 0;
	}
	printf("%d\n", count);
	return (0);
}
