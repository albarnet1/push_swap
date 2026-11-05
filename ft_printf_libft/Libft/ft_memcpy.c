/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 15:56:00 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/07 11:22:30 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*b;
	char	*c;
	size_t	i;

	b = (char *)dest;
	c = (char *)src;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		b[i] = c[i];
		i++;
	}
	return (dest);
}

// int main(void)
// {
// 	char src[] = "abcdefg";
// 	char dest[] = "hallo";
// 	ft_memcpy(dest, src, 3);
// 	printf("%s", dest);
// }