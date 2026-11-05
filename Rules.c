/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Rules.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 15:25:49 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/05 16:26:38 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap a/b: go to the second element and put it in front
void	sa(void)
{
	ft_lstadd_front(a, a[1]);
}

void	sb(void)
{
	ft_lstadd_front(b, b[1]);
}

void	ss(void)
{
	sa();
	sb();
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
