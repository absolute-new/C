/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_strdup.c                                    #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/12 06:01:38 by absolute     ##               #+#        */
/*   Updated: 2025/09/12 06:01:40 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		size;
	char	*start;
	char	*str;
	char	*original_src;

	size = 0;
	original_src = src;
	while (src[size])
		size++;
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str)
	{
		start = str;
		while (*original_src)
			*start++ = *original_src++;
		*start = '\0';
	}
	return (str);
}
