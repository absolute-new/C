/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_printf.c                                   #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/23 12:26:17 by absolute     ##               #+#        */
/*   Updated: 2026/04/23 12:26:17 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hundle_format(va_list args, const char spec, t_flags flags)
{
	switch (spec)
	{
		case 'c':
			return (ft_putchar_flags(va_arg(args, int), flags));
		case 's':
			return (ft_putstr_flags(va_arg(args, char *), flags));
		case 'p':
			return (ft_putptr_flags(va_arg(args, void *), flags));
		case 'd':
		case 'i':
			return (ft_putnbr_flags(va_arg(args, int), flags));
		case 'u':
			return (ft_putunsigned_flags(va_arg(args, unsigned int), flags));
		case 'x':
			return (ft_puthex_flags(va_arg(args, unsigned int), 0, flags));
		case 'X':
			return (ft_puthex_flags(va_arg(args, unsigned int), 1, flags));
		case '%':
			return (ft_putchar_flags('%', flags));
		default:
			break;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		count;
	int		ret;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_parse_flags(&format, &flags, args);
			ret = ft_hundle_format(args, *format, flags);
			if (ret == 0 && *format != '%' && !ft_strchr("cspdiuxX%", *format))
				count += ft_putchar('%') + ft_putchar(*format);
			else
				count += ret;
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
