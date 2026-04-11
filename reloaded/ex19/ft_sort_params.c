/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_sort_params.c                               #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/12 05:14:09 by absolute     ##               #+#        */
/*   Updated: 2025/09/12 05:14:10 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_strcmp(char *s1, char *s2)
{
	int	result;

	result = 0;
	if (!s1)
		result = -1;
	else if (!s2)
		result = 1;
	else
	{
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		result = (unsigned char)*s1 - (unsigned char)*s2;
	}
	return (result);
}

void	ft_sort_params(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				temp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_print_params(int argc, char **argv)
{
	char	**current;
	char	*str;

	current = argv + 1;
	while (current < argv + argc)
	{
		str = *current;
		while (*str)
			ft_putchar(*str++);
		current++;
		ft_putchar('\n');
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_sort_params(argc, argv);
		ft_print_params(argc, argv);
	}
	return (0);
}
