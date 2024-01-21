/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:53:35 by kboulkri          #+#    #+#             */
/*   Updated: 2023/10/20 17:54:19 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		s_len;
	char	*str;

	if (!s1 && s2)
		return (ft_strdup(s2));
	s_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * ((s_len + 1)));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, (ft_strlen(s1) + 1));
	ft_strlcat(str, (char *)s2, s_len + 1);
	free(s1);
	return (str);
}
