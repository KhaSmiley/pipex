/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:54 by kboulkri          #+#    #+#             */
/*   Updated: 2024/01/17 20:21:51 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"
#include <string.h>

void	here_doc(char *pathname, char *limiter)
{
	int		fd;
	char	*line;

	fd = open(pathname, O_RDWR | O_CREAT, 0666);
	if (fd < 0)
		return (perror("Error here_doc : fd"));
	limiter = ft_strjoin(limiter, "\n");
	while (1)
	{
		write(2, "here_doc> ", 10);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	free(limiter);
	close(fd);
}

int	find_here_doc(char *str)
{
	if (ft_strncmp(str, "here_doc", 8) == 0)
		return (0);
	return (1);
}
