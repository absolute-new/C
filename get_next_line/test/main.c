/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   main.c                                        #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/20 21:03:21 by absolute     ##               #+#        */
/*   Updated: 2026/04/20 21:03:21 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "../get_next_line_bonus.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	printf("---------------------------\nBUFFER_SIZE\t=\t%llu\n---------------------------\n", (unsigned long long int)BUFFER_SIZE);
	printf("---------------------------\nINT_MAX\t\t=\t%d\nLONG_MAX\t=\t%ld\nLL_MAX\t\t=\t%lld\nULL_MAX\t\t=\t%llu\n---------------------------\n", INT_MAX, LONG_MAX, LLONG_MAX, ULLONG_MAX);
	if (argc != 2)
	{
		printf("File not found.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error read file.\n");
		return (0);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
