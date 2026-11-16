/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 14:43:18 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/16 18:42:18 by albarnet      ########   odam.nl         */
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
	int				rank;
	struct s_stack	*next;
}	t_stack;

typedef	struct s_counter_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_counter;

typedef struct	s_group
{
	t_stack	*a; //pointer to the head node
	t_stack	*b;
	t_counter *ops;
}	t_group;



void	ft_complex(t_group *stcks, int bench);
void	algorithm(int mode, t_group *stcks, int bench);

void	ft_stckadd_front(t_stack **lst, t_stack *new);
void	ft_stckadd_back(t_stack **lst, t_stack *new);
int		ft_stcksize(t_stack *lst);
t_stack	*ft_stcklast(t_stack *lst);
t_stack	*pop(t_stack **stack);
int		ft_compute_disorder(t_stack *stck_a);

void	swap(t_stack **stack);
void	sa(t_group *group, int bench);
void	sb(t_group *group, int bench);
void	ss(t_group *group, int bench);
void	push(t_stack **dest, t_stack **src);
void	pa(t_group *group, int bench);
void	pb(t_group *group, int bench);
void	rotate(t_stack **stack);
void	ra(t_group *group, int bench);
void	rb(t_group *group, int bench);
void	rr(t_group *group, int bench);
void	rrotate(t_stack **stack);
void	rra(t_group *group, int bench);
void	rrb(t_group *group, int bench);
void	rrr(t_group *group, int bench);
int		ft_free(t_stack **stck);


#endif