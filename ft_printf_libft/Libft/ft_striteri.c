/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/13 11:49:44 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/13 12:23:56 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void	ft_toupper2(unsigned int i, char* s)
// {
// 	if (s[i] >= 'a' && s[i] <= 'z')
// 		s[i] = s[i] - 32;
// }

// int	main(void)
// {
// 	char	str[] = "abcdef";

// 	ft_striteri(str, ft_toupper2);
// 	printf("%s", str);
// }