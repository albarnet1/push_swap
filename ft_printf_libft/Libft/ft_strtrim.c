/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/05 19:13:47 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/16 16:28:29 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_is_in_set(char const *s, int idx, char const *set)
{
	while (*set)
	{
		if (s[idx] == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_check_center(char const *s, char const *set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		if (ft_char_is_in_set(s, i, set) == 0)
		{
			j = i;
			break ;
		}
		i++;
	}
	i = ft_strlen(s) - 1;
	while (s[i])
	{
		if (ft_char_is_in_set(s, i, set) == 0)
			break ;
		i--;
	}
	str = ft_substr(s, j, ft_strlen(s) - j - (ft_strlen(s) - 1 - i));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	return (ft_check_center(s1, set));
}

// int	main(void)
// {
// 	printf("%s", ft_strtrim("...abcdef...", "."));
// }