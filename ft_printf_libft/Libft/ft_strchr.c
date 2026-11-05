/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 18:17:44 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/08 12:29:15 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if ((unsigned char)c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == (unsigned char) c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (0);
}

// int main(void)
// {
// 	char str[] = "teste";
// 	int letter = '1024';
// 	printf("%p", ft_strchr(str, letter));
// }