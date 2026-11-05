/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 14:43:18 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/05 16:57:33 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "ft_printf_libft/Libft/libft.h"
# include "ft_printf_libft/ft_printf.h"

typedef struct	s_list
{
	int	number;
	struct s_list	*next;
}	t_list;

#endif