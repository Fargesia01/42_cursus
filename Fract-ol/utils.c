/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:41:19 by slott             #+#    #+#             */
/*   Updated: 2022/02/16 10:57:53 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fract_ol.h"

char	*ft_cpy(char *src)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(ft_strlen(src) * sizeof(char) + 1);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	c;

	c = 0;
	while (s1[c] == s2[c] && s1[c] && s2[c])
		c++;
	return ((unsigned char)s1[c] - (unsigned char) s2[c]);
}
