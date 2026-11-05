/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/05 19:28:37 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/20 16:23:28 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	size_t	i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		break ;
	}
	if (ft_strlen(s) == i)
		return (0);
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != 0)
			words++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (words);
}

char	*ft_make_str(char const *str, char c)
{
	char		*str2;
	size_t		i;
	size_t		cnt;

	cnt = 0;
	i = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[cnt + i] != c && str[cnt + i])
	{
		cnt++;
	}
	str2 = ft_substr(str + i, 0, cnt);
	return (str2);
}

char	*ft_check_malloc(char const *s, int idx, char **arr, char c)
{
	char	*str;

	str = ft_make_str(s, c);
	if (!str)
	{
		while (idx > 0)
		{
			idx--;
			free(arr[idx]);
		}
		free(arr);
		return (NULL);
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		idx;
	int		words;
	char	**arr;
	char	*str;

	idx = 0;
	words = ft_count_words(s, c);
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s && idx < words)
	{
		str = ft_check_malloc(s, idx, arr, c);
		if (!str)
			return (NULL);
		arr[idx++] = str;
		while (*s == c)
			s++;
		while (*s != c && *s)
			s++;
	}
	arr[idx] = 0;
	return (arr);
}

// int	main(void)
// {
// 	char delim = ' ';
// 	char str[] = "tripouille";
// 	char	**lolly = ft_split(str, delim);
// 	for (int i = 0; i <3; i++)
// 	{
// 		printf("-%s-\n", lolly[i]);
// 	}
// }