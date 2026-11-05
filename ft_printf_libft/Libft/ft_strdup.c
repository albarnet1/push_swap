/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/05 13:25:43 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/15 21:47:20 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	size;

	size = ft_strlen(s) + 1;
	s2 = malloc(size);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s, size);
	return (s2);
}

// int main(void)
// {
// 	char str[] = "";
// 	printf("%s", ft_strdup(str));
// }