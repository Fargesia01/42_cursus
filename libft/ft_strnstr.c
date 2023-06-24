/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:26:05 by slott             #+#    #+#             */
/*   Updated: 2021/10/23 18:37:31 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int		ft_strcmp(char *s1, char *s2);
size_t			ft_leng(char *str);

char	*ft_strnstr(const char *hay, const char *nee, size_t size)
{
	size_t	c;
	char	*h;
	char	*n;

	h = (char *) hay;
	n = (char *) nee;
	c = 0;
	if (nee[0] == 0)
		return (h);
	while (h[c] && c < size)
	{
		if (h[c] == n[0])
		{	
			if (ft_strcmp(&h[c], n) && ft_leng(n) < size - c + 1)
				return (&h[c]);
		}
		c++;
	}
	return (NULL);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	c;

	c = 0;
	while (s1[c] && s2[c])
	{
		if (s1[c] != s2[c])
			return (0);
		c++;
	}
	return (1);
}

size_t	ft_leng(char *str)
{
	size_t	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

/*int main()
{
	char s1[30] = "toto";
	char s2[30] = "";
	printf("%s", ft_strnstr(s1, s2, 0));	
}*/
