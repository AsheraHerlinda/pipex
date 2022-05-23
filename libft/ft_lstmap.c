/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:32:39 by asherlin          #+#    #+#             */
/*   Updated: 2021/10/24 13:32:48 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*newel;

	if (!lst)
		return (0);
	map = 0;
	while (lst)
	{
		newel = ft_lstnew(f(lst->content));
		if (!newel)
		{
			ft_lstclear(&map, del);
			return (0);
		}
		ft_lstadd_back(&map, newel);
		lst = lst->next;
	}
	return (map);
}
