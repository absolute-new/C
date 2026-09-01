#include "../include/socket_utils.h"
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	*get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET)
		return (&(((struct sockaddr_in *)sa)->sin_addr));
	return (&(((struct sockaddr_in6 *)sa)->sin6_addr));
}

static struct addrinfo	*get_serverinfo(const char *port)
{
	struct addrinfo	hints;
	struct addrinfo	*serverinfo;
	int				rv;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	rv = getaddrinfo(NULL, port, &hints, &serverinfo);
	if (rv != 0)
		return (NULL);
	return (serverinfo);
}

static int	setup_socket_options(int sockfd)
{
	int	yes;

	yes = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
	{
		perror("setsockport");
		close(sockfd);
		return (-1);
	}
	return (0);
}

static int	bind_to_address(struct addrinfo *p, int *sockfd)
{
	*sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
	if (*sockfd == -1)
		return (-1);
	if (setup_socket_options(*sockfd) == -1)
		return (-1);
	if (bind(*sockfd, p->ai_addr, p->ai_addrlen) == -1)
	{
		close(*sockfd);
		return (-1);
	}
	return (0);
}

int	create_listening_socket(const char *port, int backlog)
{
	struct addrinfo	*serverinfo;
	struct addrinfo	*p;
	int				sockfd;

	serverinfo = get_serverinfo(port);
	if (serverinfo == NULL)
		return (-1);
	p = serverinfo;
	while (p != NULL)
	{
		if (bind_to_address(p, &sockfd) == 0)
			break ;
		p = p->ai_next;
	}
	freeaddrinfo(serverinfo);
	if (p == NULL)
		return (-1);
	if (listen(sockfd, backlog) == -1)
	{
		perror("listen");
		close(sockfd);
		return (-1);
	}
	return (sockfd);
}
