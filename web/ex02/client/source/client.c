#include "../include/client_handler.h"
#include "../include/socket_utils.h"
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

static void	print_connection_info(struct addrinfo *p)
{
	char	s[INET6_ADDRSTRLEN];

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
		s, sizeof(s));
	printf("client: connecting to %s\n", s);
}

int	main(int ac, char *av[])
{
	int				sockfd;
	struct addrinfo	*serverinfo;

	if (ac != 2)
	{
		fprintf(stderr, "usage: client hostname\n");
		exit(1);
	}
	sockfd = connect_to_server(av[1], PORT);
	if (sockfd == -1)
	{
		fprintf(stderr, "client: failed to connect\n");
		exit(1);
	}
	getaddrinfo(av[1], PORT, NULL, &serverinfo);
	print_connection_info(serverinfo);
	freeaddrinfo(serverinfo);
	handle_server_response(sockfd);
	close(sockfd);
	return (0);
}
