/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cinq.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:06:55 by slott             #+#    #+#             */
/*   Updated: 2022/02/17 16:10:15 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	cinq(t_stru *s)
{
	int	i;

	i = 0;
	while (s->size_a != s->max_size - 2)
	{
		if (s->stack_a[0] == 0 || s->stack_a[0] == 1)
			pb(s);
		if (s->size_a != s->max_size - 2)
			ra(s);
	}
	if (s->size_a == 3)
		trois(s);
	else
	{
		if (s->stack_a[0] > s->stack_a[1])
			sa(s);
	}
	if (s->stack_b[0] < s->stack_b[1])
		sb(s);
	pa(s);
	pa(s);
}
