/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/19 13:30:39 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/25 16:52:37 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONVERSIONS "cspdiuxX%"
# include <stdio.h>
# include <stdarg.h>
# include "Libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_print(va_list *s, char m);
void	ft_puthex_fd(int n, char *base);
int		ft_putnbr_base(int n, char *base);
int		ft_putptr(long long unsigned n);
int		ft_putnbr_base_uns(unsigned int n, char *base);

#endif