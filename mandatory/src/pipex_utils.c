/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/05/22 19:50:07 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	open_pipe(t_data *data, char *argv, char **envp);
static void	apply_command(t_data *data, char *argv, char **envp);

void	pipex(t_data *data, int argc, char **argv, char **envp)
{
	int	pid_stat;

	dup2(data->in, 0);
	close(data->in);
	while (data->cmd_count < argc - 2)
	{
		open_pipe(data, argv[data->cmd_count], envp);
		++data->cmd_count;
	}
	dup2(data->out, 1);
	close(data->out);
	data->pid = fork();
	if (data->pid == -1)
		free_data(data, "fork()", errno);
	if (data->pid == 0)
		apply_command(data, argv[argc - 2], envp);
	waitpid(data->pid, &pid_stat, WNOHANG);
	if (WEXITSTATUS(pid_stat) == EXIT_FAILURE)
		free_data(data, "Error_PID", errno);
}

static void	open_pipe(t_data *data, char *argv, char **envp)
{
	int	pid_stat;

	if (pipe(data->pipefd) == -1)
		free_data(data, "pipe", errno);
	data->pid = fork();
	if (data->pid == -1)
		free_data(data, "fork()", errno);
	if (data->pid == 0)
	{
		close(data->pipefd[0]);
		if (dup2(data->pipefd[1], 1) == -1)
			free_data(data, "dup_2 pipefd[1]", errno);
		close(data->pipefd[1]);
		apply_command(data, argv, envp);
	}
	else
	{
		close(data->pipefd[1]);
		if (dup2(data->pipefd[0], 0) == -1)
			free_data(data, "dup_2 pipefd[0]", errno);
		close(data->pipefd[0]);
		waitpid(data->pid, &pid_stat, WNOHANG);
		if (WEXITSTATUS(pid_stat) == EXIT_FAILURE)
			free_data(data, "Error_PID", errno);
	}
}

static void	apply_command(t_data *data, char *argv, char **envp)
{
	get_command(data, argv);
	execve(data->c_path, data->cmd, envp);
	free_data(data, "execve_error", errno);
}
