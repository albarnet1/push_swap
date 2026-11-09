/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Rules.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 15:25:49 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/09 14:24:04 by dakuznet      ########   odam.nl         */
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
}

void	sb(t_group *group)
{
	if (group != NULL)
		swap(&group->b);
}

void	ss(t_group *group)
{
	if (group != NULL)
	{
		swap(&group->a);
		swap(&group->b);
	}
}

// Push a/b: add top element to the other list front
void	push(t_stack *dest, t_stack *src)
{
	if (src != NULL)
		ft_lstadd_front(&dest, src);
}

void	pa(t_group *group)
{
	if (group != NULL)
		push(group->a, group->b);
}

void	pb(t_group *group)
{
	if (group != NULL)
		push(group->b, group->a);
}

// Rotate a/b: The first element becomes the last one.

void	rotate(t_stack **stack)
{
	t_stack	*new;
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
}

void	rb(t_group *group)
{
	if (group != NULL)
		rotate(&group->b);
}

void	rr(t_group *group)
{
	if (group != NULL)
	{
		rotate(&group->a);
		rotate(&group->b);
	}
}

// Rotate a/b in the reverse order: The last element becomes the first one.

void rra()
{
	int	i;
	i = ft_lstsize(a[0]) - 1;
	ft_lstadd_front(a, a[i]);
	free(a[i]);
}

void rrb()
{
	int	i;
	i = ft_lstsize(b[0]) - 1;
	ft_lstadd_front(b, b[i]);
	free(b[i]);
}

void rrr()
{
	rra();
	rrb();
}
