/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   get_next_line.c                                      #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/12 17:27:54 by absolute     ##               #+#        */
/*   Updated: 2026/04/12 17:27:54 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *remainder, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	if (bytes_read == 0)
		return (remainder);
	buffer[bytes_read] = '\0';
	if (!remainder)
		tmp = ft_strdup(buffer);
	else
		tmp = ft_strjoin(remainder, buffer);
	free(remainder);
	return (tmp);
}

static char	*fill_remainder(int fd, char *remainder)
{
	char	*buffer;
	char	*old;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(remainder, '\n'))
	{
		old = remainder;
		remainder = read_file(fd, remainder, buffer);
		if (!remainder || old == remainder)
			break ;
	}
	free(buffer);
	return (remainder);
}

static char	*extract_line(char *remainder)
{
	char	*line;
	int		i;

	if (!remainder || !remainder[0])
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		line = (char *)malloc(i + 2);
	else
		line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_remainder(char *remainder)
{
	char	*new_remainder;
	size_t	i;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = ft_strdup(remainder + i + 1);
	free(remainder);
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = fill_remainder(fd, remainder);
	if (!remainder)
		return (NULL);
	line = extract_line(remainder);
	remainder = update_remainder(remainder);
	return (line);
}
