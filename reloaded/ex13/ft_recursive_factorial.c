/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_recursive_factorial.c                       #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/07 01:21:46 by absolute     ##               #+#        */
/*   Updated: 2025/09/07 01:21:47 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 1 || nb == 0)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}
