/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:16:03 by slott             #+#    #+#             */
/*   Updated: 2021/10/19 15:43:13 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		x;
	char	*s;

	x = 0;
	s = (char *) str;
	while (s[x])
	{
		if (s[x] == (char)c)
			return (&s[x]);
		x++;
	}
	if (c == '\0')
		return (&s[x]);
	return (0);
}
