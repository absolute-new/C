/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_str_is_uppercase.c                         #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/17 05:47:53 by absolute     ##               #+#        */
/*   Updated: 2026/04/17 05:47:53 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_uppercase(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isupper(str[i]))
			return (0);
		i++;
	}
	return (1);
}
