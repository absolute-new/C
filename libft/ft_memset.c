/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_memset.c                                    #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/14 06:09:09 by absolute     ##               #+#        */
/*   Updated: 2025/09/14 06:09:10 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*ptr_res;

	ptr_res = (unsigned char *)ptr;
	while (num-- > 0)
		*ptr_res++ = (unsigned char)value;
	return (ptr);
}
