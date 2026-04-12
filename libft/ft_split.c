/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   ft_split.c                                    #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/11 22:18:31 by absolute     ##               #+#        */
/*   Updated: 2026/04/11 22:18:31 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_get_word(char const *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(end - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_all(char **result, size_t j)
{
	while (j > 0)
	{
		j--;
		free(result[j]);
	}
	free(result);
}

static void	ft_fill_array(char **array, char const *s, char c, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] && j < count)
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			array[j] = ft_get_word(s, start, i);
			if (!array[j])
			{
				ft_free_all(array, j);
				return ;
			}
			j++;
		}
		else
			i++;
	}
	array[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**array;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	array = (char **)malloc((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	ft_fill_array(array, s, c, count);
	return (array);
}
