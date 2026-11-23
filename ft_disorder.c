/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_disorder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/13 10:42:24 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/23 18:29:16 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static char *ft_disordertoa_h(int disorder, char *str1, char *str2)
{
	char	*res;

	res = "";
	if ((disorder / 1000) >= 1)
	{
		res = ft_strjoin(str1, ".");
		res = ft_strjoin(res, str2 + 2);
		if (!res)
			return (NULL);
	}
	else if ((disorder / 100) >= 1)
	{
		res = ft_strjoin(str1, ".");
		res = ft_strjoin(res, str2 + 1);
		if (!res)
			return (NULL);
	}
	else if ((disorder / 10) >= 1)
	{
		res = ft_strjoin(str1, ".");
		res = ft_strjoin(res, str2);
		if (!res)
			return (NULL);
	}
	return (res);
}

void *ft_freestrings(char *str1, char *str2)
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

char	*ft_disordertoascii(int disorder)
{
	char *res;
	char *str1;
	char *str2;
	str1 = NULL;
	str2 = NULL;
	str1 = ft_itoa(disorder / 100);
	str2 = ft_itoa(disorder);
	if (!str1 || !str2)
		return (ft_freestrings(str1, str2));
	res = ft_disordertoa_h(disorder, str1, str2);
	if ((disorder / 10) < 1 && (disorder) >= 1)
	{
		res = "0.0";
		res = ft_strjoin(res, str2);
		ft_freestrings(str1, str2);
		if (!res)
			return (ft_freestrings(str1, str2));
		return (res);
	}
	if (disorder < 1)
		res = "0.00";
	ft_freestrings(str1, str2);
	return (res);
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

/* int main(void)
{
	int arr[] = {1, 6, 3, 5, -9999};
	t_stack *a;
	t_stack *next;
	int i = 0;
	
	t_stack *tmp = NULL;
	a = tmp;
	while (arr[i] != -9999)
	{
		tmp = malloc(sizeof(t_stack));
		tmp->next = malloc(sizeof(t_stack));
		if (!tmp)
			return (1);
		tmp->number = arr[i];
		tmp->next = NULL;
		ft_stckadd_back((&a), tmp);
		i++;
	}

	printf("Disorder: %f\n", ft_compute_disorder(a));

	while (a != NULL)
	{
    	next = a->next;
		printf("%i ", a->number);
    	free(a);
    	a = next;
	}

	return (0);
}
*/
