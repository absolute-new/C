/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   ft_strcmp.c                                    #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/12 04:33:46 by absolute     ##               #+#        */
/*   Updated: 2025/09/12 04:33:48 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	answer;

	answer = 0;
	if (!s1 && !s2)
		answer = 0;
	else if (!s1)
		answer = -1;
	else if (!s2)
		answer = 1;
	else
	{
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		answer = (unsigned char)*s1 - (unsigned char)*s2;
	}
	return (answer);
}
