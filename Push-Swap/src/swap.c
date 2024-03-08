/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:13:00 by slott             #+#    #+#             */
/*   Updated: 2022/02/17 14:50:46 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	sa(t_stru *s)
{
	int	tmp;

	tmp = 0;
	tmp = s->stack_a[0];
	s->stack_a[0] = s->stack_a[1];
	s->stack_a[1] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stru *s)
{
	int	tmp;

	tmp = 0;
	tmp = s->stack_b[0];
	s->stack_b[0] = s->stack_b[1];
	s->stack_b[1] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stru *s)
{
	sa(s);
	sb(s);
}
