/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:27:03 by slott             #+#    #+#             */
/*   Updated: 2022/02/12 13:56:21 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	rra(t_stru *s)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < s->size_a)
		i++;
	i--;
	tmp = s->stack_a[i];
	while (i > 0)
	{
		s->stack_a[i] = s->stack_a[i - 1];
		i--;
	}
	s->stack_a[i] = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stru *s)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < s->size_b)
		i++;
	i--;
	tmp = s->stack_b[i];
	while (i > 0)
	{
		s->stack_b[i] = s->stack_b[i - 1];
		i--;
	}
	s->stack_b[i] = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stru *s)
{
	rra(s);
	rrb(s);
}
