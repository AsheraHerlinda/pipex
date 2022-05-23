/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:32:50 by asherlin          #+#    #+#             */
/*   Updated: 2021/10/13 19:18:16 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*t;

	i = 0;
	t = (char *) s;
	while (n > 0)
	{
		t[i] = c;
		n--;
		i++;
	}
	s = (void *) t;
	return (s);
}
