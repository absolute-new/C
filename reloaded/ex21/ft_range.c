/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_range.c                                     #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/12 06:27:16 by absolute     ##               #+#        */
/*   Updated: 2025/09/12 06:27:17 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	if (min >= max)
		arr = NULL;
	else
	{
		size = max - min;
		arr = (int *) malloc(sizeof(int) * size);
		if (arr)
		{
			i = 0;
			while (i < size)
			{
				arr[i] = min + i;
				i++;
			}
		}
	}
	return (arr);
}
