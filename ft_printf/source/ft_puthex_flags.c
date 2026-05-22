/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_puthex_flags.c                             #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/05/22 11:31:40 by absolute     ##               #+#        */
/*   Updated: 2026/05/22 11:31:40 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static int	ft_puthex_rec(unsigned long n, int upcase)
{
	char	*hex_lower;
	char	*hex_upper;
	int		count;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex_rec(n / 16, upcase);
	if (upcase)
		count += ft_putchar(hex_upper[n % 16]);
	else
		count += ft_putchar(hex_lower[n % 16]);
	return (count);
}

static int	ft_put_width_left(const t_flags *flags, int total_len)
{
	int	count;
	int	width;

	count = 0;
	width = flags->width;
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

	count = 0;
	width = flags->width;
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

static int	ft_puthex_with_precission(unsigned long n, int upcase,
		t_flags flags)
{
	int	count;
	int	zeros;
	int	real_len;

	count = 0;
	if (!(flags.dot && flags.precission == 0 && n == 0))
	{
		real_len = ft_hex_len(n);
		if (flags.dot && flags.precission > real_len)
		{
			zeros = flags.precission - real_len;
			while (zeros--)
				count += ft_putchar('0');
		}
		count += ft_puthex_rec(n, upcase);
	}
	return (count);
}

int	ft_puthex_flags(unsigned long n, int upcase, t_flags flags)
{
	int		count;
	int		len;
	int		total_len;

	count = 0;
	len = ft_hex_len(n);
	if (flags.dot && flags.precission == 0 && n == 0)
		len = 0;
	if (flags.dot && flags.precission > len)
		len = flags.precission;
	total_len = len;
	if (flags.hash && n != 0)
		total_len = len + 2;
	if (flags.hash && n != 0)
	{
		if (upcase)
			count += ft_putstr("0X");
		else
			count += ft_putstr("0x");
	}
	count += ft_put_width_left(&flags, total_len);
	count += ft_puthex_with_precission(n, upcase, flags);
	count += ft_put_width_right(&flags, total_len);
	return (count);
}
