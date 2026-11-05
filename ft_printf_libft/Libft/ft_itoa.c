/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/12 18:54:00 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/23 16:38:13 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_helper_function(int n, int posneg, int idx)
{
	char	*str;

	idx = 2;
	str = malloc(idx - posneg);
	if (!str)
		return (NULL);
	if (posneg < 0)
		str[0] = '-';
	str[0 - posneg] = n + 48;
	str[1 - posneg] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		idx;
	int		posneg;

	posneg = 0;
	idx = ft_count(n);
	if (n < 0)
	{
		n *= -1;
		posneg = -1;
	}
	if (n + 48 >= '0' && n + 48 <= '9')
		return (ft_helper_function(n, posneg, idx));
	str = (char *)malloc((char)idx + 1);
	if (!str)
		return (NULL);
	str[idx--] = 0;
	while (idx >= 0)
	{
		str[idx--] = ((unsigned int)n % 10) + 48;
		n = (unsigned int)n / 10;
	}
	if (posneg < 0)
		str[0] = '-';
	return (str);
}

// int	main(void)
// {
// 	unsigned int	n;

// 	n = 2147483648;
// 	printf("%s", ft_itoa(n));
// }