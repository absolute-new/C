#ifndef FILE_HANDLER_H
# define FILE_HANDLER_H

int		file_open(char const *filename);
void	do_read(int fd, char *arg, char type);
void	do_write(int fd, char *arg);
void	do_seek(int fd, char *arg);
long	get_offset(char *str);

#endif // FILE_HANDLER_H