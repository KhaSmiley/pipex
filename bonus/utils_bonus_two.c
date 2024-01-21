/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:49:40 by kboulkri          #+#    #+#             */
/*   Updated: 2024/01/17 20:22:02 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	open_fd(t_data *data, int i)
{
	int	fd;

	fd = -1;
	if (i == 0)
	{
		if (ft_access(data->path_i) == 0)
			fd = open(data->path_i, O_RDONLY);
		if (fd < 0)
			return (close(data->pipe_fd[0]), close(data->pipe_fd[1]),
				perror("Error"), exit(1), fd);
	}
	if (i == (data->nb_cmb - 1))
	{
		if (data->here_doc)
			fd = open(data->path_o, O_WRONLY | O_CREAT | O_APPEND, 0666);
		else
			fd = open(data->path_o, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd < 0)
			return (close(data->tmp_fd), close(data->pipe_fd[1]),
				perror("Error"), exit(1), fd);
	}
	return (fd);
}

int	ft_strlen_from(int i, char *str)
{
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_access(char *cmd)
{
	if (ft_access(cmd) == 1)
		return (cmd);
	else
		exit(ft_printf("%s: command not found\n", cmd));
}
