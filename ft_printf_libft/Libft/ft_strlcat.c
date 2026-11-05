/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/05 11:07:25 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/15 21:47:54 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest;

	dest = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src) + size);
	if (size <= dest)
		return (size + ft_strlen(src));
	i = 0;
	while (i < (size - dest - 1) && src[i])
	{
		dst[i + dest] = src[i];
		i++;
	}
	dst[i + dest] = 0;
	return (ft_strlen(src) + dest);
}

// int main(void)
// {
// 	char str1[] = "a";
// 	char str11[] = "a";
// 	char str2[] = "lorem";
// 	printf("%zu\n", ft_strlcat(str1, str2, 5));
// 	printf("%s\n", str1);	
// 	printf("%zu\n", strlcat(str11, str2, 5));
// 	printf("%s\n", str11);
// }