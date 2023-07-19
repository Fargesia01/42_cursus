/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trois.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:48:59 by slott             #+#    #+#             */
/*   Updated: 2022/02/17 14:06:45 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	trois(t_stru *s)
{
	if (s->stack_a[1] == 0 && s->stack_a[2] == 2)
		sa(s);
	else if (s->stack_a[0] == 0 && s->stack_a[1] == 2)
	{
		rra(s);
		sa(s);
	}
	else if (s->stack_a[0] == 1 && s->stack_a[1] == 2)
		rra(s);
	else if (s->stack_a[0] == 2 && s->stack_a[1] == 0)
		ra(s);
	else
	{
		ra(s);
		sa(s);
	}
}
