/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_strncmp.c                                   #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/17 11:01:48 by absolute     ##               #+#        */
/*   Updated: 2025/09/17 11:01:49 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n <= 0)
		return (0);
	else
	{
		while (n-- && *s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
	}
	if (n == (size_t)-1)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
