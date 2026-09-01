#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../include/socket_utils.h"
#include "../include/client_handler.h"

static void	sigchld_handler(int s)
{
	(void)s;
	while (waitpid(-1, NULL, WNOHANG) > 0)
		;
}

static void	handle_signal(void)
{
	struct sigaction	sa;

	sa.sa_handler = sigchld_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGCHLD, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(1);
	}
}

static void	handle_new_client(int sockfd, int client_fd,
		struct sockaddr_storage *their_addr)
{
	char	s[INET6_ADDRSTRLEN];

	inet_ntop(their_addr->ss_family, get_in_addr(
			(struct sockaddr *)&their_addr), s, sizeof(s));
	printf("server: got connection from %s\n", s);
	if (!fork())
	{
		close(sockfd);
		handle_client(client_fd);
		exit(0);
	}
	close(client_fd);
}

static void	accept_loop(int sockfd)
{
	int						client_fd;
	struct sockaddr_storage	their_addr;
	socklen_t				sin_size;

	while (1)
	{
		sin_size = sizeof(their_addr);
		client_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
		if (client_fd == -1)
		{
			perror("accept");
			continue ;
		}
		handle_new_client(sockfd, client_fd, &their_addr);
	}
}

int	main(void)
{
	int	sockfd;

	handle_signal();
	sockfd = create_listening_socket(PORT, BACKLOG);
	if (sockfd == -1)
		exit(1);
	printf("server: waiting for connections...\n");
	accept_loop(sockfd);
	return (0);
}
