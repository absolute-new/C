/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_lstiter.c                                  #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/15 14:10:15 by absolute     ##               #+#        */
/*   Updated: 2026/04/15 14:10:15 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
