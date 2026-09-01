#ifndef SOCKET_UTILS_H
# define SOCKET_UTILS_H

# include <netdb.h>
# include <arpa/inet.h>
# include <stdlib.h>

# define PORT	"3094"

void	*get_in_addr(struct sockaddr *sa);
int		connect_to_server(const char *host, const char *port);

#endif // SOCKET_UTILS_H