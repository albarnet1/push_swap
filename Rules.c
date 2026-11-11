/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Rules.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 15:25:49 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/10 18:42:09 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap a/b: go to the second element and put it in front. Do nothing if there is only one or no elements. 
void	swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
	
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_group *group)
{
	
	if (group != NULL)
		swap(&group->a);
	group->ops->sa++;
}

void	sb(t_group *group)
{
	if (group != NULL)
		swap(&group->b);
	group->ops->sb++;
}

void	ss(t_group *group)
{
	if (group != NULL)
	{
		swap(&group->a);
		swap(&group->b);
	}
	group->ops->ss++;
}

// Push a/b: add top element to the other list front
t_stack *pop(t_stack **stack)
{
	t_stack *top;
	
	top = *stack;
	*stack = top->next;
	top->next = NULL;
	return (*stack);
}

void	push(t_stack **dest, t_stack **src)
{
	t_stack *new;

	if (src == NULL || *src == NULL)
		return ;
	new = *src;
	*src  = pop(src);
	ft_lstadd_front(dest, new);
}

void	pa(t_group *group)
{
	if (group != NULL)
		push(group->a, group->b);
	group->ops->pa++;
}

void	pb(t_group *group)
{
	if (group != NULL)
		push(group->b, group->a);
	group->ops->pb++;
}

// Rotate a/b: The first element becomes the last one.

void	rotate(t_stack **stack)
{
	t_stack *first;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
}

void	ra(t_group *group)
{
	if (group != NULL)
		rotate(&group->a);
	group->ops->ra++;
}

void	rb(t_group *group)
{
	if (group != NULL)
		rotate(&group->b);
	group->ops->rb++;
}

void	rr(t_group *group)
{
	if (group != NULL)
	{
		rotate(&group->a);
		rotate(&group->b);
	}
	group->ops->rr++;
}

// Rotate a/b in the reverse order: The last element becomes the first one.

void rrotate(t_stack **stack)
{
	t_stack *new;
	t_stack *tmp;
	
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	new = ft_lstlast(*stack);
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstlast(*stack)->next = NULL;
	ft_lstadd_front(stack, new);
}

void rra(t_group *group)
{
	if (group != NULL)
		rrotate(&group->a);
	group->ops->rra++;
}

void rrb(t_group *group)
{
	if (group != NULL)
		rrotate(&group->b);
	group->ops->rrb++;
}

void rrr(t_group *group)
{
	if (group != NULL)
		rrotate(&group->a);
		rrotate(&group->b);
	group->ops->rrr++;
}
