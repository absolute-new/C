/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_printf.h                                   #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/23 12:18:47 by absolute     ##               #+#        */
/*   Updated: 2026/04/23 12:18:47 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_flags
{
	int	zero;
	int	minus;
	int	dot;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precission;
}	t_flags;

int		ft_printf(const char *format, ...);

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putptr(void *ptr);
int		ft_puthex(unsigned long n, int upcase);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);

/*   UTILS   */
int		ft_isdigit(int c);
int		ft_strchr(const char *s, int c);
int		ft_atoi(const char **str);
int		ft_strlen(const char *s);
void	ft_parse_flags(const char **s, t_flags *flags, va_list args);
void	ft_init_flags(t_flags *flags);

/*	BONUS	*/
int		ft_putchar_flags(char c, t_flags flags);
int		ft_putstr_flags(char *s, t_flags flags);
int		ft_putnbr_flags(int n, t_flags flags);
int		ft_putptr_flags(void *prt, t_flags flags);
int		ft_puthex_flags(unsigned long n, int upcase, t_flags flags);
int		ft_putunsigned_flags(unsigned int n, t_flags flags);

#endif