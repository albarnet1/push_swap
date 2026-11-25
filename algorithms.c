/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/10 12:11:08 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/25 14:13:30 by albarnet      ########   odam.nl         */
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

void	algorithm(t_group *stcks, int disorder, int bench)
{
	stcks->a_size = ft_nodecount(stcks->a);
	ft_init_operations(stcks->ops);
	if (disorder != 0)
	{
		ft_init_operations(stcks->ops);
		if (stcks->mode == 1)
			ft_simple(stcks, bench);
		if (stcks->mode == 2)
			ft_medium(stcks, bench);
		if (stcks->mode == 3)
			ft_complex(stcks, bench);
		else
			ft_adaptive(stcks, disorder, bench);
	}
}
