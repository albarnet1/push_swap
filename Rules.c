/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Rules.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 15:25:49 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/23 12:54:22 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

// Rotate a/b: The first element becomes the last one.

void	rotate(t_stack **stack)
{
	t_stack *first;
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

// Rotate a/b in the reverse order: The last element becomes the first one.

void rrotate(t_stack **stack)
{
	t_stack *new;
	t_stack *tmp;
	
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

void rra(t_group *group, int bench)
{
	if (group != NULL)
		rrotate(&group->a);
	group->ops->rra++;
	if (bench == 0)
		ft_printf("rra\n");
}

void rrb(t_group *group, int bench)
{
	if (group != NULL)
		rrotate(&group->b);
	group->ops->rrb++;
	if (bench == 0)
		ft_printf("rrb\n");
}

void rrr(t_group *group, int bench)
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

/* void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%i ", stack->number);
		stack = stack->next;
	}
	printf("\n");
}

void	print_group(t_group group)
{
	printf("stack_a:\n");
	print_stack(group.a);
	printf("stack_b:\n");
	print_stack(group.b);
	printf("\n");
}

int	main(void)
{
	t_stack a_third = {30, NULL};
	t_stack a_second = {20, &a_third};
	t_stack a_first = {10, &a_second};

	t_stack *b_first = NULL;
	t_counter	ops = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	t_group group = {&a_first, b_first, &ops};

	int i = 128;
	int runs = i;
	
	while (i>0)
	{
		sa(&group);
		sb(&group);
		ss(&group);
		pa(&group);
		pb(&group);
		ra(&group);
		rb(&group);
		rr(&group);
		rra(&group);
		rrb(&group);
		rrr(&group);
		i--;
	}

	printf("sa:%i\n", group.ops->sa);
	printf("sb:%i\n", group.ops->sb);
	printf("ss:%i\n", group.ops->ss);
	printf("pa:%i\n", group.ops->pa);
	printf("pb:%i\n", group.ops->pb);
	printf("ra:%i\n", group.ops->ra);
	printf("rb:%i\n", group.ops->rb);
	printf("rr:%i\n", group.ops->rr);
	printf("rra:%i\n", group.ops->rra);
	printf("rrb:%i\n", group.ops->rrb);
	printf("rrr:%i\n", group.ops->rrr);

	printf(".. Runs out of %i runs", runs);
}
 */