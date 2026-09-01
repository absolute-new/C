#ifndef SOCKET_UTILS_H
# define SOCKET_UTILS_H

# define PORT	"3094"
# define BACKLOG	100

# include <netinet/in.h>

void	*get_in_addr(struct sockaddr *sa);
int		create_listening_socket(const char *port, int backlog);

#endif // SOCKET_UTILS_H
