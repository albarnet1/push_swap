/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/10 12:11:08 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/24 12:21:24 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_operations(t_counter *ops)
{
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
}

void	algorithm(int mode, t_group *stcks, int disorder, int bench)
{
	ft_init_operations(stcks->ops);
	if (mode == 1)
		ft_simple(stcks, bench);
	if (mode == 2)
		ft_medium(stcks, bench);
	if (mode == 3)
		ft_complex(stcks, bench);
	if (mode == 4)
		ft_adaptive(stcks, disorder, bench);
}
