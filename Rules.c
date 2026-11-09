/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Rules.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 15:25:49 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/09 13:01:51 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap a/b: go to the second element and put it in front. Do nothing if there is only one or no elements. 
void	swap(t_list **lst)
{
	t_list *first;
	t_list *second;
	
	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}

void	sa(t_stack *stack)
{
	if (stack != NULL)
		swap(&stack->a);
}

void	sb(t_stack *stack)
{
	if (stack != NULL)
		swap(&stack->b);
}

void	ss(t_stack *stack)
{
	if (stack != NULL)
	{
		swap(&stack->a);
		swap(&stack->b);
	}
}

// Push a/b: add top element to the other list front
void	pa(void)
{
	if (b[0] != NULL)
		ft_lstadd_front(a, b[0]);
}

void	pb(void)
{
	if (a[0] != NULL)
		ft_lstadd_front(b, a[0]);
}

// Rotate a/b: The first element becomes the last one.
void	ra(void)
{
	ft_lstadd_back(a, a[0]);
	free(a[0]);
}

void	rb(void)
{
	if (b[0] != NULL)
	{
		ft_lstadd_back(b, b[0]);
		free(b[0]);
	}
}

void	rr(void)
{
	ra();
	rb();
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
