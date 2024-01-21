/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:47:58 by kboulkri          #+#    #+#             */
/*   Updated: 2023/12/26 20:42:31 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char const *s1, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if ((s1[i] != c && s1[i + 1] == '\0') || (s1[i] != c && s1[i + 1] == c))
		{
			count++;
			i++;
		}
		else
		{
			i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	j = 0;
	len = ft_count_word(s, c);
	array = malloc(sizeof(char *) * (len + 1));
	if (!array)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			array[j++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	array[j] = 0;
	return (array);
}
