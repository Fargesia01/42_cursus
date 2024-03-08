/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:48:51 by slott             #+#    #+#             */
/*   Updated: 2022/03/10 15:01:48 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

long	ft_atoi(const char *str)
{
	t_atoi	s;

	s.r = 0;
	s.c = 0;
	s.m = 0;
	if (str[s.c] == 45)
	{
		s.m++;
		s.c++;
	}
	while (str[s.c])
	{
		if (str[s.c] < 48 || str[s.c] > 57)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		s.r = s.r * 10 + (str[s.c] - '0');
		s.c++;
	}
	gratte_ligne(&s);
	return (s.r);
}

void	gratte_ligne(t_atoi *s)
{
	if (s->m == 1)
		s->r = s->r * -1;
	if (s->r > 2147483647 || s->r < -2147483648)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}

int	check_sorted(t_stru *s)
{
	int	i;

	i = 0;
	while (i < s->size_a)
	{
		if (s->stack_a[i + 1] != s->stack_a[i] + 1)
			break ;
		i++;
	}
	if (i == s->size_a - 1)
		return (1);
	else
		return (0);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	x;

	x = 0;
	if (size > 0)
	{
		while (x < size - 1 && src[x])
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = 0;
	}
	x = 0;
	while (src[x])
		x++;
	return (x);
}
