/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/10 12:11:08 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/10 14:13:00 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(int mode, t_group *stcks, int bench)
{
	if (mode == 1)
		ft_simple(stcks);
	if (mode == 2)
		ft_medium(stcks);
	if (mode == 3)
		ft_complex(stcks);
	if (mode == 4)
		ft_adaptive(stcks);
}

int ft_simple(t_group *stcks)
{
	t_stack	*tmp;
	int pnbr;
	tmp = stcks->a;
	while (tmp->next != NULL)
	{
		if (pnbr > tmp->number)
			pnbr = tmp->number;
		ra(stcks->a);
	}
}
