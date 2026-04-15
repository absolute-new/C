/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_lstdelone.c                                #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/15 14:00:50 by absolute     ##               #+#        */
/*   Updated: 2026/04/15 14:00:50 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
