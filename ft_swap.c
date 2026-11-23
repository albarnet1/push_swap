/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/23 13:00:51 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/23 13:02:27 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_group *group, int bench)
{
	if (group != NULL)
		swap(&group->a);
	group->ops->sa++;
	if (bench == 0)
		ft_printf("sa\n");
}

void	sb(t_group *group, int bench)
{
	if (group != NULL)
		swap(&group->b);
	group->ops->sb++;
	if (bench == 0)
		ft_printf("sb\n");
}

void	ss(t_group *group, int bench)
{
	if (group != NULL)
	{
		swap(&group->a);
		swap(&group->b);
	}
	group->ops->ss++;
	if (bench == 0)
		ft_printf("ss\n");
}
