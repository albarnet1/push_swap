/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 14:43:08 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/24 14:58:06 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *s)
{
	int	i;
	int	j;

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

int	ft_fill_list(t_group *stcks, int i, int argc, char **argv)
{
	int			nbr;
	char		**splitted;
	int			j;
	t_stack		*tmp;

	j = 0;
	nbr = 0;
	if (!argv[i])
		return (0);
	j = i;
	while (argv[argc - 1][0] == '\0')
	{
		argc--;
	}
	while (strncmp(argv[j++], "", 1) == 0 && i != argc)
	{
		if (j == argc)
			return (ft_free(&stcks));
	}
	j = 0;
	while (i < argc)
	{
		if (ft_isnum(argv[i]) == 0)
		{
			write(2, "Error\n", 6);
			return (ft_free(&stcks));
		}
		if (strncmp(argv[i], "", 1) == 0 && i < argc)
			i++;
		splitted = ft_split(argv[i++], ' ');
		if (!splitted)
			return (ft_free(&stcks));
		while (splitted[j] != NULL)
		{
			tmp = malloc(sizeof(t_stack));
			if (!tmp)
				return (ft_free(&stcks));
			nbr = ft_atoi(splitted[j++]);
			tmp->number = nbr;
			tmp->next = NULL;
			ft_stckadd_back((&stcks->a), tmp);
		}
		ft_free_split(splitted);
		j = 0;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	int			mode;
	int			bench;
	int			disorder;
	t_group		*stcks;

	stcks = malloc(sizeof(t_group));
	if (!stcks)
		return (0);
	stcks->a = NULL;
	stcks->b = NULL;
	stcks->ops = NULL;
	stcks->ops = malloc(sizeof(t_counter));
	if (stcks->ops == NULL)
		return (ft_free(&stcks));
	i = 1;
	mode = 0;
	bench = 0;
	if (argc < 2)
		return (ft_free(&stcks));
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
		return (ft_free(&stcks));
	if (mode != 0)
		i++;
	if (ft_fill_list(stcks, i, argc, argv) == 0)
		return (0);
	if (ft_check_duplicates(stcks) == 0)
		return (0);
	disorder = ft_compute_disorder(stcks->a);
	algorithm(mode, stcks, disorder, bench);
	ft_bench(stcks, bench, mode, disorder);
	ft_free(&stcks);
}
