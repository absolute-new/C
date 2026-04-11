/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_memcpy.c                                    #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/17 10:30:20 by absolute     ##               #+#        */
/*   Updated: 2025/09/17 10:30:22 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if (!dest && !src)
		ptr_dest = dest;
	else
	{
		ptr_dest = (unsigned char *)dest;
		ptr_src = (unsigned char *)src;
		while (n--)
		{
			*ptr_dest++ = *ptr_src++;
		}
	}
	return (dest);
}
