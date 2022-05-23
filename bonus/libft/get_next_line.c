/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2021/12/09 20:44:13 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_temp_line(char *temp_line, int fd);
static char	*ft_create_line(void);
static char	*ft_fill_res_line(char *temp_line);
static char	*ft_fill_rem_line(char *temp_line);

char	*get_next_line(int fd)
{
	char		*res_line;
	static char	*temp_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (temp_line)
			free(temp_line);
		return (NULL);
	}
	temp_line = ft_get_temp_line(temp_line, fd);
	if (!temp_line)
		return (NULL);
	res_line = ft_fill_res_line(temp_line);
	temp_line = ft_fill_rem_line(temp_line);
	return (res_line);
}

static char	*ft_get_temp_line(char *temp_line, int fd)
{
	char	*buf;
	int		byte_read;
	char	*tmp;

	byte_read = 1;
	if (!temp_line)
		temp_line = ft_create_line();
	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(temp_line, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[byte_read] = '\0';
		tmp = temp_line;
		temp_line = ft_strjoin(temp_line, buf);
		free(tmp);
	}
	free (buf);
	return (temp_line);
}

static char	*ft_create_line(void)
{
	char	*line;

	line = malloc(sizeof(char));
	line[0] = '\0';
	return (line);
}

static char	*ft_fill_res_line(char *temp_line)
{
	char	*res_line;
	int		i;

	i = 0;
	if (!temp_line[i])
		return (NULL);
	while (temp_line[i] && temp_line[i] != '\n')
		i++;
	res_line = malloc (sizeof(char) * i + 2);
	if (!res_line)
		return (NULL);
	i = 0;
	while (temp_line[i] && temp_line[i] != '\n')
	{
		res_line[i] = temp_line[i];
		i++;
	}
	if (temp_line[i] == '\n')
	{
		res_line[i] = temp_line[i];
		i++;
	}
	res_line[i] = '\0';
	return (res_line);
}

static char	*ft_fill_rem_line(char *temp_line)
{
	char	*rem_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (temp_line[i] && temp_line[i] != '\n')
		i++;
	if (!temp_line[i])
	{
		free(temp_line);
		return (NULL);
	}
	rem_line = temp_line;
	temp_line = NULL;
	temp_line = malloc (sizeof(char) * (ft_strlen(rem_line) - i + 1));
	if (!temp_line)
		return (NULL);
	i++;
	while (rem_line[i])
		temp_line[j++] = rem_line[i++];
	free(rem_line);
	temp_line[j] = '\0';
	return (temp_line);
}
