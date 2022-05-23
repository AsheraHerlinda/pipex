/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:44:59 by asherlin          #+#    #+#             */
/*   Updated: 2021/10/17 10:31:10 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (little[j] != '\0')
		j++;
	if (j == 0)
		return ((char *)big);
	j = 0;
	while (big[i] != '\0')
	{
		while ((big[i + j] == little[j] || little[j] == '\0') && i + j <= len)
		{
			if (little[j] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		j = 0;
		i++;
	}	
	return (0);
}
