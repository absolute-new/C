/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_puthex.c                                   #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/23 13:18:29 by absolute     ##               #+#        */
/*   Updated: 2026/04/23 13:18:29 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, int upcase)
{
	char	*hex_lower;
	char	*hex_upper;
	int		count;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, upcase);
	if (upcase)
		count += ft_putchar(hex_upper[n % 16]);
	else
		count += ft_putchar(hex_lower[n % 16]);
	return (count);
}
