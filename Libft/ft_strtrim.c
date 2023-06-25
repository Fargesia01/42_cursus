/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:03:18 by slott             #+#    #+#             */
/*   Updated: 2021/10/23 16:34:50 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(const char *str, const char *list)
{
	char	*tab;
	size_t	c;
	int		d;

	c = 0;
	d = 0;
	if (!(str) || !(list))
		return (NULL);
	while (str[c] && ft_strchr(list, str[c]))
		c++;
	while (str[c] && ft_strchr(list, str[ft_strlen(str) - d - 1]))
		d++;
	if (c == ft_strlen(str) + 1)
		return (malloc(1));
	tab = ft_substr(str, c, ft_strlen(str) - c - d);
	return (tab);
}

/*int main()
{
	char *s;
	char s1[] = "aaaoo";
	char s2[] = "o";
	s = ft_strtrim(s1, s2);
	printf("%s", s);
}*/
