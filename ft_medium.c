/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_medium.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/12 17:56:00 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/13 15:22:08 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

int sqrt(int n)
{
	int i;

	i = 0;
	while((i + 1) * (i + 1) <= n)
		i++;
	return (i);	
}

int max(t_stack *stck)
{
	int max;

	max = INT_MIN;
	while (stck->next != NULL)
	{
		if (stck->number > max)
			max = stck->number;
		stck = stck -> next;
	}
	return (max);
}

int min(t_stack *stck)
{
	int min;

	min = INT_MAX;
	while (stck->next != NULL)
	{
		if (stck->number < min)
			min = stck->number;
		stck = stck -> next;
	}
	return (min);
}
int	ft_medium(t_group *stcks)
{
	t_stack *a;
	t_stack *b;
	int width;
	int	len;
	int ind;
	int stck_min;
	int stck_max;
	
	a = stcks->a;
	b = stcks->b;
	len = ft_stcksize(a);
	ind = sqrt(len);
	stck_min = min(a);
	stck_max = max(a);
	width = (stck_max - stck_min + 1)/ind;
	while (ind >= 0)
	{
		while (a->next != NULL)
			if (((a->number - stck_min)/width) == ind)
			{
				ft_stckadd_front(stcks->b, a);
				// pop a
			}
		// simple sort inside b;
		// return sorted b to stcks->a;
		// ind++;
		// a = stcks->a;
	}
}

int main(void)
{
	int n = 25;
	printf("sqrt(%i) = %i", n, ft_sqrt(n));

	return (0);
}