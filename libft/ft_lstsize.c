/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:06:18 by asherlin          #+#    #+#             */
/*   Updated: 2021/10/24 11:06:54 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	c;

	c = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		c++;
		lst = lst->next;
	}
	return (c);
}
