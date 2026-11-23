/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bench.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/23 17:00:08 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/23 18:15:26 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sum_operations(t_counter *stcks)
{
	int	res;

	res = 0;
	res += stcks->sa;
	res += stcks->sb;
	res += stcks->ss;
	res += stcks->pa;
	res += stcks->pb;
	res += stcks->ra;
	res += stcks->rb;
	res += stcks->rr;
	res += stcks->rra;
	res += stcks->rrb;
	res += stcks->rrr;
	return (res);
}

static void	ft_putcount(char *name, int number, int new_line)
{
	if (new_line == 1)
		ft_putstr_fd("\n[bench] ", 2);
	else 
		ft_putchar_fd('	', 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(number, 2);
}

static void	ft_putops_helper(t_counter *op)
{
	ft_putcount("sa", op->sa, 1);
	ft_putcount("sb", op->sb, 0);
	ft_putcount("ss", op->ss, 0);
	ft_putcount("pa", op->pa, 0);
	ft_putcount("pb", op->pb, 0);
	ft_putcount("ra", op->ra, 1);
	ft_putcount("rb", op->rb, 0);
	ft_putcount("rra", op->rra, 0);
	ft_putcount("rrb", op->rrb, 0);
	ft_putcount("rrr", op->rrr, 0);
}

void	ft_bench(t_group *stcks, int bench, int mode, int disorder)
{
	char		*dis;
	t_counter	*tmp;

	tmp = stcks->ops;
	if (bench == 1)
	{
		write(2, "[bench] disorder: ", 19);
		dis = ft_disordertoascii(disorder);
		write(2, dis, ft_strlen(dis));
		free(dis);
		write(2, "%\n[bench] strategy: ", 21);
		if (mode == 1)
			ft_putstr_fd("Simple / O(n^2)", 2);
		if (mode == 2)
			ft_putstr_fd("Medium / O(n√n)", 2);
		if (mode == 3)
			ft_putstr_fd("Complex / O(n log n)", 2);
		if (mode == 4)
			ft_putstr_fd("Adaptive / ", 2);
		ft_putcount("total_ops", ft_sum_operations(tmp), 1);
		ft_putops_helper(stcks->ops);
	}
}
