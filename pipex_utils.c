/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/05/04 22:12:42 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_1(t_data *data, char **envp);
static void	child_2(t_data *data, char **envp);

void	pipex(t_data *data, char **envp)
{
	if (pipe(data->pipefd) == -1)
		free_data(data, "pipe", errno);
	data->pid_1 = fork();
	if (data->pid_1 == -1)
		free_data(data, "fork 1", errno);
	if (data->pid_1 == 0)
		child_1(data, envp);
	data->pid_2 = fork();
	if (data->pid_2 == -1)
		free_data(data, "fork 2", errno);
	if (data->pid_2 == 0)
		child_2(data, envp);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
}

static void	child_1(t_data *data, char **envp)
{
	if (dup2(data->pipefd[1], 1) == -1)
		free_data(data, "dup_2 pipefd[1]", errno);
	close(data->pipefd[0]);
	if (dup2(data->in, 0) == -1)
		free_data(data, "dup_2 infile", errno);
	execve(data->c_path1, data->cmd_1, envp);
}

static void	child_2(t_data *data, char **envp)
{
	if (dup2(data->pipefd[0], 0) == -1)
		free_data(data, "dup_2 pipefd[0]", errno);
	close(data->pipefd[1]);
	if (dup2(data->out, 1) == -1)
		free_data(data, "dup_2 outfile", errno);
	execve(data->c_path2, data->cmd_2, envp);
}
