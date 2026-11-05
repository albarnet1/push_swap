/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 10:38:25 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/15 21:36:34 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*b;

	b = s;
	while (n > 0)
	{
		*b = c;
		b++;
		n--;
	}
	return (s);
}

// int	main(void)
// {
// 	char arr[10] = "123456789";
// 	ft_memset(arr, 'd', 6);
// 	// printf("\n%p", ft_memset(arr, 'a', 2));
// 	printf("\n%s", arr);
// }