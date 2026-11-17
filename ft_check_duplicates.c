/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_duplicates.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/17 13:54:49 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/17 16:39:31 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicates(t_group *stcks)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (stcks->a == NULL)
		return (ft_free(&stcks));
	tmp1 = stcks->a;
	tmp2 = tmp1->next;
	while (tmp1 != NULL)
	{
		while (tmp2 != NULL)
		{
			if (tmp2->number == tmp1->number)
			{
				ft_free(&stcks);
				write(2, "Error\n", 6);
				return (0);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		if (tmp1 != NULL)
			tmp2 = tmp1->next;
	}
	return (1);
}
