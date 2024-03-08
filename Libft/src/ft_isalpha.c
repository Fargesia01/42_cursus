/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:39:36 by slott             #+#    #+#             */
/*   Updated: 2021/10/13 16:41:56 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_isalpha(int x)
{
	if (x > 64 && x < 91)
	{
		return (1);
	}
	else if (x > 96 && x < 123)
	{
		return (1);
	}
	return (0);
}
