/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:10:37 by slott             #+#    #+#             */
/*   Updated: 2021/11/03 14:03:53 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int nbr, int c)
{
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648", c));
	else if (nbr < 0)
	{
		ft_putchar('-', c);
		c = ft_putnbr(-nbr, c + 1);
	}
	else if (nbr >= 10)
	{
		c = ft_putnbr(nbr / 10, c + 1);
		ft_putchar(nbr % 10 + '0', 0);
	}
	else
		c = ft_putchar(nbr + '0', c);
	return (c);
}
