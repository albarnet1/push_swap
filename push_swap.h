/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 14:43:18 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/10 16:17:07 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "ft_printf_libft/Libft/libft.h"
# include "ft_printf_libft/ft_printf.h"

typedef struct	s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

typedef struct	s_group
{
	t_stack	*a; //pointer to the head node
	t_stack	*b;
}	t_group;

void	algorithm(int mode, t_group *stcks, int bench);

void	ft_stckadd_front(t_stack **lst, t_stack *new);
void	ft_stckadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stcklast(t_stack *lst);

void	swap(t_stack **stack);
void	sa(t_group *group);
void	sb(t_group *group);
void	ss(t_group *group);
void	push(t_stack *dest, t_stack *src);
void	pa(t_group *group);
void	pb(t_group *group);
void	rotate(t_stack **stack);
void	ra(t_group *group);
void	rb(t_group *group);
void	rr(t_group *group);
void	rrotate(t_stack **stack);
void	rra(t_group *group);
void	rrb(t_group *group);
void	rrr(t_group *group);

#endif