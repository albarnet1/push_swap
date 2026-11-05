/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/19 13:28:02 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/25 17:55:35 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		res;

	res = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			if (ft_strchr(CONVERSIONS, format[i + 1]))
			{
				res = res + ft_print(&args, (char)format[++i]);
				if (format[++i] == 0)
					break ;
				continue ;
			}
		}
		write(1, &format[i++], 1);
		res++;
	}
	va_end(args);
	return (res);
}

static int	ft_print_helper(va_list *s, char m)
{
	int				n;
	unsigned int	nbr;

	if (m == 'd' || m == 'i')
	{
		n = va_arg(*s, int);
		if (n == 0)
			return ((int)write(1, "0", 1));
		return (ft_putnbr_base(n, "0123456789"));
	}
	if (m == 'u')
		return (ft_putnbr_base_uns(va_arg(*s, unsigned int), "0123456789"));
	if (m == 'x' || m == 'X')
	{
		nbr = va_arg(*s, unsigned int);
		if (nbr == 0)
			return ((int)write(1, "0", 1));
		if (m == 'x')
			return (ft_putnbr_base_uns(nbr, "0123456789abcdef"));
		return (ft_putnbr_base_uns(nbr, "0123456789ABCDEF"));
	}
	if (m == '%')
		return ((int)write(1, "%", 1));
	return (0);
}

int	ft_print(va_list *s, char m)
{
	void						*argiter;
	int							n;
	unsigned long long			pntraddress;

	if (m == 'c')
	{
		n = va_arg(*s, int);
		return ((int)write(1, &n, 1));
	}
	if (m == 's')
	{
		argiter = va_arg(*s, char *);
		if (!argiter)
			argiter = "(null)";
		return ((int)write(1, argiter, ft_strlen(argiter)));
	}
	if (m == 'p')
	{
		pntraddress = va_arg(*s, unsigned long long);
		if (pntraddress == 0)
			return ((int)write (1, "(nil)", 5));
		write(1, "0x", 2);
		return (ft_putptr(pntraddress) + 2);
	}
	return (ft_print_helper(s, m));
}

// int main()
// {
// 	char *m = "abcd";
// 	int l = ft_printf("- %d -\n", 0);
// 	printf("- %d ft_printf -", l);
// 	//printf(" - %d\n", ft_printf("%s %c %p", "abcd", 'a', m));
// }