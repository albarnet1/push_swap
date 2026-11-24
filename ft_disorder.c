/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_disorder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/13 10:42:24 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/24 17:35:31 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	*ft_freestrings(char *str1, char *str2)
{
	if (!str1 || !str2)
	{
		free(str1);
		str1 = NULL;
		free(str2);
		str2 = NULL;
		return (NULL);
	}
	free(str1);
	str1 = NULL;
	free(str2);
	str2 = NULL;
	return (NULL);
}

static void	ft_disordertoa_h(int disorder, char *str2)
{
	if ((disorder / 1000) >= 1)
	{
		ft_putnbr_fd(disorder / 100, 2);
		ft_putchar_fd('.', 2);
		ft_putstr_fd(str2 + 2, 2);
	}
	else if ((disorder / 100) >= 1)
	{
		ft_putnbr_fd(disorder / 100, 2);
		ft_putchar_fd('.', 2);
		ft_putstr_fd(str2 + 1, 2);
	}
	else if ((disorder / 10) >= 1)
	{
		ft_putnbr_fd(disorder / 100, 2);
		ft_putchar_fd('.', 2);
		ft_putstr_fd(str2, 2);
	}
}

void	ft_disordertoascii(int disorder)
{
	char	*str2;

	str2 = NULL;
	str2 = ft_itoa(disorder);
	if (!str2)
		return ;
	ft_disordertoa_h(disorder, str2);
	if ((disorder / 10) < 1 && (disorder) >= 1)
	{
		ft_putstr_fd("0.0", 2);
		ft_putstr_fd(str2, 2);
	}
	if (disorder < 1)
		ft_putstr_fd("0.00", 2);
	free (str2);
}

int	ft_compute_disorder(t_stack *stck_a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*tmp;
	t_stack	*tmp2;

	mistakes = 0;
	total_pairs = 0;
	tmp = stck_a;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			total_pairs++;
			if (tmp->number > tmp2->number)
				mistakes++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	if (mistakes == 0 && total_pairs == 0)
		return (0);
	return ((mistakes * 10000) / total_pairs);
}

// int main(void)
// {
// 	int arr[] = {1, 3, 2, -9999};
// 	t_stack *a;
// 	t_stack *next;
// 	int i = 0;

// 	t_stack *tmp = NULL;
// 	a = tmp;
// 	while (arr[i] != -9999)
// 	{
// 		tmp = malloc(sizeof(t_stack));
// 		tmp->next = malloc(sizeof(t_stack));
// 		if (!tmp)
// 			return (1);
// 		tmp->number = arr[i];
// 		tmp->next = NULL;
// 		ft_stckadd_back((&a), tmp);
// 		i++;
// 	}

// 	printf("Disorder: %d\n", ft_compute_disorder(a));

// 	while (a != NULL)
// 	{
//     	next = a->next;
// 		printf("%i ", a->number);
//     	free(a);
//     	a = next;
// 	}

// 	return (0);
// }
