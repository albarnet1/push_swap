/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base_unsigned.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/23 15:03:26 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/25 16:32:17 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_abs(int x)
{
	if (x > 0)
		return (x);
	return (-x);
}

int	ft_putnbr_base_uns(unsigned int n, char *base)
{
	int				str[500];
	int				res;
	int				i;
	int				base_len;

	i = 0;
	res = 0;
	base_len = ft_strlen(base);
	if (n == 0)
		return ((int)write(1, "0", 1));
	while (n)
	{
		str[i++] = ft_abs(n % base_len);
		n = n / base_len;
	}
	while (i > 0)
	{
		ft_putchar_fd(base[str[--i]], 1);
		res++;
	}
	return (res);
}
