/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:12:11 by asherlin          #+#    #+#             */
/*   Updated: 2021/10/17 13:27:44 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len_s;

	len_s = ft_strlen(s);
	ptr = (char *)malloc(len_s + 1);
	if (ptr)
	{
		ft_memcpy(ptr, s, len_s + 1);
		return (ptr);
	}
	return (0);
}
