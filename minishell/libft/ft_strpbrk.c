/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:32:48 by slott             #+#    #+#             */
/*   Updated: 2022/05/25 14:33:10 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	ft_strpbrk(const char *str, const char *charset)
{
	int	i;
	int	i2;

	i = 0;
	while (str[i])
	{
		i2 = 0;
		while (charset[i2])
		{
			if (charset[i2] == str[i])
				return (str[i]);
			i2++;
		}
		i++;
	}
	return (0);
}
