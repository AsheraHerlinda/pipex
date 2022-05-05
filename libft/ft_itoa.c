/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:17:03 by asherlin          #+#    #+#             */
/*   Updated: 2021/10/20 19:47:37 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(int n)
{
	int	dig;

	dig = 0;
	if (n < 0)
	{
		dig++;
		n = -n;
	}
	while (n / 10 >= 1)
	{
		dig++;
		n = n / 10;
	}
	return (dig + 1);
}

static char	*ft_fillchar(char *str, int n, int size)
{
	int	f;

	f = 0;
	str[size] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
		f = 1;
	}
	while (size > f)
	{
		str[size - 1] = n % 10 + '0';
		size--;
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (n == -2147483648)
	{
		str = ft_itoa(n + 1);
		str[10] = '8';
		return (str);
	}
	size = ft_digit(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	str = ft_fillchar(str, n, size);
	return (str);
}
