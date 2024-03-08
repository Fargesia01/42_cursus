/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:36:24 by slott             #+#    #+#             */
/*   Updated: 2021/11/04 12:58:24 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	ft_putnbr_hexa(unsigned int nbr, char *base, int c)
{
	if (nbr >= 16)
	{
		c = ft_putnbr_hexa(nbr / 16, base, c + 1);
		ft_putchar(base[nbr % 16], 0);
	}
	else
		c = ft_putchar(base[nbr], c);
	return (c);
}
