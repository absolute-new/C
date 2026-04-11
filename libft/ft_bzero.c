/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_bzero.c                                     #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/14 06:39:43 by absolute     ##               #+#        */
/*   Updated: 2025/09/14 06:39:44 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	unsigned char	*ptr_res;

	ptr_res = (unsigned char *)ptr;
	while (num-- > 0)
		*ptr_res++ = 0;
}
