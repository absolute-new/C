/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   get_next_line.h                               #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/12 17:06:06 by absolute     ##               #+#        */
/*   Updated: 2026/04/12 17:06:06 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_BUFFER_SIZE 1000000

# if BUFFER_SIZE < 1 || BUFFER_SIZE > MAX_BUFFER_SIZE
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);

#endif