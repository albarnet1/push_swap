/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:54:08 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/06 16:03:08 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*b;
	char	*e;

	b = (char *)s;
	e = b + n;
	while (b < e)
	{
		*b = 0;
		b++;
	}
}

// int	main(void)
// {
// 	char	arr;

// 	arr = "abcdefghijkl";
// 	printf("%s\n", arr);
// 	ft_bzero(arr, 3);
// 	printf("%s", arr);
// }
