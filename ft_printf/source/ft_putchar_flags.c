/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_putchar_flags.c                            #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/05/17 05:47:20 by absolute     ##               #+#        */
/*   Updated: 2026/05/17 05:47:20 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fill_width(t_flags flags)
{
	int	count;

	count = 0;
	while (flags.width > 1)
	{
		count += ft_putchar(' ');
		flags.width--;
	}
	return (count);
}

int	ft_putchar_flags(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width <= 1)
		return (ft_putchar(c));
	if (flags.minus)
	{
		count += ft_putchar(c);
		count += ft_fill_width(flags);
	}
	else
	{
		count += ft_fill_width(flags);
		count += ft_putchar(c);
	}
	return (count);
}
