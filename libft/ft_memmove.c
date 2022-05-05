/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:32:50 by asherlin          #+#    #+#             */
/*   Updated: 2021/10/13 19:18:16 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;	
	unsigned char	*s;

	i = 0;
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (dest == NULL && src == NULL)
		return (0);
	if (d < s)
		ft_memcpy(dest, src, n);
	else
	{
		i = n - 1;
		while (n--)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}
