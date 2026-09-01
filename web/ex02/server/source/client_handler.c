#include "../include/client_handler.h"
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

void	handle_client(int client_fd)
{
	if (send(client_fd, "Hello, World!\n", 14, 0) == -1)
		perror("send");
	close(client_fd);
}
