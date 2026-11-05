/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 14:43:08 by albarnet      #+#    #+#                 */
/*   Updated: 2026/11/05 15:52:44 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int i;
	

	i = 1;
	while (1)
	{
		// while (argv[i] >= '0' && argv[i] <= '9')
		// {
			
		// }
		// if (argv[i] == "--simple")
		// {
		// 	ft_sort_simple();
		// 	i++;
		// }
		// if (argv[i] == "--medium")
		// {
		// 	ft_sort_medium();
		// 	i++;
		// }
		// if (argv[i] == "--complex")
		// {
		// 	ft_sort_complex();
		// 	i++;
		// }
		// if (argv[i] == "--adaptive")
		// {
		// 	ft_sort_adaptive();
		// 	i++;
		// }
		break ;
	}
	while(i < argc)
		ft_printf("%s\n", argv[i++]);
	ft_printf("%d", argc - 1);
}
