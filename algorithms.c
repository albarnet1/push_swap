/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/10 12:11:08 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/11 15:54:33 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_simple(t_group *stcks)
{
	t_stack	*tmp;
	t_stack *tmp2;
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
		pnbr = tmp->number;
		while (tmp != NULL)
		{
			if (pnbr > tmp->number)
			{
				pnbr = tmp->number;
				j = i;
			}
			// if (tmp->next != NULL)
			tmp = tmp->next;
			i++;
		}
		while (j-- > 0)
		{
			rra(stcks);
			tmp2 = stcks->a;
			// while (j-- > 0)
			// {
			// 	printf("%i ", tmp2->number);
			// 	tmp2 = tmp2->next;
			// }
			printf("\n");
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
	return (1);
}

void	algorithm(int mode, t_group *stcks, int bench)
{
	if (mode == 1)
		ft_simple(stcks);
	// if (mode == 2)
	// 	ft_medium(stcks);
	// if (mode == 3)
	// 	ft_complex(stcks);
	// if (mode == 4)
	// 	ft_adaptive(stcks);
}


