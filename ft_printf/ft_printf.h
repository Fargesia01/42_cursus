/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:52:42 by slott             #+#    #+#             */
/*   Updated: 2021/11/03 15:35:52 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c, int x);
int	ft_putstr(char *str, int c);
int	ft_putnbr(int nbr, int c);
int	ft_putunint(unsigned int n, int c);
int	ft_putnbr_hexa(unsigned int nbr, char *base, int c);
int	ft_putptr(unsigned long ptr, char *base, int c);

#endif
