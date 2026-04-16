/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_strcasecmp.c                               #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/16 13:32:59 by absolute     ##               #+#        */
/*   Updated: 2026/04/16 13:32:59 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
			return ((unsigned char)ft_tolower(s1[i])
				- (unsigned char)ft_tolower(s2[i]));
		i++;
	}
	return ((unsigned char)ft_tolower(s1[i])
		- (unsigned char)ft_tolower(s2[i]));
}
