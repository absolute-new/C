/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_putstr_flags.c                             #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/05/17 06:02:15 by absolute     ##               #+#        */
/*   Updated: 2026/05/17 06:02:15 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fill_width(t_flags flags, int len)
{
	int	count;

	count = 0;
	while (flags.width > len)
	{
		if (flags.zero && !flags.minus)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
		flags.width--;
	}
	return (count);
}

static int	ft_putstr_len(char *s, int len)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		count += ft_putchar(*s);
		s++;
		len--;
	}
	return (count);
}

int	ft_putstr_flags(char *s, t_flags flags)
{
	int	count;
	int	len;

	count = 0;
	if (!s)
	{
		if (flags.dot && flags.precission < 6)
			return (0);
		s = "(null)";
	}
	len = ft_strlen(s);
	if (flags.dot && flags.precission < len)
		len = flags.precission;
	if (flags.width <= len)
		return (ft_putstr_len(s, len));
	if (flags.minus)
	{
		count += ft_putstr_len(s, len);
		count += ft_fill_width(flags, len);
	}
	else
	{
		count += ft_fill_width(flags, len);
		count += ft_putstr_len(s, len);
	}
	return (count);
}
