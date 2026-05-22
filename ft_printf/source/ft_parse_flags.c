/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_parse_flags.c                              #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/05/17 05:30:21 by absolute     ##               #+#        */
/*   Updated: 2026/05/17 05:30:21 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_dot(const char **format, t_flags *flags)
{
	flags->dot = 1;
	(*format)++;
	if (ft_isdigit(**format))
		flags->precission = ft_atoi(format);
	else
		flags->precission = 0;
}

static void	ft_handle_flag(const char **format, t_flags *flags)
{
	if (**format == '-')
		flags->minus = 1;
	else if (**format == '0')
		flags->zero = 1;
	else if (**format == '#')
		flags->hash = 1;
	else if (**format == ' ')
		flags->space = 1;
	else if (**format == '+')
		flags->plus = 1;
}

void	ft_parse_flags(const char **format, t_flags *flags, va_list args)
{
	ft_init_flags(flags);
	while (**format && ft_strchr("-0.# +", **format))
	{
		if (**format == '.')
		{
			ft_handle_dot(format, flags);
			continue ;
		}
		ft_handle_flag(format, flags);
		(*format)++;
	}
	if (ft_isdigit(**format))
		flags->width = ft_atoi(format);
	else if (**format == '*')
	{
		(*format)++;
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width = -flags->width;
		}
	}
}
