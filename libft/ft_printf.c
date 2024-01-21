/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 22:22:52 by kboulkri          #+#    #+#             */
/*   Updated: 2023/09/30 21:22:25 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	go_search(va_list args, const char *str, int *len)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (str[++i] == 'c')
				*len += pf_putchar(va_arg(args, int));
			else if (str[i] == 's')
				pf_putstr(va_arg(args, char *), len);
			else if (str[i] == 'd' || str[i] == 'i')
				pf_putnbr(va_arg(args, int), len);
			else if ((str[i] == 'p'))
				pf_convert_base(va_arg(args, unsigned long), str[i], len);
			else if ((str[i] == 'x') || (str[i] == 'X'))
				pf_convert_base(va_arg(args, unsigned int), str[i], len);
			else if (str[i] == 'u')
				pf_convert_base(va_arg(args, unsigned int), str[i], len);
			else if (str[i] == '%')
				*len += pf_putchar('%');
		}
		else
			*len += pf_putchar(str[i]);
	}
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, str);
	go_search(args, str, &len);
	va_end(args);
	return (len);
}
