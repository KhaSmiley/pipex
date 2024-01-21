/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:12:15 by kboulkri          #+#    #+#             */
/*   Updated: 2023/05/21 18:47:50 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s_len;
	char	*str;

	if (!s1)
		return (NULL);
	s_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * ((s_len + 1)));
	if (!str)
	{
		return (NULL);
	}
	ft_strlcpy(str, (char *)s1, (ft_strlen(s1) + 1));
	ft_strlcat(str, (char *)s2, s_len + 1);
	return (str);
}
