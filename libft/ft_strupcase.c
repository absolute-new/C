/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_strupcase.c                                #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/17 06:23:18 by absolute     ##               #+#        */
/*   Updated: 2026/04/17 06:23:18 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_islower(str[i]))
			str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
