/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:43:05 by kboulkri          #+#    #+#             */
/*   Updated: 2024/01/17 20:20:14 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	redirection(t_data *data, int i)
{
	int	fd;

	if (i == 0)
	{
		fd = open_fd(data, i);
		dup2(fd, 0);
		close(fd);
	}
	if (i == (data->nb_cmb - 1))
	{
		fd = open_fd(data, i);
		dup2(fd, 1);
		close(fd);
	}
	if (i != 0)
	{
		dup2(data->tmp_fd, 0);
		close(data->tmp_fd);
	}
	if (i != data->nb_cmb - 1)
		dup2(data->pipe_fd[1], 1);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
}

void	child_process(t_data *data, int i)
{
	char	**cmd;
	char	*path;

	redirection(data, i);
	cmd = ft_split(data->cmds[i], ' ');
	if (!cmd)
		return (free_tab(cmd), exit(1));
	if (!cmd[0])
		return (ft_printf("\"\" command not found\n"), free_tab(cmd), exit(1));
	path = complete_path(data, cmd[0]);
	if (path)
		execve(path, cmd, data->envp);
	return (free_tab(cmd), free(path), exit(1));
}

void	parent_process(t_data *data, int i)
{
	close(data->pipe_fd[1]);
	if (i != 0)
		close(data->tmp_fd);
	data->tmp_fd = data->pipe_fd[0];
}

int	exec_pipe(t_data *data)
{
	int	i;
	int	status;

	i = -1;
	while (++i < data->nb_cmb)
	{
		if (pipe(data->pipe_fd) == -1)
			return (perror("Error pipe"), 0);
		data->pid[i] = fork();
		if (data->pid[i] == -1)
			return (perror("Error fork"), 0);
		if (data->pid[i] == 0)
			child_process(data, i);
		else
			parent_process(data, i);
	}
	i = 0;
	while (i < data->nb_cmb)
		waitpid(data->pid[i++], &status, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int				i;
	static t_data	data = {0};

	i = 0;
	if (argc != 5)
		return (ft_printf("Error: wrong number of arguments\n"), 1);
	init_data(argc, argv, envp, &data);
	exec_pipe(&data);
	close(data.pipe_fd[0]);
	return (0);
}
