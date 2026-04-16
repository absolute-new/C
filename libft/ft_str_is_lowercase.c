/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_str_is_lowercase.c                         #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/16 14:06:15 by absolute     ##               #+#        */
/*   Updated: 2026/04/16 14:06:15 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_lowercase(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_islower(str[i]))
			return (0);
		i++;
	}
	return (1);
}
