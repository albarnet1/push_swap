/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_medium.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/12 17:56:00 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/23 12:32:32 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 0;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}

int	ft_max(t_stack *stck)
{
	int	pnbr;

	pnbr = stck->rank;
	while (stck != NULL)
	{
		if (pnbr < stck->rank)
			pnbr = stck->rank;
		stck = stck->next;
	}
	return (pnbr);
}

void	ft_ranking(t_stack *a, int len)
{
	int	i;
	int	j;
	int	*arr;

	arr = ft_convertarr(a, len);
	if (!arr)
		return ;
	while (a != NULL)
	{
		i = 0;
		j = 0;
		while (j < len)
		{
			if (a->number > arr[j])
				i++;
			j++;
		}
		a->rank = i;
		a = a->next;
	}
	free (arr);
}

void	return_to_stack(t_group *stcks, int bench)
{
	while (stcks->b != NULL)
	{
		if (stcks->b->rank == ft_max(stcks->b))
			pa(stcks, bench);
		else
			rb(stcks, bench);
	}
}

void	ft_medium(t_group *stcks, int bench)
{
	int	len;
	int	bucket_nmb;
	int	i;
	int	remaining;

	len = ft_nodecount(stcks->a);
	ft_ranking(stcks->a, len);
	bucket_nmb = ft_sqrt(len);
	i = bucket_nmb;
	while (i >= 0)
	{
		remaining = len;
		while (remaining-- > 0 && stcks->a != NULL)
		{
			if ((stcks->a->rank * bucket_nmb / len) == i)
				pb(stcks, bench);
			else
				ra(stcks, bench);
		}
		return_to_stack(stcks, bench);
		i--;
	}
}
