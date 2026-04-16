/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_strcapitalize.c                            #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/16 13:26:04 by absolute     ##               #+#        */
/*   Updated: 2026/04/16 13:26:04 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	size_t	i;
	size_t	new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			if (new_word)
				str[i] = ft_toupper(str[i]);
			else
				str[i] = ft_tolower(str[i]);
			new_word = 0;
		}
		else if (ft_isdigit(str[i]))
			new_word = 0;
		else
			new_word = 1;
		i++;
	}
	return (str);
}
