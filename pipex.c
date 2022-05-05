/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/04/19 22:37:46 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_data	*data_init(void);
static void		open_files(t_data *data, char **argv);
static void		close_files(t_data *data);

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	(void) argv;
	if (argc != 5)
		error_msg("incorrect nums of arguments", errno);
	if (!envp)
		error_msg("no envp", errno);
	data = data_init();
	open_files(data, argv);
	get_commands(data, argv, envp);
	pipex(data, envp);
	waitpid(data->pid_1, NULL, 0);
	waitpid(data->pid_2, NULL, 0);
	close_files(data);
	free_data(data, NULL, 0);
	return (0);
}

static t_data	*data_init(void)
{
	t_data	*data;

	data = (t_data *) malloc (sizeof (t_data));
	if (!data)
		error_msg("data malloc error", errno);
	data->path = NULL;
	data->paths = NULL;
	data->cmd_1 = NULL;
	data->cmd_2 = NULL;
	data->c_path1 = NULL;
	data->c_path2 = NULL;
	data->pipefd[0] = 0;
	data->pipefd[1] = 0;
	data->in = 0;
	data->out = 0;
	data->pid_1 = 0;
	data->pid_2 = 0;
	return (data);
}

static void	open_files(t_data *data, char **argv)
{
	data->in = open(argv[1], O_RDONLY);
	if (data->in == -1)
		free_data(data, "open_infile", errno);
	data->out = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0000644);
	if (data->out == -1)
		free_data(data, "open_outfile", errno);
}

static void	close_files(t_data *data)
{
	close(data->in);
	close(data->out);
}
