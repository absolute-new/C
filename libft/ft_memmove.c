/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_memmove.c                                   #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/17 13:15:06 by absolute     ##               #+#        */
/*   Updated: 2025/09/17 13:15:07 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (n <= 0)
		return (dest);
	if (ptr_dest == ptr_src)
		return (dest);
	if (ptr_dest < ptr_src)
		while (n--)
			*ptr_dest++ = *ptr_src++;
	else
	{
		ptr_dest += n;
		ptr_src += n;
		while (n--)
			*--ptr_dest = *--ptr_src;
	}
	return (dest);
}
