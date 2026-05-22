/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_putunsigned.c                              #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/23 14:31:36 by absolute     ##               #+#        */
/*   Updated: 2026/04/23 14:31:36 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
