#include "../include/client_handler.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>

void	handle_server_response(int sockfd)
{
	char	buf[MAXDATASIZE];
	int		numbytes;

	numbytes = recv(sockfd, buf, MAXDATASIZE - 1, 0);
	if (numbytes == -1)
	{
		perror("recv");
		return ;
	}
	buf[numbytes] = '\0';
	if (numbytes > 0 && buf[numbytes - 1] == '\n')
		buf[numbytes - 1] = '\0';
	printf("client: received '%s'\n", buf);
}
