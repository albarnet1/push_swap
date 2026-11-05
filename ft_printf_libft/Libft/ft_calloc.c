/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/05 11:50:37 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/18 16:53:24 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size > __SIZE_MAX__ / nmemb)
		return (NULL);
	arr = malloc(nmemb * size);
	if (arr == 0)
		return (0);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

// int main(void)
// {
// 	printf("%lu\n", sizeof(ft_calloc(4, 20)));
// 	printf("%lu", sizeof(calloc(4, 20)));
// }