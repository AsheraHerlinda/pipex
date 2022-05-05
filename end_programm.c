/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_programm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/04/19 22:37:46 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_arr(char **arr);

void	error_msg(char *errmsg, int errnum)
{
	if (errmsg != 0 || errnum != 0)
		ft_putendl_fd("Error", 2);
	if (errmsg != 0)
		ft_putstr_fd(errmsg, 2);
	if (errmsg != 0 && errnum != 0)
		ft_putstr_fd(": ", 2);
	if (errnum != 0)
		ft_putstr_fd(strerror(errnum), 2);
	if (errmsg != 0 || errnum != 0)
	{
		ft_putendl_fd("", 2);
		exit(1);
	}
	exit(0);
}

void	free_data(t_data *data, char *errmsg, int errnum)
{
	if (data->path != NULL)
		free(data->path);
	if (data->c_path1 != NULL)
		free(data->c_path1);
	if (data->c_path2 != NULL)
		free(data->c_path2);
	if (data->cmd_1 != NULL)
		free_arr(data->cmd_1);
	if (data->cmd_2 != NULL)
		free_arr(data->cmd_2);
	if (data->paths)
		free_arr(data->paths);
	free(data);
	error_msg(errmsg, errnum);
}

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
