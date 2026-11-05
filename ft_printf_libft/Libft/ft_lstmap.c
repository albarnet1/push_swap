/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: albarnet <albarnet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/14 13:18:15 by albarnet      #+#    #+#                 */
/*   Updated: 2026/10/19 12:21:48 by albarnet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*lst2;
	void	*content;

	tmp = lst;
	if (!del || !f)
		return (NULL);
	lst2 = NULL;
	while (lst)
	{
		content = f(lst->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			ft_lstclear(&lst2, del);
			del(content);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&lst2, tmp);
	}
	return (lst2);
}
