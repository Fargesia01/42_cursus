/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:30:02 by slott             #+#    #+#             */
/*   Updated: 2021/10/13 16:43:49 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_isprint(int x)
{
	if (x > 31 && x < 127)
		return (1);
	return (0);
}
