/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/30 14:35:49 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/07 11:22:21 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
		{
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		}
		i++;
		s1++;
		s2++;
	}
	return (0);
}

// int main(void)
// {
// 	char str1[] = "abc";
// 	char str2[] = "abcd";
// 	printf("%d\n", ft_memcmp(str1, str2, 5));
// 	printf("%d", memcmp(str1, str2, 5));
// }