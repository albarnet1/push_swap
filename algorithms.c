/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/10 12:11:08 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/23 15:34:58 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple_stack_operations(t_group *stcks, int bench, int j)
{
	if (j > (ft_nodecount(stcks->a)/2))
	{
		while (j++ < ft_nodecount(stcks->a))
			rra(stcks, bench);
	}
	else
	{
		while (j-- > 0)
			ra(stcks, bench);
	}
	pb(stcks, bench);
}

void	ft_simple(t_group *stcks, int bench)
{
	t_stack	*tmp;
	int		pnbr;
	int		i;
	int		j;

	tmp = stcks->a;
	while (stcks->a != NULL)
	{
		j = 0;
		i = 0;
		pnbr = tmp->number;
		while (tmp != NULL)
		{
			if (pnbr > tmp->number)
			{
				pnbr = tmp->number;
				j = i;
			}
			tmp = tmp->next;
			i++;
		}
		ft_simple_stack_operations(stcks, bench, j);
		tmp = stcks->a;
	}
	tmp = stcks->b;
	while (tmp != NULL)
	{
		pa(stcks, bench);
		tmp = stcks->b;
	}
}

void	algorithm(int mode, t_group *stcks, int disorder, int bench)
{
	if (mode == 1)
		ft_simple(stcks, bench);
	if (mode == 2)
		ft_medium(stcks, bench);
	if (mode == 3)
		ft_complex(stcks, bench);
	if (mode == 4)
		ft_adaptive(stcks, disorder, bench);
}