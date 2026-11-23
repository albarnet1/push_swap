/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/23 13:04:38 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/23 13:06:08 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate a/b: The first element becomes the last one.
void	rotate(t_stack **stack)
{
	t_stack	*first;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	ft_stckadd_back(stack, first);
}

void	ra(t_group *group, int bench)
{
	if (group != NULL)
		rotate(&group->a);
	group->ops->ra++;
	if (bench == 0)
		ft_printf("ra\n");
}

void	rb(t_group *group, int bench)
{
	if (group != NULL)
		rotate(&group->b);
	group->ops->rb++;
	if (bench == 0)
		ft_printf("rb\n");
}

void	rr(t_group *group, int bench)
{
	if (group != NULL)
	{
		rotate(&group->a);
		rotate(&group->b);
	}
	group->ops->rr++;
	if (bench == 0)
		ft_printf("rr\n");
}
