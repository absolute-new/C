/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_memccpy.c                                   #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/17 11:38:54 by absolute     ##               #+#        */
/*   Updated: 2025/09/17 11:38:55 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int stop_char, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	unsigned char	stop_ch;

	if (!dest && !src)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	stop_ch = (unsigned char)stop_char;
	while (n--)
	{
		*ptr_dest = *ptr_src;
		if (*ptr_src == stop_ch)
			return (ptr_dest + 1);
		ptr_dest++;
		ptr_src++;
	}
	return (NULL);
}
