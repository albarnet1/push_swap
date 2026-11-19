/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Medium_algorithm_demo.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 11:14:34 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/19 12:17:56 by dakuznet      ########   odam.nl         */
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
		printf("sa\n");
}

void	sb(t_group *group, int bench)
{
	if (group != NULL)
		swap(&group->b);
	group->ops->sb++;
	if (bench == 0)
		printf("sb\n");
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
		printf("ss\n");
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
		printf("pa\n");
}

void	pb(t_group *group, int bench)
{
	if (group != NULL)
		push(&group->b, &group->a);
	group->ops->pb++;
	if (bench == 0)
		printf("pb\n");
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
		printf("ra\n");
}

void	rb(t_group *group, int bench)
{
	if (group != NULL)
		rotate(&group->b);
	group->ops->rb++;
	if (bench == 0)
		printf("rb\n");
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
		printf("rr\n");
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
		printf("rra\n");
}

void rrb(t_group *group, int bench)
{
	if (group != NULL)
		rrotate(&group->b);
	group->ops->rrb++;
	if (bench == 0)
		printf("rrb\n");
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
		printf("rrr\n");
}

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%i - %i\n", stack->number, stack->rank);
		stack = stack->next;
	}
	printf("\n");
}

int ft_sqrt(int n)
{
	int i;

	i = 0;
	while((i + 1) * (i + 1) <= n)
		i++;
	return (i);	
}

int ft_max(t_stack *stck)
{
	int pnbr = stck->rank;
	while (stck != NULL)
	{
		if (pnbr < stck->rank)
			pnbr = stck->rank;
		stck = stck->next;
	}
	return(pnbr);
}

int ft_min(t_stack *stck)
{
	int pnbr = stck->number;
	while (stck != NULL)
	{
		if (pnbr > stck->number)
			pnbr = stck->number;
		stck = stck->next;
	}
	return(pnbr);
}

t_stack *fill_stack(t_stack *a, int *arr)
{
	t_stack *tmp;
	int i;
	
	i = 0;
	while (arr[i] != -9999)
	{
		tmp = malloc(sizeof(t_stack));
		if (!tmp)
			return(tmp);
		tmp->number = arr[i];
		tmp->next = NULL;
		ft_stckadd_back((&a), tmp);
		i++;
	}
	return (a);
}

int	*ft_convertarr(t_stack *stack, int size)
{
	int	*numbers;
	int	i;

	i = 0;
	numbers = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		numbers[i++] = stack->number;
		stack = stack->next;
	}
	return (numbers);
}

void ft_ranking(t_stack *a, int len)
{
	int i;
	int j;
	int *arr;
	arr = ft_convertarr(a, len);
	while (a != NULL)
	{
		i = 0;
		j = 0;
		while(j < len)
		{
			if (a->number > arr[j])
				i++;
			j++;
		}
		a->rank = i;
		a = a->next;
	}
}

int main(void)
{
	int arr[] = {2, 5, 9, 37, 12, 58, 44, 23, 61, 18, 50, 31, 47, 26, 55, 14, -9999};
	//int arr[] = {1, 2, 3, 0, -9999};
	t_stack *a = NULL;
	t_stack *b = NULL;
	//t_counter *ops = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	t_counter ops = {0};
	
	a = fill_stack(a, arr);
	t_group group = {a, b, &ops};
	
	int len = ft_stcksize(group.a);
	
	ft_ranking(group.a, len);
	printf("stack_a:\n");
	print_stack(group.a);
	printf("stack_b:\n");
	print_stack(group.b);
	
	int bench = 1;
	int bucket_nmb = ft_sqrt(len);
	int i = bucket_nmb;
	int remaining;
	
	while (i >= 0)
	{
		printf("Bucket: %i\n", i);
		remaining = len;
			while (remaining-- > 0 && group.a != NULL)
			{
				if ((group.a->rank * bucket_nmb/len) == i)
					pb(&group, bench);
				else
					ra(&group, bench);
			}
			while (group.b != NULL)
			{
				if (group.b->rank == ft_max(group.b))
					pa(&group, bench);
				else
					rb(&group, bench);
			}
		i--;
	}
	
	printf("stack_a:\n");
	print_stack(group.a);
	printf("stack_b:\n");
	print_stack(group.b);
	
	// printf("stack_a:\n");
	// print_stack(group.a);
	// printf("stack_b:\n");
	// print_stack(group.b);
	// push(&group.b, &group.a);
	// printf("Push:\n");
	// printf("stack_a:\n");
	// print_stack(group.a);
	// printf("stack_b:\n");
	// print_stack(group.b);
	// printf("\n");
	
	// push(&group.b, &group.a);
	// printf("Push:\n");
	// printf("stack_a:\n");
	// print_stack(group.a);
	// printf("stack_b:\n");
	// print_stack(group.b);
	// printf("\n");

	// rotate(&group.a);
	// rotate(&group.b);
	// printf("Rotate:\n");
	// printf("stack_a:\n");
	// print_stack(group.a);ft_ranking(group.a, len);
	// printf("stack_b:\n");
	// print_stack(group.b);
	// printf("\n");
	
	// rrotate(&group.a);
	// rrotate(&group.b);
	// printf("Reverse rotate:\n");
	// printf("stack_a:\n");
	// print_stack(group.a);
	// printf("stack_b:\n");
	// print_stack(group.b);
	// printf("\n");

	// push(&group.a, &group.b);
	// printf("Push:\n");
	// printf("stack_a:\n");
	// print_stack(group.a);
	// printf("stack_b:\n");
	// print_stack(group.b);
	// printf("\n");

	t_stack *next;
	while (a != NULL)
	{
    	next = a->next;
    	free(a);
    	a = next;
	}
	
	return (0);
}