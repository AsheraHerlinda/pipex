/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/05/22 23:47:15 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_data
{
	char	*path;
	char	**paths;
	char	**cmd;
	char	*c_path;
	int		pipefd[2];
	int		in;
	int		out;
	pid_t	pid;
	int		cmd_count;
}	t_data;

int		get_command(t_data *data, char *argv);
void	pipex(t_data *data, int argc, char **argv, char **envp);

void	error_msg(char *errmsg, int errnum);
void	free_data(t_data *data, char *errmsg, int errnum);

#endif
