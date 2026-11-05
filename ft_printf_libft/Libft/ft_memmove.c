/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/02 10:28:01 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/07 11:22:37 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*destp;
	unsigned char	*srcp;
	size_t			i;

	i = 0;
	destp = (char *)dest;
	srcp = (unsigned char *)src;
	if (dest < src)
	{
		while (i < n)
		{
			destp[i] = srcp[i];
			i++;
		}
	}
	if (dest > src)
	{
		while (n > 0 && n + i)
		{
			destp[n - 1] = srcp[n - 1];
			n--;
		}
	}
	return (destp);
}

// int	main(void)
// {
// 	char str[] = "abcdefg";
// 	char str2[] = "abcdefg";
// 	ft_memmove(str + 1, str, 3);
// 	memmove(str2 + 1, str2, 3);
// 	printf("%s\n", str);
// 	printf("%s", str2);
// }