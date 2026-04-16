/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_itoa_base.c                                #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/16 05:20:36 by absolute     ##               #+#        */
/*   Updated: 2026/04/16 05:20:36 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_get_char(int digit)
{
	if (digit < 10)
		return ('0' + digit);
	return ('A' + (digit - 10));
}

static int	ft_count_digit(unsigned int value, int base)
{
	int	count;

	count = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base;
		count++;
	}
	return (count);
}

static void	ft_fill_result(char *result, unsigned int nb, int base, int len)
{
	result[len--] = '\0';
	while (len >= 0)
	{
		result[len--] = ft_get_char(nb % base);
		nb /= base;
	}
}

char	*ft_itoa_base(int value, int base)
{
	char			*result;
	int				len;
	unsigned int	nb;
	int				negative;

	if (base < 2 || base > 16)
		return (NULL);
	negative = 0;
	if (value < 0)
	{
		negative = (base == 10);
		nb = -value;
	}
	else
		nb = value;
	len = ft_count_digit(nb, base);
	if (negative)
		len++;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_fill_result(result, nb, base, len);
	if (negative)
		result[0] = '-';
	return (result);
}
