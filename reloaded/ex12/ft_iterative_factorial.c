/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_iterative_factorial.c                       #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/07 01:11:31 by absolute     ##               #+#        */
/*   Updated: 2025/09/07 01:11:33 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb >= 0 && nb <= 12)
	{
		while (nb > 0)
		{
			res *= nb;
			nb -= 1;
		}
		return (res);
	}
	else
		return (0);
}
