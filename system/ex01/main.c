#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int ac, char *av[], char *env)
{
	pid_t	pid;
	int		fd[2];
	char	buff[100];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		read(fd[0], buff, sizeof(buff));
		printf("Child read buffer:\t%s", buff);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		write(fd[1], "Hello, I'm Parent\n", 18);
		close(fd[1]);
		wait(NULL);
	}
	return (0);
}
