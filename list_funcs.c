/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_funcs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/10 15:56:50 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/11 17:11:23 by dakuznet      ########   odam.nl         */
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

void	ft_delhead(t_stack **head)
{
	t_stack *tmp;
	
	tmp = *head;
    tmp = tmp->next;
    free(*head);
    *head = tmp;
}