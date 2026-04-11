/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_strlcpy.c                                   #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/23 11:28:13 by absolute     ##               #+#        */
/*   Updated: 2025/09/23 11:28:14 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	n;

	if (!src || !dst)
		return (0);
	len_src = ft_strlen(src);
	if (size > 0)
	{
		if (len_src < size - 1)
			n = len_src;
		else
			n = size - 1;
		ft_memcpy(dst, src, n);
		*(dst + n) = '\0';
	}
	return (len_src);
}
