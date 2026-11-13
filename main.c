/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 14:43:08 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/13 16:18:10 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *s)
{
	int i;
	int j;
	
	j = 1;
	i = 0;
	if (!s)
	return (0);
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '-' && s[i] != '+')
		j = ft_isdigit(s[i]);
		i++;
		if (j == 0)
		return (0);
	}
	return (1);
}

int	ft_fill_list(t_stack **a, t_stack *tmp, int i, int argc, char **argv)
{
	int nbr;

	nbr = 0;
	while (i < argc)
	{
		if (ft_isnum(argv[i]) == 0)
		{
			ft_printf("Error\n");
			return (ft_free((a)));
		}
		tmp = malloc(sizeof(t_stack));
		if (!tmp)
			return (0);
		nbr = ft_atoi(argv[i++]);
		tmp->number = nbr;
		tmp->next = NULL;
		ft_stckadd_back((a), tmp);
	}
	return (1);
}

int	ft_sum_operations(t_counter *stcks)
{
	int res;
	
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

void	ft_bench(t_group *stcks, int bench, int mode, double disorder)
{
	char c[21];
	t_counter *tmp;

	tmp = stcks->ops;
	if (bench == 1)
	{
		if (mode == 1)
			ft_strlcpy(c, "Simple / O(n^2)", 16);
		if (mode == 2)
			ft_strlcpy(c, "Medium / O(n√n)", 18);
		if (mode == 3)
			ft_strlcpy(c, "Complex / O(n log n)", 21);
		if (mode == 4)
			ft_strlcpy(c, "Adaptive / ", 12);
		ft_printf("[bench] disorder:	%d%%\n", disorder);
		ft_printf("[bench] strategy: %s\n", c);
		ft_printf("[bench] total_ops: %d\n", ft_sum_operations(tmp));
		ft_printf("[bench] sa:	%i	sb:	%i	ss:	%i", tmp->sa, tmp->sb, tmp->ss);
		ft_printf("	pa:	%i	pb:	%i	\n", tmp->pa, tmp->pb);
		ft_printf("[bench] ra:	%i	rb:	%i	rra:	%i", tmp->ra, tmp->rb, tmp->rra);
		ft_printf("	rrb:	%i	rrr:	%i	\n", tmp->rrb, tmp->rrr);
	}
}

// To discuss: we can avoid -> if declare stacks directly and not via pointers
int main(int argc, char **argv)
{
	int i;
	int mode;
	int bench;
	double	disorder;
	t_group		*stcks;
	t_stack		*tmp;
	t_stack		*current;

	stcks = malloc(sizeof(t_group));
	if (!stcks)
		return (0);
	stcks->a = NULL;
	stcks->b = NULL;
	stcks->ops = malloc(sizeof(t_counter));
	i = 1;
	mode = 0;
	bench = 0;
	if (argc < 2)
		return (0);
	if (ft_strncmp(argv[i], "--bench", 7) == 0)
	{
		bench = 1;
		i = 2;
	}
	if (ft_strncmp(argv[i], "--simple", 8) == 0)
		mode = 1;
	else if (ft_strncmp(argv[i], "--medium", 8) == 0)
		mode = 2;
	else if (ft_strncmp(argv[i], "--complex", 9) == 0)
		mode = 3;
	else if (ft_strncmp(argv[i], "--adaptive", 10) == 0)
		mode = 4;
	if (mode != 0 && bench == 1 && argc == 3)
		return (0);
	if (mode != 0)
		i++;
	if (ft_fill_list(&(stcks->a), tmp, i, argc, argv) == 0)
		return (0);
	disorder = ft_compute_disorder(stcks->a);
	// current = stcks->a;
	// while (current)
	// {
	// 	ft_printf("%d ", current->number);
	// 	current = current->next;
	// }
	// ft_printf("\n");
	i = 1;
	// while (i < argc)
	// 	ft_printf("[%s]\n", argv[i++]);
	// ft_printf("{%d}", argc - 1);
	//ft_printf("\n");
	algorithm(mode, stcks, bench);
	// ft_printf("\n");
	// current = stcks->a;
	// while (current)
	// {
	// 	ft_printf("%d ", current->number);
	// 	current = current->next;
	// }
	// ft_printf("\n");
	ft_bench(stcks, bench, mode, disorder);
}
