/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/01 15:10:16 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/08 12:37:24 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	posneg;
	int	m;

	m = 0;
	posneg = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			posneg = posneg * -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		m = m + *nptr - 48;
		if (*(nptr + 1) >= '0' && *(nptr + 1) <= '9')
			m = m * 10;
		if (*(nptr + 1) < '0' || *(nptr + 1) > '9')
			return (posneg * m);
		nptr++;
	}
	return (0);
}

// int main(void)
// {
//     char str[] = "";
//     printf("%d\n", ft_atoi(str));
//     printf("%d", atoi(str));
// }