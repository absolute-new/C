/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_strnstr.c                                   #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/14 06:44:19 by absolute     ##               #+#        */
/*   Updated: 2025/09/14 06:44:22 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr_res;
	size_t	i;
	size_t	j;

	ptr_res = NULL;
	if (*needle == '\0')
		ptr_res = (char *)haystack;
	else
	{
		i = 0;
		while (haystack[i] && i < len && !ptr_res)
		{
			j = 0;
			while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
				j++;
			if (!needle[j])
				ptr_res = (char *)&haystack[i];
			i++;
		}
	}
	return (ptr_res);
}
