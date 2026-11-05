/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 14:06:29 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/07 11:26:04 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(unsigned int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

// int	main(void)
// {
// 	int	a = '4';
// 	ft_isalpha(a);
// }

// int ft_isalpha(char str[]) {
// 	int i;
// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
// 			{
// 			printf("%c", '0');
// 			return 0;
// 			}
// 		i++;
// 	}
// 	printf("%c", '1');
// 	return 1;
// }

// int main() {
// 	char a[] = "abcd0";
// 	ft_isalpha(a);
// }
