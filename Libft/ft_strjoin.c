/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:48:52 by slott             #+#    #+#             */
/*   Updated: 2021/10/16 17:18:50 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *pre, const char *su)
{
	char	*tab;
	int		c;
	int		c2;

	c2 = 0;
	c = 0;
	if (!(pre) || !(su))
		return (NULL);
	tab = malloc((ft_strlen(pre) + ft_strlen(su)) * sizeof(char) + 1);
	if (!(tab))
		return (NULL);
	while (pre[c])
	{
		tab[c] = pre[c];
		c++;
	}
	while (su[c2])
	{
		tab[c] = su[c2];
		c++;
		c2++;
	}
	tab[c] = 0;
	return (tab);
}

/*int main()
{
	char *s;

	s = ft_strjoin("oki", "doki");
	printf("%s", s);
}*/
