/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:09:17 by asherlin          #+#    #+#             */
/*   Updated: 2021/10/17 18:31:15 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_subsize(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	size = 0;
	if (ft_strlen(s) < start)
		return (size);
	if (ft_strlen(s + start) > len)
		size = len;
	else
		size = ft_strlen(s + start);
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	ptr = malloc(ft_subsize(s, start, len) + 1);
	if (ptr)
	{
		if (ft_strlen(s) < start)
		{
			ptr[0] = '\0';
			return (ptr);
		}
		j = 0;
		i = 0;
		while (s[i])
		{
			if (i >= start && j < ft_subsize(s, start, len))
				ptr[j++] = s[i];
			i++;
		}	
		ptr[j] = '\0';
	}
	return (ptr);
}
