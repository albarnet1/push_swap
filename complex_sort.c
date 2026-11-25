/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/12 12:56:43 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/25 13:55:32 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_convertarr(t_stack *stack, int size)
{
	int	*numbers;
	int	i;

	i = 0;
	numbers = NULL;
	numbers = (int *)malloc(sizeof(int) * size);
		if (!numbers)
		return (NULL);
	while (i < size)
	{
		numbers[i++] = stack->number;
		stack = stack->next;
	}
	return (numbers);
}

void	ft_sortarr(int *numbers)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (numbers[i])
	{
		j = 0;
		while (numbers[j])
		{
			if (i != j && numbers[j] > numbers[i])
			{
				tmp = numbers[j];
				numbers[j] = numbers[i];
				numbers[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_match_index(t_group *stcks, int *numbers, int size)
{
	t_stack	*tmp;
	int		j;

	tmp = stcks->a;
	while (tmp != NULL)
	{
		j = 0;
		while (j < size)
		{
			if (numbers[j] == tmp->number)
				tmp->rank = j;
			j++;
		}
		tmp = tmp->next;
	}
	free (numbers);
}

int	ft_count_bit(int size)
{
	int	cnt;

	cnt = 0;
	while (((size - 1) >> cnt) != 0)
		cnt++;
	return (cnt);
}

void	ft_complex(t_group *stcks, int bench)
{
	int	i;
	int	j;
	int	size;
	int	*intarr;

	size = ft_nodecount(stcks->a);
	intarr = ft_convertarr(stcks->a, size);
	if (!intarr)
		return ;
	ft_sortarr(intarr);
	ft_match_index(stcks, intarr, size);
	i = 0;
	while (i++ < ft_count_bit(size))
	{
		j = 0;
		while (j++ < size)
		{
			if ((stcks->a->rank >> i) & 1)
				ra(stcks, bench);
			else
				pb(stcks, bench);
		}
		while (stcks->b != NULL)
			pa(stcks, bench);
	}
}
