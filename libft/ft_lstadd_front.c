/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_lstadd_front.c                             #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/15 13:37:41 by absolute     ##               #+#        */
/*   Updated: 2026/04/15 13:37:41 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (!list || !new)
		return ;
	new->next = *list;
	*list = new;
}
