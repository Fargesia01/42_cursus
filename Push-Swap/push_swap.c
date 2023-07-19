/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:28:12 by slott             #+#    #+#             */
/*   Updated: 2022/03/10 16:41:39 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stru	s;
	char	**tab;

	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		init_stacks(&s, ft_tablen(tab), tab);
	}
	else
		init_stacks(&s, argc - 1, &argv[1]);
	if (!check_double(&s))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	simplify(&s);
	launch_algo(&s);
}

void	launch_algo(t_stru *s)
{
	if (check_sorted(s))
		return ;
	if (s->max_size == 0)
		return ;
	if (s->max_size == 1)
		return ;
	else if (s->max_size == 2)
	{
		if (s->stack_a[0] > s->stack_a[1])
			sa(s);
	}
	else if (s->max_size == 3)
		trois(s);
	else if (s->max_size <= 5)
		cinq(s);
	else
		radix(s);
}

void	init_stacks(t_stru *s, int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
		i++;
	s->stack_a = malloc(i * sizeof(int) + 1);
	s->stack_b = malloc(i * sizeof(int) + 1);
	s->tmp = malloc(i * sizeof(int) + 1);
	s->size_a = i;
	s->size_b = 0;
	s->max_size = s->size_a;
	i = 0;
	while (i < argc)
	{
		s->tmp[i] = ft_atoi(argv[i]);
		i++;
	}
}

void	print_stack(t_stru *s)
{
	int	i;

	i = 0;
	while (i < s->size_a)
	{
		printf("a : %d\n", s->stack_a[i]);
		i++;
	}
	i = 0;
	while (i < s->size_b)
	{
		printf("b : %d\n", s->stack_b[i]);
		i++;
	}
}

void	print_tab(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		printf("%d : %s\n", i, argv[i]);
		i++;
	}
}
