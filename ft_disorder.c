/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_disorder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/13 10:42:24 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/19 13:58:15 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_compute_disorder(t_stack *stck_a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*tmp;
	t_stack	*tmp2;

	mistakes = 0;
	total_pairs = 0;
	tmp = stck_a;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			total_pairs++;
			if (tmp->number > tmp2->number)
				mistakes++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	if (mistakes == 0 && total_pairs == 0)
		return (0);
	return ((mistakes * 100) / total_pairs);
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
