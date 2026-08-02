#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int	main(void)
{
	struct sockaddr_in	sa;
	int					error;
	char				ip[INET_ADDRSTRLEN];

	error = inet_pton(AF_INET, "192.168.1.1", &(sa.sin_addr));		// present to network (str - bin)
	if (error > 0)
	{
		inet_ntop(AF_INET, &(sa.sin_addr), ip, INET_ADDRSTRLEN);	// network to present (bin - str)
		printf("IP: %s\n", ip);
	}
	sa.sin_family = AF_INET;										// AF_INET - IPv4, AF_INET6 - IPv6
	sa.sin_port = htons(8080);										// host to network short (port)
	sa.sin_addr.s_addr = inet_addr("127.0.0.1");					// present to network (str - bin)
	printf("Порт: %d\n", ntohs(sa.sin_port));						// network to host
	printf("IP: %s\n", inet_ntoa(sa.sin_addr));						// network to present (bin - str)
	return (0);
}
