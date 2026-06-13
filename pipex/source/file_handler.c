/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   file_handler.c                                #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/06/08 21:09:54 by absolute     ##               #+#        */
/*   Updated: 2026/06/08 21:09:54 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_input_file(t_data *data)
{
	if (data->heredoc == 1)
	{
		get_heredoc(data);
		data->fd_in = open(".heredoc.tmp", O_RDONLY, 0);
		if (data->fd_in == -1)
		{
			msg("heredoc", ": ", strerror(errno), 1);
			exit_error(1, data);
		}
	}
	else
	{
		data->fd_in = open(data->argv[1], O_RDONLY, 0);
		if (data->fd_in == -1)
		{
			msg(data->argv[1], ": ", strerror(errno), 1);
		}
	}
}

void	get_output_file(t_data *data)
{
	int	flags;

	if (data->heredoc == 1)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	data->fd_out = open(data->argv[data->argc - 1], flags, 0644);
	if (data->fd_out == -1)
	{
		msg(data->argv[data->argc - 1], ": ", strerror(errno), 1);
		exit_error(1, data);
	}
}

void	get_heredoc(t_data *data)
{
	int		tmp_fd;
	char	*line;

	tmp_fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd == -1)
	{
		msg("heredoc", ": ", strerror(errno), 1);
		exit_error(1, data);
	}
	while (1)
	{
		write(1, "here_doc > ", 11);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, data->argv[2], ft_strlen(data->argv[2])) == 0)
		{
			free(line);
			break ;
		}
		write(tmp_fd, line, ft_strlen(line));
		free(line);
	}
	close(tmp_fd);
}
