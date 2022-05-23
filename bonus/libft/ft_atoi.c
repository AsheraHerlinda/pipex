/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:41:05 by asherlin          #+#    #+#             */
/*   Updated: 2021/10/17 11:32:26 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		res;
	char	*s;

	i = 0;
	sign = 1;
	res = 0;
	s = (char *)nptr;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\r' || \
			s[i] == '\f' || s[i] == '\v' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (48 <= s[i] && s[i] <= 57)
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res * sign);
}
