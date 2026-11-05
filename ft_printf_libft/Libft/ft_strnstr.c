/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/30 10:21:55 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/15 21:49:47 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (little[j] == 0 || little == big)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (little[0] == big[i])
		{
			while (big[i + j] == little[j] && (i + j) < len && little[j])
			{
				j++;
				if (little[j] == '\0')
					return ((char *)(big + i));
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char str1[] = "aaabcdefghijk";
// 	char str2[] = "aabc";
// 	printf("%s\n", ft_strnstr(str1, str2, 14));
// 	// printf("%s", strnstr(str1, str2, -1));
// }