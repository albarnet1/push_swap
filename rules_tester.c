/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules_tester.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/09 15:16:12 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/10 14:53:32 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
#include <stddef.h>

// Struct declaration
typedef struct	s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

typedef struct	s_group
{
	t_stack	*a; //pointer to the head node
	t_stack	*b;
}	t_group;

// List functions
void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_lstlast(t_stack *lst)
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

void	ft_lstadd_back(t_stack **lst, t_stack *new)
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

// stack functions
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

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%i ", stack->number);
		stack = stack->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack a_third = {30, NULL};
	t_stack a_second = {20, &a_third};
	t_stack a_first = {10, &a_second};

	t_stack b_first = {10, NULL};
	t_group group = {&a_first, &b_first};

	printf("stack_a:\n");
	print_stack(group.a);
	printf("stack_b:\n");
	print_stack(group.b);
	printf("\n");
	
	push(&group.a, &group.b);
	printf("Push:\n");
	printf("stack_a:\n");
	print_stack(group.a);
	printf("stack_b:\n");
	print_stack(group.b);
	printf("\n");
	
/* 	push(&group.b, &group.a);
	printf("Push:\n");
	printf("stack_a:\n");
	print_stack(group.a);
	printf("stack_b:\n");
	print_stack(group.b);
	printf("\n");

	rotate(&group.a);
	rotate(&group.b);
	printf("Rotate:\n");
	printf("stack_a:\n");
	print_stack(group.a);
	printf("stack_b:\n");
	print_stack(group.b);
	printf("\n");
	
	rrotate(&group.a);
	rrotate(&group.b);
	printf("Reverse rotate:\n");
	printf("stack_a:\n");
	print_stack(group.a);
	printf("stack_b:\n");
	print_stack(group.b);
	printf("\n");

	push(&group.a, &group.b);
	printf("Push:\n");
	printf("stack_a:\n");
	print_stack(group.a);
	printf("stack_b:\n");
	print_stack(group.b);
	printf("\n"); */
}