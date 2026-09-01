#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	char	*args[3];

	pid = fork();
	if (pid == 0)
	{
		args[0] = "ls";
		args[1] = "-l";
		args[2] = NULL;
		execve("/bin/ls", args, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		printf("Child finished\n");
	}
	return (0);
}
