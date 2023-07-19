/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:21:53 by slott             #+#    #+#             */
/*   Updated: 2022/02/17 14:49:51 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	pa(t_stru *s)
{
	int	i;

	i = 0;
	if (s->size_b == 0)
		return ;
	while (i < s->size_a)
		i++;
	while (i > 0)
	{
		s->stack_a[i] = s->stack_a[i - 1];
		i--;
	}
	s->stack_a[0] = s->stack_b[0];
	while (i < s->size_b)
	{
		s->stack_b[i] = s->stack_b[i + 1];
		i++;
	}
	s->stack_b[i] = 0;
	s->size_b--;
	s->size_a++;
	write(1, "pa\n", 3);
}

void	pb(t_stru *s)
{
	int	i;

	i = 0;
	if (s->size_a == 0)
		return ;
	while (i < s->size_b)
		i++;
	while (i > 0)
	{
		s->stack_b[i] = s->stack_b[i - 1];
		i--;
	}
	s->stack_b[0] = s->stack_a[0];
	while (i < s->size_a)
	{
		s->stack_a[i] = s->stack_a[i + 1];
		i++;
	}
	s->stack_a[i] = 0;
	s->size_b++;
	s->size_a--;
	write(1, "pb\n", 3);
}
