/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:05:58 by slott             #+#    #+#             */
/*   Updated: 2021/10/16 20:25:33 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	x;

	x = 0;
	if (!s)
		return ;
	while (s[x])
	{
		f(x, s + x);
		x++;
	}	
}
