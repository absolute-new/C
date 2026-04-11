/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_print_alphabet.c                            #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/07 00:19:49 by absolute     ##               #+#        */
/*   Updated: 2025/09/07 00:32:44 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#define FINISH 'z'

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	start;

	start = 'a';
	while (start <= FINISH)
	{
		ft_putchar(start);
		start ++;
	}
	return (0);
}
