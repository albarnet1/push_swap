/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 16:47:54 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/15 21:35:53 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(unsigned int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 97 && c <= 'z') || (c >= 48 && c <= 57))
	{
		return (1);
	}
	return (0);
}

// int	main(void) {
// 	ft_isalnum('/');
// }