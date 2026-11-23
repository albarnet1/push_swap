/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rrotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/23 13:06:34 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/23 13:07:41 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_stack **stack)
{
	t_stack	*new;
	t_stack	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	new = ft_stcklast(*stack);
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_stcklast(*stack)->next = NULL;
	ft_stckadd_front(stack, new);
}

void	rra(t_group *group, int bench)
{
	if (group != NULL)
		rrotate(&group->a);
	group->ops->rra++;
	if (bench == 0)
		ft_printf("rra\n");
}

void	rrb(t_group *group, int bench)
{
	if (group != NULL)
		rrotate(&group->b);
	group->ops->rrb++;
	if (bench == 0)
		ft_printf("rrb\n");
}

void	rrr(t_group *group, int bench)
{
	if (group != NULL)
	{
		rrotate(&group->a);
		rrotate(&group->b);
	}
	group->ops->rrr++;
	if (bench == 0)
		ft_printf("rrr\n");
}
