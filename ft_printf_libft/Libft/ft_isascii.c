/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 16:55:24 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/07 11:40:03 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(unsigned int c)
{
	if (c <= 127)
	{
		return (1);
	}
	return (0);
}

// int main(void)
// {
// 	int	a = '4';
// 	ft_isascii(a);
// }