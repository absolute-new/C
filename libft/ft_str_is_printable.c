/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_str_is_printable.c                         #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/17 05:41:43 by absolute     ##               #+#        */
/*   Updated: 2026/04/17 05:41:43 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_printable(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isprint(str[i]))
			return (0);
		i++;
	}
	return (1);
}
