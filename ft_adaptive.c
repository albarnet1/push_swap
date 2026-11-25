/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_adaptive.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dakuznet <dakuznet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/23 15:10:53 by dakuznet      #+#    #+#                 */
/*   Updated: 2026/11/25 13:32:43 by dakuznet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptive(t_group *stcks, int disorder, int bench)
{
	if (disorder == 0)
		return ;
	disorder = disorder / 100;
	if (disorder < 20)
	{
		ft_simple(stcks, bench);
		stcks->mode = 1;
	}
	else if (disorder >= 20 && disorder < 50)
	{
		ft_medium(stcks, bench);
		stcks->mode = 2;
	}
	else if (disorder >= 50)
	{
		ft_complex(stcks, bench);
		stcks->mode = 3;
	}
}
