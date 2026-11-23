/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/21 14:48:59 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/23 13:57:06 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = (unsigned int)n * -1;
	}
	while ((unsigned int)n >= 1)
	{
		n = (unsigned int)n / 10;
		i++;
	}
	return (i);
}
