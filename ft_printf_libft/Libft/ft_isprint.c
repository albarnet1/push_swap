/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 16:59:48 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/07 12:26:46 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(unsigned int c)
{
	if (c >= ' ' && c <= '~')
	{
		return (1);
	}
	return (0);
}

// int main(){
// 	int a = '4';
// 	ft_isprint(a);
// }