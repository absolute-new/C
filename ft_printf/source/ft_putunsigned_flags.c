/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_putunsigned_flags.c                        #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/05/22 13:02:08 by absolute     ##               #+#        */
/*   Updated: 2026/05/22 13:02:08 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_len(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_put_width_left(const t_flags *flags, int total_len)
{
	int	count;
	int	width;

	width = flags->width;
	count = 0;
	if (!flags->minus && width > total_len)
	{
		while (width > total_len)
		{
			if (flags->zero && !flags->dot)
				count += ft_putchar('0');
			else
				count += ft_putchar(' ');
			width--;
		}
	}
	return (count);
}

static int	ft_put_width_right(const t_flags *flags, int total_len)
{
	int	count;
	int	width;

	width = flags->width;
	count = 0;
	if (flags->minus && width > total_len)
	{
		while (width > total_len)
		{
			count += ft_putchar(' ');
			width--;
		}
	}
	return (count);
}

static int	ft_putunsigned_rec(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned_rec(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

static int	ft_putunsigned_with_precission(unsigned int n, t_flags flags)
{
	int	count;
	int	zeros;
	int	real_len;

	count = 0;
	if (!(flags.dot && flags.precission == 0 && n == 0))
	{
		real_len = ft_unsigned_len(n);
		if (flags.dot && flags.precission > real_len)
		{
			zeros = flags.precission - real_len;
			while (zeros--)
				count += ft_putchar('0');
		}
		count += ft_putunsigned_rec(n);
	}
	return (count);
}

int	ft_putunsigned_flags(unsigned int n, t_flags flags)
{
	int	count;
	int	len;
	int	total_len;

	count = 0;
	len = ft_unsigned_len(n);
	if (flags.dot && flags.precission == 0 && n == 0)
		len = 0;
	if (flags.dot && flags.precission > len)
		len = flags.precission;
	total_len = len;
	count += ft_put_width_left(&flags, total_len);
	count += ft_putunsigned_with_precission(n, flags);
	count += ft_put_width_right(&flags, total_len);
	return (count);
}
