/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_disorder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/13 10:42:24 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/13 13:54:30 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

double	ft_compute_disorder(t_stack *stck_a)
{
	double	mistakes;
	double	total_pairs;
	int		i;
	int		j;
	t_stack	*tmp;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	tmp = stck_a;
	while (i < ft_stcksize(stck_a))
	{
		j = i + 1;
		while (j < ft_stcksize(stck_a) - 1)
		{
			total_pairs++;
			if (tmp->number > tmp->next->number)
				mistakes++;
			j++;
			tmp = tmp->next;
		}
		tmp = stck_a;
		i++;
	}
	return (mistakes / total_pairs);
}

/* int main(void)
{
	int arr[] = {1, 6, 3, 5, -9999};
	t_stack *a;
	t_stack *next;
	int i = 0;
	
	t_stack *tmp = NULL;
	a = tmp;
	while (arr[i] != -9999)
	{
		tmp = malloc(sizeof(t_stack));
		tmp->next = malloc(sizeof(t_stack));
		if (!tmp)
			return (1);
		tmp->number = arr[i];
		tmp->next = NULL;
		ft_stckadd_back((&a), tmp);
		i++;
	}

	printf("Disorder: %f\n", ft_compute_disorder(a));

	while (a != NULL)
	{
    	next = a->next;
		printf("%i ", a->number);
    	free(a);
    	a = next;
	}

	return (0);
}
*/