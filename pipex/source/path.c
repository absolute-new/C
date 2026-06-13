/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   path.c                                        #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/06/08 18:15:10 by absolute     ##               #+#        */
/*   Updated: 2026/06/08 18:15:10 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_env_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			return (path);
		}
		i++;
	}
	return (NULL);
}

static char	**make_usable_paths(char **paths)
{
	int		i;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(tmp);
		i++;
	}
	return (paths);
}

static char	**get_env_paths(char **envp)
{
	char	*env_path_str;
	char	**paths;

	env_path_str = get_env_path(envp);
	if (!env_path_str)
		return (NULL);
	paths = ft_split(env_path_str, ':');
	free(env_path_str);
	if (!paths)
		return (NULL);
	paths = make_usable_paths(paths);
	return (paths);
}

static char	*get_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*cmd_path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	paths = get_env_paths(envp);
	if (!paths)
		return (NULL);
	cmd_path = get_cmd_path(cmd, paths);
	free_strs(NULL, paths);
	return (cmd_path);
}
