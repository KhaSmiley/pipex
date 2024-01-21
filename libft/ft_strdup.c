/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:26:55 by kboulkri          #+#    #+#             */
/*   Updated: 2023/05/17 19:35:28 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*copy;

	i = ft_strlen(s);
	copy = (char *)malloc(i + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, (i + 1));
	return (copy);
}
