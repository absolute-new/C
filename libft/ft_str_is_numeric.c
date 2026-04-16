/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_str_is_numeric.c                           #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/16 14:10:47 by absolute     ##               #+#        */
/*   Updated: 2026/04/16 14:10:47 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_numeric(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
