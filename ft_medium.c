/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_medium.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/12 17:56:00 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/19 17:05:57 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int ft_sqrt(int n)
{
	int i;

	if (n <= 0)
		return (0);
	i = 0;
	while((i + 1)*(i + 1) <= n)
		i++;
	return (i);	
}

int ft_max(t_stack *stck)
{
	int	pnbr;
	
	pnbr = stck->rank;
	while (stck != NULL)
	{
		if (pnbr < stck->rank)
			pnbr = stck->rank;
		stck = stck->next;
	}
	return(pnbr);
}

// int	*ft_convertarr(t_stack *stack, int size)
// {
// 	int	*numbers;
// 	int	i;

// 	i = 0;
// 	numbers = (int *)malloc(sizeof(int) * size);
// 	while (i < size)
// 	{
// 		numbers[i++] = stack->number;
// 		stack = stack->next;
// 	}
// 	return (numbers);
// }

void ft_ranking(t_stack *a, int len)
{
	int i;
	int j;
	int *arr;
	arr = ft_convertarr(a, len);
	if (!arr)
		return ;
	while (a != NULL)
	{
		i = 0;
		j = 0;
		while(j < len)
		{
			if (a->number > arr[j])
				i++;
			j++;
		}
		a->rank = i;
		a = a->next;
	}
	free (arr); // ???
}

void	ft_medium(t_group *stcks, int bench)
{
	int len = ft_stcksize(stcks->a);
	ft_ranking(stcks->a, len);
	
	int bucket_nmb = ft_sqrt(len);
	int i = bucket_nmb;
	int remaining;
	while (i >= 0)
	{
		remaining = len;
			while (remaining-- > 0 && stcks->a != NULL)
			{
				if ((stcks->a->rank * bucket_nmb/len) == i)
					pb(stcks, bench);
				else
					ra(stcks, bench);
			}
			while (stcks->b != NULL)
			{
				if (stcks->b->rank == ft_max(stcks->b))
					pa(stcks, bench);
				else
					rb(stcks, bench);
			}
		i--;
	}
}