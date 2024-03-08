/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:01:11 by slott             #+#    #+#             */
/*   Updated: 2021/10/22 18:14:17 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	m;
	int	r;

	m = 0;
	c = 0;
	r = 0;
	while ((str[c] > 8 && str[c] < 14) || str[c] == 32)
		c++;
	if (str[c] == 45)
	{
		m++;
		c++;
	}
	else if (str[c] == 43)
		c++;
	while (str[c] > 47 && str[c] < 58)
	{
		r = r * 10 + (str[c] - '0');
		c++;
	}
	if (m == 1)
		r = r * -1;
	return (r);
}

/*int main()
{
	printf("%d", atoi(""));
}*/
