/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_putptr.c                                   #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/23 13:12:33 by absolute     ##               #+#        */
/*   Updated: 2026/04/23 13:12:33 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)ptr;
	count = ft_putstr("0x");
	count += ft_puthex(addr, 0);
	return (count);
}
