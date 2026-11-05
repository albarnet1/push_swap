/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/30 13:29:14 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/15 21:38:33 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s == (unsigned char) c)
		{
			return ((char *)s);
		}
		s++;
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char str1[] = "abcdefg";
// 	int c = 'd';
// 	printf("%p\n", ft_memchr(str1, c, 11));
// 	printf("%p", memchr(str1, c, 11));
// }