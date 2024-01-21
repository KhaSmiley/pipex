/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:43:40 by kboulkri          #+#    #+#             */
/*   Updated: 2024/01/17 20:20:11 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
		return (ft_printf("%s: command not found\n", cmd), NULL);
}

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
		fd = open(data->path_o, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd < 0)
			return (close(data->tmp_fd), close(data->pipe_fd[1]),
				perror("Error"), exit(1), fd);
	}
	return (fd);
}
