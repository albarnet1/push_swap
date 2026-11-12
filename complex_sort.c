/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/12 12:56:43 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/12 14:35:46 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_complex(t_group *stcks)
{
	t_stack	*tmp;
	int pnbr;
	int i;
	int j;

	j = 0;
	i = 0;
	tmp = stcks->a;
	while (stcks->a != NULL)
	{
		j = 0;
		i = 0;
		pnbr = tmp->number % 10;
		while (tmp != NULL)
		{
			if (pnbr > tmp->number % 10)
			{
				pnbr = tmp->number % 10;
				j = i;
			}
			tmp = tmp->next;
			i++;
		}
		while (j-- > 0)
		{
			ra(stcks);
		}
		pb(stcks);
		tmp = stcks->a;
	}
	tmp = stcks->b;
	while (tmp != NULL)
	{
		pa(stcks);
		tmp = stcks->b;
	}
}