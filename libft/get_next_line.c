/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:40:55 by kboulkri          #+#    #+#             */
/*   Updated: 2023/12/29 19:18:13 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fix_buffer(char *str)
{
	int		j;
	int		i;
	char	tmp;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i])
	{
		tmp = str[i];
		str[j] = tmp;
		i++;
		j++;
	}
	str[j] = '\0';
}

void	trim_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '\n')
		str[i + 1] = '\0';
}

int	check_nl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			nb_bytes;

	nb_bytes = 1;
	if (fd < 0 || read(fd, buffer, 0))
		return (NULL);
	str = ft_strjoin_gnl(NULL, buffer);
	if (!str)
		return (NULL);
	while (!check_nl(str) && nb_bytes)
	{
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[nb_bytes] = '\0';
		str = ft_strjoin_gnl(str, buffer);
	}
	if ((str[0] == '\0') && (nb_bytes == 0))
		return (free(str), NULL);
	trim_str(str);
	if (nb_bytes)
		fix_buffer(buffer);
	return (str);
}
