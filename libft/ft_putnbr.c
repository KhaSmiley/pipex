/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:17:05 by kboulkri          #+#    #+#             */
/*   Updated: 2023/12/28 19:26:18 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_putnbr(int n, int *len)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		*len += pf_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		pf_putnbr(nb / 10, len);
	}
	*len += pf_putchar((nb % 10) + '0');
}

void	pf_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		*len += write(2, "(null)", 6);
		return ;
	}
	while (str[i])
	{
		*len += pf_putchar(str[i]);
		i++;
	}
}

int	pf_putchar(char c)
{
	write(2, &c, 1);
	return (1);
}
