/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_strlowcase.c                               #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/16 14:15:02 by absolute     ##               #+#        */
/*   Updated: 2026/04/16 14:15:02 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
