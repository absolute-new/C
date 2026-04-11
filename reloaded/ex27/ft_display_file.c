/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   display_file.c                                 #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/13 04:13:00 by absolute     ##               #+#        */
/*   Updated: 2025/09/13 04:13:01 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(int descriptor, char c)
{
	write(descriptor, &c, 1);
}

void	ft_putstr(int descriptor, char *str)
{
	if (str)
	{
		while (*str)
		{
			ft_putchar(descriptor, *str);
			str++;
		}
	}
}

int	show_char(char **argv)
{
	int		fd;
	int		bytes;
	char	temp;
	int		result;

	result = 0;
	fd = open(argv[1], O_RDONLY);
	bytes = 1;
	if (fd != -1)
	{
		while (bytes > 0)
		{
			bytes = read(fd, &temp, 1);
			if (bytes > 0)
				ft_putchar(1, temp);
		}
		bytes = close(fd);
		if (!bytes)
			result = 1;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr(2, "File name is missing.\n");
	else if (argc == 2)
	{
		if (!show_char(argv))
			ft_putstr(2, "Cannot read file.\n");
	}
	else
		ft_putstr(2, "Too many arguments.\n");
	return (0);
}
