/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_disorder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/13 10:42:24 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/13 16:16:18 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_compute_disorder(t_stack *stck_a)
{
	int		mistakes;
	int		total_pairs;
	int	i;
	int	j;
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

// int main(void)
// {
// 	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
// 	t_stack *a;
// 	t_stack *next;
// 	int i = 0;
	
// 	t_stack *tmp = NULL;
// 	a = tmp;
// 	while (i < 8)
// 	{
// 		tmp = malloc(sizeof(t_stack));
// 		tmp->next = malloc(sizeof(t_stack));
// 		if (!tmp)
// 			return (1);
// 		tmp->number = arr[i];
// 		tmp->next = NULL;
// 		ft_stckadd_back((&a), tmp);
// 		i++;
// 	}

// 	while (a != NULL)
// 	{
//     	next = a->next;
// 		printf("%i ", a->number);
//     	free(a);
//     	a = next;
// 	}

// 	return (0);
// }
