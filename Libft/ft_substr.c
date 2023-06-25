/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:40:57 by slott             #+#    #+#             */
/*   Updated: 2021/10/20 13:52:03 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *str, unsigned int x, size_t len)
{
	char	*tab;
	size_t	c;

	c = 0;
	if (!(str))
		return (NULL);
	if (x > ft_strlen(str))
		tab = malloc(1 * sizeof(char));
	else if (len <= ft_strlen(str) - x)
		tab = malloc(len * sizeof(char) + 1);
	else
		tab = malloc(ft_strlen(str) - x * sizeof(char) + 1);
	if (!(tab))
		return (NULL);
	while (c < len && str[x + c] && x < ft_strlen(str))
	{
		tab[c] = str[x + c];
		c++;
	}
	tab[c] = 0;
	return (tab);
}

/*int main()
{
	char *s;
	s = ft_substr("oki", 4, 40);
	printf("%s", s);
}*/
