/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/05/22 23:46:23 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void		wrong_command(t_data *data);

int	get_command(t_data *data, char *argv)
{
	int		i;
	char	*tmp;

	i = 0;
	data->cmd = ft_split(argv, ' ');
	if (data->cmd[0] == NULL)
		free_data(data, "no command", 0);
	while (data->paths[i])
	{
		if (data->cmd[0][0] == '~' || \
			data->cmd[0][0] == '.' || data->cmd[0][0] == '/')
			data->c_path = ft_strdup(data->cmd[0]);
		else
		{
			tmp = ft_strjoin(data->paths[i], "/");
			data->c_path = ft_strjoin(tmp, data->cmd[0]);
			free(tmp);
		}	
		if (access(data->c_path, X_OK) == 0)
			return (1);
		free(data->c_path);
		i++;
	}
	wrong_command(data);
	return (0);
}

static void	wrong_command(t_data *data)
{
	char	*tmp;
	char	*msg;

	data->c_path = NULL;
	tmp = ft_strjoin("Command \"", data->cmd[0]);
	msg = ft_strjoin(tmp, "\" not found");
	free(tmp);
	ft_putendl_fd(msg, 2);
	free(msg);
	free_data(data, NULL, errno);
}
