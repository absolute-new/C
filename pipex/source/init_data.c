/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   init_data.c                                   #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/06/08 22:40:20 by absolute     ##               #+#        */
/*   Updated: 2026/06/08 22:40:20 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_data	clean_init(void)
{
	t_data	data;

	data.envp = NULL;
	data.argv = NULL;
	data.cmd_options = NULL;
	data.cmd_path = NULL;
	data.argc = -1;
	data.heredoc = 0;
	data.fd_in = -1;
	data.fd_out = -1;
	data.pipe = NULL;
	data.nb_cmds = -1;
	data.child = -1;
	data.pids = NULL;
	return (data);
}

static void	generate_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_cmds - 1)
	{
		if (pipe(data->pipe + i * 2) == -1)
		{
			msg("Pipe error", ": ", strerror(errno), 1);
			exit_error(1, data);
		}
		i++;
	}
}

t_data	init_data(int argc, char **argv, char **envp)
{
	t_data	data;

	data = clean_init();
	data.envp = envp;
	data.argc = argc;
	data.argv = argv;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		data.heredoc = 1;
	get_input_file(&data);
	get_output_file(&data);
	data.nb_cmds = argc - 3 - data.heredoc;
	data.pids = malloc(sizeof(int) * data.nb_cmds);
	if (!data.pids)
		exit_error(msg("PID error", strerror(errno), "", 1), &data);
	data.pipe = malloc(sizeof(int) * (data.nb_cmds - 1) * 2);
	if (!data.pipe)
	{
		free(data.pids);
		msg("Pipe error", ": ", strerror(errno), 1);
		exit_error(1, &data);
	}
	generate_pipes(&data);
	return (data);
}
