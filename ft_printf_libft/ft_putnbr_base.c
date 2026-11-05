/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/21 14:16:00 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/23 16:32:16 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_abs(int x)
{
	if (x > 0)
		return (x);
	return (-x);
}

int	ft_putnbr_base(int n, char *base)
{
	int				str[500];
	int				res;
	int				i;
	int				base_len;

	i = 0;
	res = 0;
	base_len = ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", 1);
		res++;
	}
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

int	ft_putptr(long long unsigned n)
{
	int				str[500];
	int				res;
	int				i;
	char			*base;

	base = "0123456789abcdef";
	i = 0;
	res = 0;
	while (n)
	{
		str[i] = n % 16;
		n = n / 16;
		i++;
	}
	while (i > 0)
	{
		ft_putchar_fd(base[str[--i]], 1);
		res++;
	}
	return (res);
}

// int main(void)
// {
// 	ft_putnbr_base(-9, "0123456789abcdef");
// 	printf("\n\n%x\n", -9);
// 	// ft_putnbr_base(-2147483647, "0123456789abcdef");
// 	// printf("%p", -2147483647);
// }