/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_itoa.c                                     #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/12 13:02:49 by absolute     ##               #+#        */
/*   Updated: 2026/04/12 13:02:49 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;
	len = ft_numlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	len--;
	while (len >= 0 && str[len] != '-')
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (str);
}
