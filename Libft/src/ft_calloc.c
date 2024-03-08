/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:24:01 by slott             #+#    #+#             */
/*   Updated: 2021/11/04 14:17:25 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t c, size_t size)
{
	char	*tab;

	tab = malloc(c * size * sizeof(char));
	if (!(tab))
		return (NULL);
	ft_bzero(tab, c * size * sizeof(char));
	return (tab);
}

/*int main()
{
	
}*/
