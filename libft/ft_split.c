/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:09:32 by asherlin          #+#    #+#             */
/*   Updated: 2021/10/20 19:48:05 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_cr_word(char const *s, size_t i, char c)
{
	char	*word;
	size_t	len;

	len = 0;
	while (s[i + len] != c && s[i + len])
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (0);
	len = 0;
	while (s[i + len] != c && s[i + len])
	{
		word[len] = s[i + len];
		len++;
	}
	word[len] = '\0';
	return (word);
}

static void	ft_clean(char **arr, size_t j)
{
	while (j != 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr[0]);
	return ;
}

static char	**ft_makearr(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			arr[j] = ft_cr_word(s, i, c);
			if (arr[j] == NULL)
			{
				ft_clean(arr, j);
				free(arr);
				return (0);
			}
			i = i + ft_strlen(arr[j]) - 1;
			j++;
		}
		i++;
	}
	arr[j] = (void *)0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_words;

	if (!s)
		return (0);
	arr_words = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!arr_words)
		return (0);
	arr_words = ft_makearr(arr_words, s, c);
	if (arr_words == NULL)
	{
		free(arr_words);
		return (NULL);
	}
	return (arr_words);
}
