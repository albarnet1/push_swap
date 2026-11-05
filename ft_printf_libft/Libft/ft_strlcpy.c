/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/01 16:21:51 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/15 21:48:16 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0 || dst == 0)
		return (ft_strlen(src));
	while ((i < size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char str1[] = "12345";
// 	char str2[] = "000000000";
// 	printf("%zu\n", ft_strlcpy(str1, str2, 6));
// 	printf("%s", str1);
// 	//strncpy(str1, str2, 0);
// }