/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_putendl_fd.c                               #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/15 06:22:00 by absolute     ##               #+#        */
/*   Updated: 2026/04/15 06:22:00 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd('\n', fd);
}
