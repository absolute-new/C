/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ulits.c                                       #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/06/08 17:45:29 by absolute     ##               #+#        */
/*   Updated: 2026/06/08 17:45:29 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(int error_status, t_data *data)
{
	if (data)
	{
		close_fds(data);
		if (data->pipe)
			free(data->pipe);
		if (data->pids)
			free(data->pids);
		if (data->cmd_options || data->cmd_path)
			free_strs(data->cmd_path, data->cmd_options);
	}
	if (data && data->heredoc == 1)
		unlink(".heredoc.tmp");
	exit(error_status);
}

int	msg(char *s1, char *s2, char *s3, int erno)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(s3, 2);
	return (erno);
}

void	free_strs(char *str, char **strs)
{
	int	i;

	if (str)
	{
		free(str);
		str = NULL;
	}
	if (strs)
	{
		i = 0;
		while (strs[i])
		{
			free(strs[i]);
			strs[i] = NULL;
			i++;
		}
		free(strs);
		strs = NULL;
	}
}

void	close_fds(t_data *data)
{
	int	i;

	if (data->fd_in != -1)
		close(data->fd_in);
	if (data->fd_out != -1)
		close(data->fd_out);
	if (data->pipe)
	{
		i = 0;
		while (i < (data->nb_cmds - 1) * 2)
		{
			close(data->pipe[i]);
			i++;
		}
	}
}
