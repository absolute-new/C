/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_strrchr.c                                   #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/14 06:26:50 by absolute     ##               #+#        */
/*   Updated: 2025/09/14 06:26:51 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*result;
	char	ch;

	result = NULL;
	ch = (char)c;
	while (*str)
	{
		if (*str == ch)
			result = (char *)str;
		str++;
	}
	if (ch == '\0')
		result = (char *)str;
	return (result);
}
