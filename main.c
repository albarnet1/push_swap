/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 14:43:08 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/10 12:39:04 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "libft.h"
// #include "ft_printf.h"

int	ft_free(t_stack **stck)
{
	t_stack	*tmp;
	if (!stck || !*stck)
		return (0);
	while (*stck)
	{
		tmp = (*stck)->next;
		free(*stck);
		*stck = tmp;
	}
	// free((*stck)->number);
	free(*stck);
	*stck = NULL;
	stck = NULL;
	return (0);
}

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

void	ft_stckadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
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

int main(int argc, char **argv)
{
	int i;
	int mode;
	t_group		*stcks;
	t_stack		*tmp;
	t_stack		*current;

	stcks = malloc(sizeof(t_group));
	if (!stcks)
		return (0);
	stcks->a = NULL;
	stcks->b = NULL;
	i = 2;
	mode = 0;
	if (argc < 2)
		return (0);
	else if (ft_strncmp(argv[1], "--simple", 8) == 0)
		mode = 1;
	else if (ft_strncmp(argv[1], "--medium", 8) == 0)
		mode = 2;
	else if (ft_strncmp(argv[1], "--complex", 9) == 0)
		mode = 3;
	else if (ft_strncmp(argv[1], "--adaptive", 10) == 0)
		mode = 4;
	else 
	{
		if (argv[1] != NULL)
			ft_printf("Error");
		return (0);
	}
	if (ft_fill_list(&(stcks->a), tmp, i, argc, argv) == 0)
		return (0);
	current = stcks->a;
	while (current)
	{
		ft_printf("%d ", current->number);
		current = current->next;
	}
	ft_printf("\n");
	i = 1;
	while (i < argc)
		ft_printf("[%s]\n", argv[i++]);
	ft_printf("{%d}", argc - 1);
	algorithm()
}
