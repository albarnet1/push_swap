/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/23 13:03:02 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/23 13:04:14 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push a/b: add top element to the other list front
t_stack	*pop(t_stack **stack)
{
	t_stack	*top;

	top = *stack;
	*stack = top->next;
	top->next = NULL;
	return (*stack);
}

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*new;

	if (src == NULL || *src == NULL)
		return ;
	new = *src;
	*src = pop(src);
	ft_stckadd_front(dest, new);
}

void	pa(t_group *group, int bench)
{
	if (group != NULL)
		push(&group->a, &group->b);
	group->ops->pa++;
	if (bench == 0)
		ft_printf("pa\n");
}

void	pb(t_group *group, int bench)
{
	if (group != NULL)
		push(&group->b, &group->a);
	group->ops->pb++;
	if (bench == 0)
		ft_printf("pb\n");
}
