/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:04:05 by slott             #+#    #+#             */
/*   Updated: 2022/02/17 13:20:57 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_double(t_stru *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->max_size)
	{
		j = i + 1;
		while (j < s->max_size)
		{
			if (s->tmp[i] == s->tmp[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
