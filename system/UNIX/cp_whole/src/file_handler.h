#ifndef FILE_HANDLER_H
# define FILE_HANDLER_H

# define BUFF_SIZE	1024

int	file_open(char const *filename, int mode);
void	read_file(int in_fd, int out_fd);
void	write_file(int fd, char const *buffer, int bytes_read);


#endif // FILE_HANDLER_H