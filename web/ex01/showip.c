#include <stdio.h>			/**< для printf, fprintf */
#include <string.h>			/**< для memset, strlen */

#ifdef _WIN32
	#include <winsock2.h>	/**<  для сокетов (AF_INET, SOCK_STREAM) */
	#include <ws2tcpip.h>	/**< для inet_ntop */

	# ifdef _MSC
		#pragma comment(lib, "ws2_32.lib")
	# endif

	#define CLOSE_SOCKET(s)		closesocket(s)
	#define IS_VALID_SOCKET(s)	((s) != INVALID_SOCKET)
	#define GET_LAST_ERROR()	WSAGetLastError()
	#define SOCKET_TYPE			SOCKET
#else
	#include <sys/types.h>	/**< для size_t, ssize_t */
	#include <sys/socket.h>	/**<  для сокетов (AF_INET, SOCK_STREAM) */
	#include <netdb.h>		/**< для getaddrinfo, struct addrinfo */
	#include <arpa/inet.h>	/**< для inet_ntop */
	#include <netinet/in.h>	/**< для sockaddr_in, sockaddr_in6 */

	#define CLOSE_SOCKET(s)		close(s)
	#define IS_VALID_SOCKET(s)	((s) >= 0)
	#define GET_LAST_ERROR()	errno
	#define SOCKET_TYPE			int
#endif

static int	init_network(void)
{
#ifdef _WIN32
	WSADATA	wsa_data;
	if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0)
	{
		fprintf(stderr, "WSAStartup failed\n");
		return (-1);
	}
#endif
	return (0);
}

static void	cleanup_network(void)
{
#ifdef _WIN32
	WSACleanup();
#endif
}

static void	print_addr(struct addrinfo *res)
{
	struct addrinfo	*p;
	void			*addr;
	char			*ipver;
	char			ipstr[INET6_ADDRSTRLEN];

	for (p = res; p != NULL; p = p->ai_next)
	{
		if (p->ai_family == AF_INET)
		{
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
			addr = &(ipv4->sin_addr);
			ipver = "IPv4";
		}
		else
		{
			struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipver = "IPv6";
		}
		inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
		printf(" %s: %s\n", ipver, ipstr);
	}
}

int	main(int ac, char *av[])
{
	struct addrinfo	hints;
	struct addrinfo	*res;
	int				status;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: showip hostname\n");
		return (1);
	}
	if (init_network() != 0)
		return (1);
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_ALL;
	status = getaddrinfo(av[1], NULL, &hints, &res);
	if (status != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		return (2);
	}
	printf("IP addresses for %s:\n\n", av[1]);
	print_addr(res);
	freeaddrinfo(res);
	cleanup_network();
	return (0);
}
