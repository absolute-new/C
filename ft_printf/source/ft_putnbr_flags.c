/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_putnbr_flags.c                             #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/05/17 06:24:23 by absolute     ##               #+#        */
/*   Updated: 2026/05/17 06:24:23 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_put_sign(t_flags flags, int neg)
{
	if (neg)
		return (ft_putchar('-'));
	else if (flags.plus)
		return (ft_putchar('+'));
	else if (flags.space)
		return (ft_putchar(' '));
	return (0);
}

static int	ft_put_precision(t_flags flags, int n)
{
	int	count;

	count = 0;
	while (flags.dot && flags.precission > ft_numlen(n))
	{
		count += ft_putchar('0');
		flags.precission--;
	}
	return (count);
}

static int	ft_fill_width(t_flags flags, int total_len)
{
	int	count;

	count = 0;
	while (flags.width > total_len)
	{
		if (flags.zero && !flags.dot)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
		flags.width--;
	}
	return (count);
}

int	ft_putnbr_flags(int n, t_flags flags)
{
	int	count;
	int	neg;
	int	len;
	int	total_len;

	count = 0;
	if (n == INT_MIN)
		return (ft_putstr_flags("-2147483648", flags));
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	len = ft_numlen(n);
	if (flags.dot && flags.precission > len)
		len = flags.precission;
	if (n == 0 && flags.dot && flags.precission == 0)
		len = 0;
	total_len = len + (neg || flags.plus || flags.space);
	if (!flags.minus && flags.width > total_len)
		count += ft_fill_width(flags, total_len);
	count += ft_put_sign(flags, neg);
	count += ft_put_precision(flags, n);
	if (!(n == 0 && flags.dot && flags.precission == 0))
		count += ft_putnbr(n);
	if (flags.minus && flags.width > total_len)
		count += ft_fill_width(flags, total_len);
	return (count);
}
