/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   pipex.h                                       #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/06/08 17:26:03 by absolute     ##               #+#        */
/*   Updated: 2026/06/08 17:26:03 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "get_next_line.h"

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

typedef struct s_data
{
	char	**envp;
	char	**argv;
	char	**cmd_options;
	char	*cmd_path;
	int		argc;
	int		heredoc;
	int		fd_in;
	int		fd_out;
	int		*pipe;
	int		nb_cmds;
	int		child;
	int		*pids;
}	t_data;

/*	initialization	*/
t_data	init_data(int argc, char **argv, char **envp);

/*	path and split	*/
char	*find_path(char *cmd, char **envp);
char	**ft_split(const char *s, char c);

/*	file handling	*/
void	get_input_file(t_data *data);
void	get_output_file(t_data *data);
void	get_heredoc(t_data *data);

/*	error and cleanup	*/
void	exit_error(int error_status, t_data *data);
void	close_fds(t_data *data);
void	free_strs(char *str, char **strs);

/*	utils	*/
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
int		msg(char *s1, char *s2, char *s3, int erno);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

#endif
