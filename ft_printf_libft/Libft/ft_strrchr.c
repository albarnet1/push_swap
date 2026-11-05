/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 18:49:06 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/15 21:37:41 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)(s + i));
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}

// #include <string.h>

// int	main(void)
// {
// 	char str[] = "abcdecfg";
// 	int letter = 'c';
// 	printf("%p\n", ft_strrchr(str, letter));
// 	printf("%p\n", strrchr(str, letter));
// }