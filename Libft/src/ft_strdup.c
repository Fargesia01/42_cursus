/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:08:48 by slott             #+#    #+#             */
/*   Updated: 2021/10/14 16:08:27 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*tab;
	int		c;

	c = 0;
	tab = malloc(ft_strlen(str));
	if (!(tab))
		return (NULL);
	while (str[c])
	{
		tab[c] = str[c];
		c++;
	}
	tab[c] = '\0';
	return (tab);
}

/*int main()
{
	char ok[5];

	ok = 
}*/
