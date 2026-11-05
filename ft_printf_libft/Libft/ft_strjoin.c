/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/05 17:54:55 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/15 21:44:18 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	stringlength;
	size_t	i;
	size_t	m;

	m = 0;
	i = 0;
	stringlength = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_calloc(stringlength + 1, 1);
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	m = i;
	i = 0;
	while (s2[i])
		s3[m++] = s2[i++];
	s3[m] = 0;
	return (s3);
}

// int main(void)
// {
// 	char	str1[] = "ab";
// 	char	str2[] = "abc";
// 	printf("%s", ft_strjoin(str1, str2));
// }