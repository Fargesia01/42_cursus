/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:11:49 by slott             #+#    #+#             */
/*   Updated: 2021/11/03 17:15:50 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptr(unsigned long ptr, char *base, int c)
{
	if (ptr >= 16)
	{
		c = ft_putptr(ptr / 16, "0123456789abcdef", c + 1);
		ft_putchar(base[ptr % 16], 0);
	}
	else
		c = ft_putchar(base[ptr], c);
	return (c);
}
