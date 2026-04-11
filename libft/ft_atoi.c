/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_atoi.c                                      #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/17 12:14:41 by absolute     ##               #+#        */
/*   Updated: 2025/09/17 12:14:43 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	int			result;
	const char	*ptr_str;

	result = 0;
	sign = 1;
	ptr_str = str;
	while ((*ptr_str >= '\t' && *ptr_str <= '\r') || *ptr_str == ' ')
		ptr_str++;
	if (*ptr_str == '+')
		ptr_str++;
	else if (*ptr_str == '-')
	{
		sign = -1;
		ptr_str++;
	}
	while (*ptr_str >= '0' && *ptr_str <= '9')
	{
		result = result * 10 + (*ptr_str++ - '0');
	}
	return (result * sign);
}
