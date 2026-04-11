/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_foreach.c                                   #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/13 03:44:18 by absolute     ##               #+#        */
/*   Updated: 2025/09/13 03:44:19 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	flag;
	int	i;

	flag = 0;
	if (!tab || length <= 0 || !f)
		flag = 1;
	if (!flag)
	{
		i = 0;
		while (i < length)
		{
			f(tab[i]);
			i++;
		}
	}
}
