#include "../include/socket_utils.h"
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	*get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET)
		return (&(((struct sockaddr_in *)sa)->sin_addr));
	return (&(((struct sockaddr_in6 *)sa)->sin6_addr));
}

static int	try_connect(struct addrinfo *p, int *sockfd)
{
	*sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
	if (*sockfd == -1)
	{
		p = p->ai_next;
		return (-1);
	}
	if (connect(*sockfd, p->ai_addr, p->ai_addrlen) == -1)
	{
		close(*sockfd);
		p = p->ai_next;
		return (-1);
	}
	return (0);
}

int	connect_to_server(const char *host, const char *port)
{
	struct addrinfo	hints;
	struct addrinfo	*serverinfo;
	struct addrinfo	*p;
	int				sockfd;
	int				rv;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	rv = getaddrinfo(host, port, &hints, &serverinfo);
	if (rv != 0)
		return (-1);
	p = serverinfo;
	while (p != NULL)
	{
		if (try_connect(p, &sockfd) == 0)
			break ;
		p = p->ai_next;
	}
	freeaddrinfo(serverinfo);
	if (p == NULL)
		return (-1);
	return (sockfd);
}
