/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_lstlast.c                                  #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/15 13:50:14 by absolute     ##               #+#        */
/*   Updated: 2026/04/15 13:50:14 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
