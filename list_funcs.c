/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_funcs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/10 15:56:50 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/13 13:59:22 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stckadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_stcklast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (lst == 0)
		return (NULL);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_stckadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int	ft_stcksize(t_stack *lst)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_free(t_stack **stck)
{
	t_stack	*tmp;
	if (!stck || !*stck)
		return (0);
	while (*stck)
	{
		tmp = (*stck)->next;
		free(*stck);
		*stck = tmp;
	}
	free(*stck);
	*stck = NULL;
	stck = NULL;
	return (0);
}