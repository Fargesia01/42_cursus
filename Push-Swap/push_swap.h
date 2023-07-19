/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:24:07 by slott             #+#    #+#             */
/*   Updated: 2022/03/22 15:33:37 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pushswap
{
	int	*stack_a;
	int	*stack_b;
	int	*tmp;
	int	size_a;
	int	size_b;
	int	max_size;
}	t_stru;

typedef struct s_atoi
{
	int		c;
	long	r;
	int		m;
}	t_atoi;

void	init_stacks(t_stru *s, int argc, char *argv[]);
void	sa(t_stru *s);
void	sb(t_stru *s);
void	ss(t_stru *s);
void	pa(t_stru *s);
void	pb(t_stru *s);
void	ra(t_stru *s);
void	rb(t_stru *s);
void	rr(t_stru *s);
void	rra(t_stru *s);
void	rrb(t_stru *s);
void	rrr(t_stru *s);
void	radix(t_stru *s);
void	trois(t_stru *s);
void	cinq(t_stru *s);
void	empty_b(t_stru *s);
void	launch_algo(t_stru *s);
void	simplify(t_stru *s);
void	print_stack(t_stru *s);
int		check(char *argv[], t_stru *s);
int		check_sorted(t_stru *s);
int		check_double(t_stru *s);
long	ft_atoi(const char *str);
void	gratte_ligne(t_atoi *s);
int		ft_tablen(char **tab);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(const char *s, char ch);
void	print_tab(char *argv[]);

#endif
