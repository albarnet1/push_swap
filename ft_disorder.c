/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_disorder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/13 10:42:24 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/13 12:01:54 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_compute_disorder(t_stack *stck_a)
{
	int mistakes = 0;
	int total_pairs = 0;
	size_t i = 0;
	size_t j = i + 1;
	size_t len;
	t_stack *tmp;
	
	tmp = stck_a;
	len = ft_stcksize(stck_a);
	while(i < len)
	{
		while (j < len - 1)
			{
				total_pairs++;
				if (tmp->number > tmp->next->number)
				{
					mistakes++;
				}
				j++;
				tmp = tmp->next;
			}
		tmp = stck_a;
		i++;
		j = i + 1;
	}
	return (mistakes / total_pairs);
}