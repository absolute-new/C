/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   pipex.c                                       #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/06/08 18:00:56 by absolute     ##               #+#        */
/*   Updated: 2026/06/08 18:00:56 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	redirect_io(int in, int out, t_data *data)
{
	if (dup2(in, STDIN_FILENO) == -1)
		exit_error(msg("dup2", ": ", strerror(errno), 1), data);
	if (dup2(out, STDOUT_FILENO) == -1)
		exit_error(msg("dup2", ": ", strerror(errno), 1), data);
}

static void	child(t_data *data)
{
	if (data->child == 0)
		redirect_io(data->fd_in, data->pipe[1], data);
	else if (data->child == data->nb_cmds - 1)
		redirect_io(data->pipe[(data->child - 1) * 2], data->fd_out, data);
	else
		redirect_io(data->pipe[(data->child - 1) * 2],
			data->pipe[data->child * 2 + 1], data);
	close_fds(data);
	if (data->cmd_options == NULL || data->cmd_path == NULL)
		exit_error(1, data);
	if (execve(data->cmd_path, data->cmd_options, data->envp) == -1)
		exit_error(msg(data->cmd_options[0], ": ", strerror(errno), 1), data);
}

static int	parent(t_data *data)
{
	pid_t	wpid;
	int		status;
	int		exit_code;

	close_fds(data);	
	exit_code = 1;
	data->child--;
	while (data->child >= 0)
	{
		wpid = waitpid(data->pids[data->child], &status, 0);
		if (wpid == data->pids[data->nb_cmds - 1])
		{
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
		}
		data->child--;
	}
	free(data->pipe);
	free(data->pids);	
	return (exit_code);
}

static int	pipex(t_data *data)
{
	int	exit_code;

	if (pipe(data->pipe) == -1)
		exit_error(msg("pipe", ": ", strerror(errno), 1), data);
	data->child = 0;
	while (data->child < data->nb_cmds)
	{
		data->cmd_options = ft_split(data->argv[data->child + 2
				+ data->heredoc], ' ');
		if (!data->cmd_options)
			exit_error(msg("malloc", ": ", strerror(errno), 1), data);
		data->cmd_path = find_path(data->cmd_options[0], data->envp);
		data->pids[data->child] = fork();
		if (data->pids[data->child] == -1)
			exit_error(msg("fork", ": ", strerror(errno), 1), data);
		if (data->pids[data->child] == 0)
			child(data);
		free_strs(data->cmd_path, data->cmd_options);
		data->child++;
	}
	exit_code = parent(data);
	return (exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		exit_code;

	if (argc < 5)
	{
		if (argc >= 2 && !ft_strncmp("here_doc", argv[1], 8))
			return (msg("Usage: ", "./pipex here_doc LIMITER cmd1 cmd2 ..."
					" cmdn file2.", "", 1));
		return (msg("Usage: ", "./pipex file1 cmd1 cmd2 ... cmdn file2.",
				"", 1));
	}
	else if (argc < 6 && !ft_strncmp("here_doc", argv[1], 8))
		return (msg("Usage: ", "./pipex here_doc LIMITER cmd1"
				"cmd2 ... cmdn file2.", "", 1));
	if (!envp || envp[0][0] == '\0')
		exit_error(msg("Unexpected error.", "", "", 1), &data);
	data = init_data(argc, argv, envp);
	exit_code = pipex(&data);
	return (exit_code);
}
