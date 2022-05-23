/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/05/22 23:46:23 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void	here_doc_input(t_data *data, char **argv);

void	here_doc_read(t_data *data, char **argv)
{
	pid_t	pid;

	if (pipe(data->pipefd) == -1)
		free_data(data, "here_doc_pipefd", errno);
	pid = fork();
	if (pid == -1)
		free_data(data, "here_doc_pid", errno);
	if (pid > 0)
	{
		dup2(data->pipefd[0], 0);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		waitpid(pid, NULL, 0);
	}
	else
	{
		dup2(data->pipefd[1], 1);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		here_doc_input(data, argv);
	}
}

static void	here_doc_input(t_data *data, char **argv)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("> ", 2);
		line = get_next_line(0);
		if (!line)
			free_data(data, "here_doc_gnl", errno);
		if (!ft_strncmp(line, argv[2], ft_strlen(argv[2])))
			break ;
		ft_putstr_fd(line, 1);
		free(line);
	}
	free(line);
	get_next_line(-1);
	free_data(data, NULL, 0);
	exit(0);
}
