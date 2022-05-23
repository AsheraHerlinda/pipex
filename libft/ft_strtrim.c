/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:46:47 by asherlin          #+#    #+#             */
/*   Updated: 2021/10/17 19:46:59 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_srcset(const char *s1, const char *set)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (set[y] != '\0')
	{
		if (set[y] == s1[x])
		{
			x++;
			y = -1;
		}
		y++;
	}
	return (x);
}

static size_t	ft_srcset_rev(const char *s1, const char *set)
{
	size_t	x;
	size_t	y;

	x = ft_strlen(s1);
	y = 0;
	while (set[y] != '\0')
	{
		if (set[y] == s1[x - 1])
		{
			x--;
			y = -1;
		}
		y++;
	}	
	if (x != 0)
		return (ft_strlen(s1) - x);
	else
		return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*ptr;

	if (!s1 || !set)
		return (0);
	i = ft_srcset(s1, set);
	j = 0;
	len = ft_strlen(s1) - i - ft_srcset_rev(s1, set);
	ptr = malloc(len + 1);
	if (ptr)
	{
		while (len - j > 0)
		{
			ptr[j] = s1[i];
			j++;
			i++;
		}
		ptr[j] = '\0';
		return (ptr);
	}
	return (0);
}
