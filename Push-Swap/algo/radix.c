/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:50:05 by slott             #+#    #+#             */
/*   Updated: 2022/03/01 14:17:26 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	radix(t_stru *s)
{
	int	max_it;
	int	i;
	int	j;

	max_it = 0;
	i = 0;
	while ((s->size_a - 1) >> max_it != 0)
		max_it++;
	while (i < max_it)
	{
		j = 0;
		while (j++ < s->max_size)
		{
			if (check_sorted(s))
				empty_b(s);
			if (((s->stack_a[0] >> i) & 1) == 1)
			{
				ra(s);
			}
			else
				pb(s);
		}
		empty_b(s);
		i++;
	}
}

void	empty_b(t_stru *s)
{
	int	size;
	int	i;

	size = s->size_b;
	i = 0;
	while (i < size)
	{
		pa(s);
		i++;
	}
}

void	simplify(t_stru *s)
{
	int	i;
	int	i2;
	int	val;

	i = 0;
	while (i < s->size_a)
	{
		val = 0;
		i2 = 0;
		while (i2 < s->size_a)
		{
			if (s->tmp[i2] < s->tmp[i])
				val++;
			i2++;
		}
		s->stack_a[i] = val;
		i++;
	}
}
