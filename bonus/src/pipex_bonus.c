/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/05/22 23:46:23 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static t_data	*data_init(char **argv);
static void		open_files(t_data *data, int argc, char **argv);
static void		search_paths(t_data *data, char **envp);

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (!((argc >= 5 && ft_strncmp(argv[1], "here_doc", 9)) || argc >= 6))
		error_msg("incorrect nums of arguments", errno);
	if (!envp)
		error_msg("no envp", errno);
	data = data_init(argv);
	open_files(data, argc, argv);
	search_paths(data, envp);
	pipex(data, argc, argv, envp);
	free_data(data, NULL, 0);
	return (0);
}

static t_data	*data_init(char **argv)
{
	t_data	*data;

	data = (t_data *) malloc (sizeof (t_data));
	if (!data)
		error_msg("data malloc error", errno);
	data->here_doc = 0;
	data->cmd_count = 2;
	if (!(ft_strncmp(argv[1], "here_doc", 9)))
	{
		data->here_doc = 1;
		data->cmd_count = 3;
	}
	data->paths = NULL;
	data->cmd = NULL;
	data->c_path = NULL;
	data->pipefd[0] = 0;
	data->pipefd[1] = 0;
	data->in = 0;
	data->out = 0;
	data->pid = 0;
	return (data);
}

static void	open_files(t_data *data, int argc, char **argv)
{
	if (!data->here_doc)
	{
		data->in = open(argv[1], O_RDONLY);
		if (data->in == -1)
			free_data(data, "open_infile", errno);
		data->out = open(argv[argc - 1], O_WRONLY | \
						O_TRUNC | O_CREAT, 0000644);
		if (data->out == -1)
			free_data(data, "open_outfile", errno);
	}
	else
	{
		data->out = open(argv[argc - 1], O_WRONLY | \
						O_APPEND | O_CREAT, 0000644);
		if (data->out == -1)
			free_data(data, "open_outfile", errno);
	}
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
