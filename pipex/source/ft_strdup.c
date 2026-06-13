/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_strdup.c                                   #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/06/08 19:33:26 by absolute     ##               #+#        */
/*   Updated: 2026/06/08 19:33:26 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;

	len = ft_strlen(s1);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
