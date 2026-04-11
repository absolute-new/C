/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_count_if.c                                  #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/13 04:03:06 by absolute     ##               #+#        */
/*   Updated: 2025/09/13 04:03:09 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int(*f)(char *))
{
	int	count;
	int	i;
	int	flag;

	count = 0;
	flag = 0;
	if (!tab || !f)
		flag = 1;
	if (!flag)
	{
		i = 0;
		while (tab[i])
		{
			if (f(tab[i]) == 1)
				count++;
			i++;
		}
	}
	return (count);
}
