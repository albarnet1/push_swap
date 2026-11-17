/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_onerror_funcs.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/17 14:41:52 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/17 14:55:03 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free(t_group **stcks)
{
	t_stack	*tmp;

	if (!stcks || !*stcks)
		return (0);
	while ((*stcks)->a)
	{
		tmp = (*stcks)->a->next;
		free((*stcks)->a);
		(*stcks)->a = tmp;
	}
	while ((*stcks)->b)
	{
		tmp = (*stcks)->b->next;
		free((*stcks)->b);
		(*stcks)->b = tmp;
	}
	free((*stcks)->a);
	(*stcks)->a = NULL;
	free((*stcks)->b);
	(*stcks)->b = NULL;
	free((*stcks)->ops);
	(*stcks)->ops = NULL;
	free(*stcks);
	*stcks = NULL;
	return (0);
}
