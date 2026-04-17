/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_strtok.c                                   #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/17 06:02:17 by absolute     ##               #+#        */
/*   Updated: 2026/04/17 06:02:17 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*g_save = NULL;

char	*ft_strtok(char *str, const char *delim)
{
	char	*token_start;

	if (str)
		g_save = str;
	if (!g_save || !*g_save)
		return (NULL);
	while (*g_save && ft_strchr(delim, *g_save))
		g_save++;
	if (!*g_save)
		return (NULL);
	token_start = g_save;
	while (*g_save && !ft_strchr(delim, *g_save))
		g_save++;
	if (*g_save)
	{
		*g_save = '\0';
		g_save++;
	}
	return (token_start);
}
