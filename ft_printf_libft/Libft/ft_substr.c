/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/05 17:06:59 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/23 16:38:57 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		s2 = malloc(1);
		if (!s2)
			return (NULL);
		*s2 = 0;
		return (s2);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	s2 = ft_calloc((len + 1), 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i++] = s[start++];
	}
	return (s2);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*dst;

// 	if (*s == 0)
// 		return (ft_calloc((char)0, 1));
// 	if (start >= ft_strlen(s))
//  		return (NULL);
// 	dst = ft_calloc(len, sizeof(char));	
// 	ft_strlcpy(dst, s + start, len + 1);
// 	return(dst);
// }

// int	main(void)
// {
// 	char	str[] = "hola";
// 	printf("%s", ft_substr(str, 0, 18446744073709551615));
// }