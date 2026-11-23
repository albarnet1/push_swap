/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_simple.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/23 15:36:00 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/23 15:54:35 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple_stack_operations(t_group *stcks, int bench, int j)
{
	if (j > (ft_nodecount(stcks->a) / 2))
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

	while (stcks->a != NULL)
	{
		tmp = stcks->a;
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
	}
	while (stcks->b != NULL)
		pa(stcks, bench);
}
