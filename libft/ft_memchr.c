/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_memchr.c                                    #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/17 17:09:29 by absolute     ##               #+#        */
/*   Updated: 2025/09/17 17:09:30 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr_str;
	unsigned char	ch;

	ch = (unsigned char)c;
	ptr_str = (unsigned char *)str;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if (*ptr_str == ch)
			return ((void *)ptr_str);
		ptr_str++;
	}
	return (NULL);
}
