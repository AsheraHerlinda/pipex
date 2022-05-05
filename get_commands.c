/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/05/02 22:09:50 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void		search_paths(t_data *data, char **envp);
static int		get_command_1(t_data *data, char *argv);
static int		get_command_2(t_data *data, char *argv);
static void		wrong_command(t_data *data, int f);

void	get_commands(t_data *data, char **argv, char **envp)
{
	search_paths(data, envp);
	get_command_1(data, argv[2]);
	get_command_2(data, argv[3]);
}

static void	search_paths(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp("PATH=", envp[i], 5)) && envp[i] != NULL)
		{
			data->path = ft_strdup(envp[i] + 5);
			data->paths = ft_split(data->path, ':');
			break ;
		}
		i++;
	}
	if (!data->paths || data->paths[0] == NULL)
		free_data(data, "PATHS dosn't exist", 0);
}

static int	get_command_1(t_data *data, char *argv)
{
	int		i;
	char	*tmp;

	i = 0;
	data->cmd_1 = ft_split(argv, ' ');
	if (data->cmd_1[0] == NULL)
		free_data(data, "no command 1", 0);
	while (data->paths[i])
	{
		tmp = ft_strjoin(data->paths[i], "/");
		data->c_path1 = ft_strjoin(tmp, data->cmd_1[0]);
		free(tmp);
		if (access(data->c_path1, X_OK) == 0)
			return (1);
		free(data->c_path1);
		i++;
	}
	data->c_path1 = NULL;
	wrong_command(data, 1);
	return (0);
}

static int	get_command_2(t_data *data, char *argv)
{
	int		i;
	char	*tmp;

	i = 0;
	data->cmd_2 = ft_split(argv, ' ');
	if (data->cmd_2[0] == NULL)
		free_data(data, "no command 2", 0);
	while (data->paths[i])
	{
		tmp = ft_strjoin(data->paths[i], "/");
		data->c_path2 = ft_strjoin(tmp, data->cmd_2[0]);
		free(tmp);
		if (access(data->c_path2, X_OK) == 0)
			return (1);
		free(data->c_path2);
		i++;
	}
	data->c_path2 = NULL;
	wrong_command(data, 2);
	return (0);
}

static void	wrong_command(t_data *data, int f)
{
	char	*tmp;
	char	*msg;

	if (f == 1)
		tmp = ft_strjoin("Command 1 \"", data->cmd_1[0]);
	if (f == 2)
		tmp = ft_strjoin("Command 2 \"", data->cmd_2[0]);
	msg = ft_strjoin(tmp, "\" not found");
	free(tmp);
	ft_putendl_fd(msg, 2);
	free(msg);
	free_data(data, NULL, errno);
}
