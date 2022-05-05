/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/04/17 22:30:56 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_data
{
	char	*path;
	char	**paths;
	char	**cmd_1;
	char	**cmd_2;
	char	*c_path1;
	char	*c_path2;
	int		pipefd[2];
	int		in;
	int		out;
	pid_t	pid_1;
	pid_t	pid_2;
}	t_data;

void	get_commands(t_data *data, char **argv, char **envp);
void	pipex(t_data *data, char **envp);

void	error_msg(char *errmsg, int errnum);
void	free_data(t_data *data, char *errmsg, int errnum);

#endif
