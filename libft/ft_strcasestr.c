/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_strcasestr.c                               #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/16 13:51:22 by absolute     ##               #+#        */
/*   Updated: 2026/04/16 13:51:22 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j]
			&& ft_tolower(haystack[i + j])
			== ft_tolower(needle[j]))
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
