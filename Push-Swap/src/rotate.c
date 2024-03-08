/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:13:22 by slott             #+#    #+#             */
/*   Updated: 2022/02/17 14:50:20 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	ra(t_stru *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s->stack_a[0];
	while (i < s->size_a)
	{
		s->stack_a[i] = s->stack_a[i + 1];
		i++;
	}
	s->stack_a[i - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stru *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s->stack_b[0];
	while (i < s->size_b)
	{
		s->stack_b[i] = s->stack_b[i + 1];
		i++;
	}
	s->stack_b[i - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stru *s)
{
	ra(s);
	rb(s);
}
