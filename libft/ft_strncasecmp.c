/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_strncasecmp.c                              #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/17 06:27:47 by absolute     ##               #+#        */
/*   Updated: 2026/04/17 06:27:47 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
			return ((unsigned char)ft_tolower(s1[i])
				- (unsigned char)ft_tolower(s2[i]));
		i++;
	}
	if (i < n)
		return ((unsigned char)ft_tolower(s1[i])
			- (unsigned char)ft_tolower(s2[i]));
	return (0);
}
