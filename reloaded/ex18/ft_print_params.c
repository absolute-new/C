/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_print_params.c                              #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/12 05:02:58 by absolute     ##               #+#        */
/*   Updated: 2025/09/12 05:02:59 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_str(char *str)
{
	if (str)
	{
		while (*str)
		{
			ft_putchar(*str);
			str++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_print_str(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
