/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_strchr.c                                    #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/25 17:32:47 by absolute     ##               #+#        */
/*   Updated: 2025/09/25 17:32:48 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}
