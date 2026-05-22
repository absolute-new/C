/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_putptr_flags.c                             #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/05/22 10:40:54 by absolute     ##               #+#        */
/*   Updated: 2026/05/22 10:40:54 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fill_len_ptr(unsigned long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

static int	ft_putptr_hex(unsigned long n, t_flags flags)
{
	int	count;
	int	len;
	int	zeros;

	len = ft_fill_len_ptr(n);
	count = 0;
	if (flags.dot && flags.precission == 0 && n == 0)
		return (0);
	if (flags.dot && flags.precission > len)
	{
		zeros = flags.precission - len;
		while (zeros--)
			count += ft_putchar('0');
	}
	count += ft_puthex(n, 0);
	return (count);
}

static int	ft_put_width_left(const t_flags *flags, int total_len)
{
	int	count;
	int	width;

	width = flags->width;
	count = 0;
	if (!flags->minus && flags->width > total_len)
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
	if (flags->minus && flags->width > total_len)
	{
		while (width > total_len)
		{
			count += ft_putchar(' ');
			width--;
		}
	}
	return (count);
}

int	ft_putptr_flags(void *ptr, t_flags flags)
{
	unsigned long	addr;
	int				count;
	int				len;
	int				total_len;

	if (!ptr)
	{
		if (flags.dot && flags.precission == 0)
			return (ft_putstr_flags("0x", flags));
		return (ft_putstr_flags("(nil)", flags));
	}
	addr = (unsigned long)ptr;
	len = ft_fill_len_ptr(addr);
	if (flags.dot && flags.precission > len)
		len = flags.precission;
	if (addr == 0)
		len = 1;
	total_len = len + 2;
	count = 0;
	count += ft_put_width_left(&flags, total_len);
	count += ft_putstr("0x");
	count += ft_putptr_hex(addr, flags);
	count += ft_put_width_right(&flags, total_len);
	return (count);
}
